<?php

namespace Storage\Transfer\Controller;

require_once (COMMON_ROOT . '/includes/security.inc');
require_once(COMMON_ROOT . '/includes/constants.inc');
require_once STORAGE_ROOT . '/src/Storage/Transfer/Common/StorageTransferPutWorker.php';

use Jobs;
use \Auth\User\UserSecurity;
use Storage\Transfer\Model;

/**
 * \file StorageActiveTransfer.php
 * \author WD
 * \copyright Copyright (c) 2012, Western Digital Corp. All rights reserved.
 */

/**
 * \class StorageActiveTransfer
 * \brief Used for manually initiating a storage transfer.
 *
 * - This component extends the Rest Component.
 * - Supports xml and json formats for response data. Default format is xml.
 * - User must be authenticated to use this component.
 *
 */
class StorageActiveTransfer {

    use \Core\RestComponent;

    const COMPONENT_NAME = 'storage_active_transfer';

    /**
     * \par Description:
     * Used to manually initiate a storage transfer based on the src path and dest path provided.
     *
     * \par Security:
     * - Requires Admin User authentication.
     *
     * \par HTTP Method: POST
     * - http://localhost/api/@RST_API_VERSION/rest/storage_active_transfer/{src_path}
     *
     * \par Parameter Details:
     * \param src_path             String   - required
     * \param transfer_mode        String   - optional
     * \param async                boolean  - optional
     *
     * \par Parameter Details
     * - src_path - source path of the file transfer
     * - transfer_mode - mode of storage transfer. Value of this parameter can be 'copy' or 'move'. If this value is not passed then transfer will happen
     *                   according to the behaviour saved in storage transfer settings.
     * - async - if set to true, will treat the request as an asynchronous Job and return the Job Id in response
     * - async_comment - the user comment about the job description
     *
     * \retval status String - success
     *
     * \par HTTP Response Codes:
     * - 200 - On successful restore of the configuration
     * - 400 - Bad request, if parameter or request does not correspond to the api definition
     * - 401 - User is not authorized
     * - 403 - Request is forbidden
     * - 404 - Requested resource not found
     * - 500 - Internal server error
     *
     * \par Error Codes:
     * - 401  - STORAGE_TRANSFER_BAD_REQUEST - System configuration bad request.
     * - 402  - STORAGE_TRANSFER_DEVICE_NOT_LOCATED - Unable to locate SD card device
     *
     * \par XML Response Example:
     * \verbatim
      <storage_active_transfer>
        <job_id>56</job_id>
        <status>success</status>
       </storage_active_transfer>
      \endverbatim
     */
    public function post($urlPath, $queryParams = null, $outputFormat = 'xml') {

        $transferPutWorker = \StorageTransferPutWorker::getInstance();
        $transferPutWorker->setupWorker($urlPath, $queryParams);
        $transferPutWorker->validate();
        if($queryParams['async'] == 'true') {
    	    //Creating Job ID. Inserting same in Jobs DB.
    	    $job_manager = \Jobs\JobManager::getInstance();
    	    $job_manager->initManager($urlPath, $queryParams, 'post', self::COMPONENT_NAME, 'COPY');
    	    $asyncComment = isset($queryParams['async_comment']) ? $queryParams['async_comment'] : '';
    	    $jobid = $job_manager->create($queryParams['async_comment']); //Got all parameters ready create a JOB in DB

    	    if(isset($jobid) && $jobid > 0) {
    	    	\Jobs\Common\JobMonitor::triggerJobMonitor();
    	        $this->generateSuccessOutput(202, self::COMPONENT_NAME, array('job_id' => $jobid, 'status' => 'success'), $outputFormat);
    	        //if(!isset($queryParams['async_test']) || $queryParams['async_test']!=='skip_job_start') {
    	            // async_test not a require param but only used during testing to skip job start trigger
    	        //    \Jobs\Common\JobMonitor::triggerJobMonitor();
    	        //}
    	    }
    	    else {
    	        $this->generateErrorOutput(500, self::COMPONENT_NAME, 'JOB_MANAGER_CREATE_ERROR', $outputFormat);
    	    }
    	}else{
    	    $this->generateErrorOutput(500, self::COMPONENT_NAME, 'STORAGE_TRANSFER_BAD_REQUEST', $outputFormat);
    	}
    	
    }
}