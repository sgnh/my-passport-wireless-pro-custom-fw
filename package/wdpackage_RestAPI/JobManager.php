<?php

/**
 * \file jobs/JobManager.php
 * \author WDMV - Mountain View - Software Engineering
 * \copyright Copyright (c) 2014, Western Digital Corp. All rights reserved.
 */


namespace Jobs;
use Jobs\Model;
use Jobs\Common;
use PDO;

require_once JOBS_ROOT.'/includes/jobsconstants.inc';

class JobManager {
    private $url_path;
    private $query_string;
    private $http_method_type;
    private $component_name;
    private $descriptor_type;
    private $job_db;
    private $taskManager;
    static protected $self;

    private function __construct() {
        $this->job_db = new Model\JobDB();
        $this->taskManager = new Common\TaskManager();
    }

    public static function getInstance() {

        if (!self::$self instanceof JobManager) {
            self::$self = new self();
        }
        return self::$self;
    }

    public function initManager($url_path=null, $query_string=null, $http_method_type=null, $component_name=null, $descriptor_type=null) {
        $this->url_path = $url_path;
        $this->query_string = $query_string;
        $this->http_method_type = $http_method_type;
        $this->component_name = $component_name;
        $this->descriptor_type = $descriptor_type;
    }

    /**
     * Create a job record
     *
     * @param type $comments
     * @param type $username
     * @param type $device_user_id
     * @return null
     * @throws \Core\Rest\Exception
     */
    public function create($comments=null, $username=null, $device_user_id=null) {
        $retVal=$conf=null;
		
        $descriptor = $this->taskManager->generateDescriptor($this->url_path, $this->query_string);
        if(empty($descriptor)) {
            throw new \Core\Rest\Exception('JOBS_CREATE_FAILED', 500, null, $this->component_name);
        }
        try {
            $dbh = $this->job_db->getDB(); // db handle
            $dbh->beginTransaction();
            $jobId = $this->job_db->createJob($descriptor['jobtype_id'],$comments, $username, $device_user_id); // job record
            
            if(isset($jobId) && $jobId > 0) {
            	\Core\Logger::getInstance()->debug("New New jobId: $jobId");
            	exec_runtime("sudo /usr/local/sbin/storage_transfer_LED_status.sh starting", $conf, $retVal);
            }
            $descriptor['details']['job_id'] = $jobId;
            $this->job_db->createTaskDetails($jobId, $this->component_name, $descriptor['descriptor_type'],
                                            json_encode($descriptor['details']),
                                            $this->http_method_type, json_encode($this->query_string));
            $dbh->commit();
            return $jobId;
        }
        catch (\PDOException $pdoe) {
            $dbh->rollBack();
            \Core\Logger::getInstance()->err("JobManager create() PDO Exception: " . $pdoe->getMessage());
            return null;
        }
        catch (Exception $e) {
            $dbh->rollBack();
            \Core\Logger::getInstance()->err("JobManager create() Exception: " . $e->getMessage());
            return null;
        }
    }

    /**
     * Execute given job now
     * @param type $jobID
     */
    public function execute($jobId) {
        $this->taskManager->executeTask($jobId, $this->getInstance());
    }

    /**
     * Function to support Jobs put API
     * @param type $jobID
     * @param type $status
     * @param type $async_comment
     */
    public function put($jobID, $status, $async_comment) {
        $job_details = $this->getDetailsById($jobID);
        if(!$this->checkUserAccessPermission($job_details[0]['username'])) {
            return 'USER_NOT_AUTHORIZED';
        }
        if(!isset($job_details) || empty($job_details)) {
            return 'JOBS_NOT_FOUND'; // no record found
        }
        // A Job can only be canceled if it's in either Waiting or
        // Running state...
        if($status &&
                ($job_details[0]['status'] != 'waiting' && $job_details[0]['status'] != 'running')) {
                //\Core\Logger::getInstance()->err("JobManager::put() - JobId=". $jobID . '. Status='. $job_details[0]['status']);
                return 'JOBS_PUT_NOT_WAITING_OR_RUNNING';
        }

        if($status && $async_comment) {
            $this->job_db->updateJobStateCanceledWithComments($jobID, $async_comment);
        }
        else if($status) {
            $this->job_db->updateJobStateCompleted($jobID, JOBSTATE_CANCELLED, time());
        }
        else {
            $this->job_db->updateComments($jobID, $async_comment);
        }
        return 'OK';
    }

    /*
     * Checks if the Job state is Cancled
     *
     * @param type $jobId
     */
    public function isJobCanceled($jobId){
        $job_details = $this->getDetailsById($jobId);

        // A running Job Not found? Something went totally wrong!!
        if(!isset($job_details) || empty($job_details)) {
            return true; //'JOBS_NOT_FOUND';
        }

        //\Core\Logger::getInstance()->err("JobManager::isJobCanceled() - JobId=". $jobId . '. Status='. $job_details[0]['status']);
        if($job_details[0]['status'] == 'canceled') {
            return true;
        }
        else{
            return false;
        }
    }

        /**
     * Function to support Jobs delete api
     * @param type $jobID
     * @return string
     */
    public function delete($jobID) {
        $job_details = $this->getDetailsById($jobID);
        if(!$this->checkUserAccessPermission($job_details[0]['username'])) {
            return 'USER_NOT_AUTHORIZED';
        }
        if(!isset($job_details) || empty($job_details)) {
            return 'JOBS_NOT_FOUND'; // no record found
        }
        if($job_details[0]['status'] == 'running') {
            return 'JOBS_DELETE_JOB_RUNNING';
        }
        $this->job_db->deleteJob($jobID);
        return 'OK';
    }


    /**
     * Get all job details (from Jobs and TaskDetails)
     * @param type $jobID
     */
    public function getDetailsById($jobID, $filter=true) {
        $job_details = $this->job_db->getJobById($jobID);
        if($filter) {
            return $this->filterJobDetails($job_details);
        }
        else {
            return $job_details;
        }
    }

    public function getDetails($jobID, $status, $username, $device_user_id,
                               $create_time, $start_time, $complete_time) {
        if(isset($jobID)) {
            $job_details = $this->getDetailsById($jobID);
            if($this->checkUserAccessPermission($job_details[0]['username'])) {
                return $job_details;
            }
            else {
                return 'USER_NOT_AUTHORIZED';
            }
        }
        else {
            $job_details = $this->job_db->getJobDetails($status, $username, $device_user_id,
                                                        $create_time, $start_time, $complete_time);
            return $this->filterJobDetails($job_details);
        }
    }

    public function getAllJobs() {
        $job_details = $this->job_db->getAllJobs();
        return $this->filterJobDetails($job_details);
    }

    /*
     * Updates the Job state as Running with the current timestamp
     *
     * @param $jobId - to be updated
     */
    public function updateJobStateStarted($jobID) {
        $this->job_db->updateJobStateStarted($jobID, JOBSTATE_RUNNING, time());
    }

    /*
     * Updates the Job state as Failed with the provided error code & message
     *
     * @param $jobId - to be updated
     * @param $error_code - application specific error code
     * @param $error_message - application specific error message
     *
     */
    public function updateJobStateError($jobId, $error_code, $error_message) {
        $this->job_db->updateJobStateError($jobId, JOBSTATE_FAILED, $error_code, $error_message);
    }

    /*
     * Updates the Job state as Completed with the current timestamp
     *
     * @param $jobId - to be updated
     */

    public function updateJobStateCompleted($jobID) {
        $this->job_db->updateJobStateCompleted($jobID, JOBSTATE_COMPLETED, time());
    }

    /*
     * Updates the Job state as Canceleds with the current timestamp
     *
     * @param $jobId - to be updated
     */
    public function updateJobStateCanceled($jobID) {
        $this->job_db->updateJobStateCompleted($jobID, JOBSTATE_CANCELLED, time());
    }

    /**
     * Gets the integer representation of the Job State as stored in the Db.
     *
     * @param type $jobId
     * @return type integer
     */
    public function getJobStateId($jobId) {
        $job_record = $this->job_db->getJob($jobId);
        return $job_record[0]['jobstate_id'];
    }

    /**
     * Gets the string representation of the Job State as displayed to User
     *
     * @param type  $jobId
     * @return type string
     */
    public function getJobStateText($jobId) {
        $job_record = $this->job_db->getJob($jobId);
        return $job_record[0]['description'];
    }

    /**
     * Fetchs the next Waiting Job for execution
     *
     * @return type mixed
     */
    public function getNextJobToProcess() {
        $next_waiting_job = $this->job_db->getNextJob();
        if(is_array($next_waiting_job) && !empty($next_waiting_job)) {
            return $next_waiting_job[0];
        }
        else {
            return null;
        }
    }

    /*
     * Updates the Job with the provided Work Total.
     * The total work to be accomplished to mark the Job as completed.
     *
     * @param $jobId - to be updated
     */
    public function setWorkTotal($jobId, $work_total) {
        $this->job_db->setWorkTotal($jobId, $work_total);
    }

    /*
     * Updates the Job with the provided Work Complete.
     * The work that's accomplished so far. May or may not be the total work.
     *
     * @param $jobId - to be updated
     */
    public function setWorkComplete($jobId, $work_complete) {
        $this->job_db->setWorkComplete($jobId, $work_complete);
    }

    /*
     * Gets total work to be accomplished by the given Job Id.
     *
     * @param $jobId - to be updated
     */
    public function getWorkTotal($jobId) {
        return $this->job_db->getWorkTotal($jobId);
    }

    /*
     * Gets work completed thus far by the given Job Id.
     *
     * @param $jobId - to be updated
     */
    public function getWorkComplete($jobId) {
        $this->job_db->getWorkComplete($jobId);
    }

    /**
     * Retrieves all Waiting Jobs to be processed
     *
     * @return type collection/array of Jobs
     */
    public function getAllWaitingJobs() {
        return $this->job_db->getAllJobsByState(JOBSTATE_WAITING);
    }

    /**
     * Check if Jobmonitor is already running.
     *
     * Note: This is an Apache specific implementation and is not currently used. But
     * keeping the implementation for future consideration/use.
     *
     * @return type true/false
     */
    private function isJobmonitorActive() {
        // check apache status
        $ch = curl_init('http://localhost/server-status');
        curl_setopt($ch, CURLOPT_VERBOSE, false);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);
        $content = curl_exec($ch);
        curl_close($ch);
        preg_match_all("/jobmonitor.php/", $content, $matches);
        return count($matches[0])>1?true:false;
    }

    /*
     * Private method to filter the Job details as needed to be presented
     * or returned to the client/end-user.
     *
     * @param $job_details - Jobs as an array.
     */
    private function filterJobDetails($job_details) {
        $returnJobs = array();
        $sessionUserId = getSessionUserId();
        $admin = isAdmin($sessionUserId)?true:false;
        foreach($job_details as $key => $val) {
           if($admin || $val['username']==$sessionUserId) {
               $descriptor = array_merge(['component'=>$val['component']], \json_decode($val['descriptor'], true));
                unset($descriptor['job_id']);
                // job attributes that we are interested in
                $returnJobs[] = array(
                    'job_id'=>$val['job_id'],'status'=>$val['jobstate'],
                    'username'=>$val['username'],/*'device_user_id'=>$val['device_user_id'], */
                    'comment' => $val['description'],
                    'task_details'=>$descriptor, // Request/Query Params as an array
                    'create_time'=>$val['create_time'],'start_time'=>$val['start_time'],
                    'complete_time'=>$val['complete_time'],'total_work'=>$val['work_total'],
                    'complete_work'=>$val['work_complete'],'error_code'=>$val['error_code'],
                    'error_message'=>$val['error_message']);
           }
        }
        return $returnJobs;
    }

    /*
     * Checks/compares the User who submitted the Job with the current Session User
     *
     * @param $job_username - username who submited the Job
     */
    private function checkUserAccessPermission($job_username) {
            $ret_value = false;
            $sessionUserId = getSessionUserId();
            if (isAdmin($sessionUserId) || $sessionUserId == $job_username) {
                $ret_value = true;
            }
            return $ret_value;
    }
}

?>