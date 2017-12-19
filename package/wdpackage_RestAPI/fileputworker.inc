<?php
/**
 * \file    worker/fileputworker.inc
 * \author WDMV - Mountain View - Software Engineering
 * \copyright Copyright (c) 2012, Western Digital Corp. All rights reserved.
 */
use Jobs\Common;
//use Jobs;

//require_once JOBS_ROOT . '/includes/progress/jobprogress.inc';
require_once FILESYSTEM_ROOT . '/includes/filedescriptor.inc';
require_once FILESYSTEM_ROOT . '/includes/filemanagerutil.inc';
require_once COMMON_ROOT . '/includes/security.inc';

use \Shares\Model\Share\SharesDao;

class FilePutWorker extends Common\JobWorker {

	private $sourcePath;
	private $sourcePathRelative;
	private $sourcePathLocal;
	private $sourceFileManagerDescriptorStr;
	private $isSourceLocalFile;

	private $destPath;
	private $destPathRelative;
	private $destPathLocal;
	private $destFileManagerDescriptorStr;
	private $isDestLocalFile;

	private $destOverwrite;
    static protected $self;

    public static function getInstance() {
        if (!self::$self instanceof FilePutWorker) {
            self::$self = new self();
        }
        return self::$self;
    }

	public function validate() {
        $sharePath = getSharePath();

		if (!startsWith($this->urlPath[0], '@')) {
			// By default if there is no 'File Descriptor' we assume it's a LOCAL file.
			array_unshift($this->urlPath, '@LOCAL');
		}

        $this->sourceFileManagerDescriptorStr = $this->urlPath[0];
		$this->sourcePathRelative = implode('/', array_slice($this->urlPath, 1));
		$this->isSourceLocalFile = isLocalFile($this->sourceFileManagerDescriptorStr);

		if ($this->isSourceLocalFile) {
			$queryParamValue = $this->_validateFilePUTQueryParam($this->queryParams);

			//$newPath = isset($this->queryParams['new_path']) ? trim($this->queryParams['new_path']) : null;
			if ( !empty($queryParamValue["new_path"]) ) {
				//This supports backward compatibility to new_path for local file.
				$this->queryParams['dest_path'] = $queryParamValue["new_path"];
			}

            $shareName = $this->urlPath[1];

			//check user permission for the share
			\Core\Logger::getInstance()->info("source share: $shareName");

            $doCopy = isset($this->queryParams['copy']) ? trim($this->queryParams['copy']) : null;
			$doCopy = ($doCopy === 'true' || $doCopy === '1'  || $doCopy === 1) ? true : false;

            if( $doCopy ) { // COPY
			    if(!(new SharesDao())->isShareAccessible($shareName, false, false)) {
		            throw new Exception('USER_NOT_AUTHORIZED', 403);
			    }
	        } else { // move, user needs write access from source share
			    if(!(new SharesDao())->isShareAccessible($shareName, true, false)) {
		            throw new Exception('USER_NOT_AUTHORIZED', 403);
			    }
	        }

            $this->sourcePathLocal = $this->_constructSourcePathLocal($this->sourcePathRelative);
			\Core\Logger::getInstance()->info("sourcePathRelative: $this->sourcePathRelative");
			$this->_validateFileSourcePathLocal($shareName);
			// Check if the mtime is an integer
			if(isset($this->queryParams["mtime"])){
			 if(!filter_var($this->queryParams['mtime'], FILTER_VALIDATE_INT))
			     throw new Exception('INVALID_MTIME', 400);
			}
			//$mtime = isset($this->queryParams['mtime']) ? trim($this->queryParams['mtime']) : null;
			//$mtime = !is_numeric($mtime) ? strtotime($mtime) : $mtime;
		}// if ($this->isSourceLocalFile)

        $fileName = end(explode('/', $this->sourcePathRelative));
		$this->destPath = isset($this->queryParams['dest_path'])  ? $this->queryParams['dest_path']  : null;

        if ( isset($this->destPath) ) {
			$destPathArr = explode('/', trim($this->destPath, '/'));
			if (!startsWith($destPathArr[0], '@')) {
				//By default if there is no 'File Descriptor' we assume it's a LOCAL file.
				array_unshift($destPathArr, '@LOCAL');
			}
			$this->destFileManagerDescriptorStr = $destPathArr[0];
			$this->destPathRelative = implode('/', array_slice($destPathArr, 1));
			if(is_dir($sharePath . DS .$this->destPathRelative)){
				$this->destPathRelative = $this->destPathRelative . DS . $fileName;
				\Core\Logger::getInstance()->info("destPathRelative :$this->destPathRelative");
			}

			$this->destOverwrite = isset($this->queryParams['overwrite']) ? trim($this->queryParams['overwrite']) : null;
			$this->destOverwrite = ($this->destOverwrite === 'true' || $this->destOverwrite === '1' || $this->destOverwrite === 1) ? true : false;
			$this->isDestLocalFile  = isLocalFile($this->destFileManagerDescriptorStr);

			if ($this->isDestLocalFile) {
				//Validate dest file if it's LOCAL.
				$destPathShareName = $destPathArr[1];
				\Core\Logger::getInstance()->info("destination share : $destPathShareName");
				//check user permission for the destination share
				if(!(new SharesDao())->isShareAccessible($destPathShareName, true, false)) {
		            throw new Exception('USER_NOT_AUTHORIZED', 403);
			    }

				$destDirRelative  = dirname($this->destPathRelative);
				$this->destPathLocal = $sharePath . '/' . $this->destPathRelative;
				\Core\Logger::getInstance()->info("destPathLocal :$this->destPathLocal");
				$this->destPathLocal = removeDuplicateForwardSlashes($this->destPathLocal);
				$this->_validateFileDestPathLocal($destPathShareName, $destDirRelative);
			}// if ($this->isDestLocalFile)
		}
	}//validate

	public function execute() {
        $jobId = $this->queryParams['job_id'];

        // If not destPath set then it must be just an mtime update - but no more or copy
        if (isset($this->destPath)) {
			$doCopy = isset($this->queryParams['copy']) ? trim($this->queryParams['copy']) : null;
			$doCopy = ($doCopy === 'true' || $doCopy === '1'  || $doCopy === 1) ? true : false;

            // COPY
            if( $doCopy ) {

                if(strcasecmp($this->sourceFileManagerDescriptorStr, '@DROPBOX') !== 0) {
                    $sourceParams = filterQueryParams('source_', $this->queryParams);
                }
                else {
                    $sourceParams = $this->queryParams;
                }

                if(strcasecmp($this->destFileManagerDescriptorStr, '@DROPBOX') !== 0) {
                    $destParams = filterQueryParams('dest_', $this->queryParams);
                }
                else {
                    $destParams = $this->queryParams;
                }

                //$destParams   = filterQueryParams('dest_', $this->queryParams);
				$isDir = false;
				$sourceFileDescriptor      = new FileDescriptor($this->sourceFileManagerDescriptorStr, $sourceParams, $this->sourcePathRelative, $isDir);
				$destinationFileDescriptor = new FileDescriptor($this->destFileManagerDescriptorStr, $destParams, $this->destPathRelative, $isDir);
				copyFile($sourceFileDescriptor, $destinationFileDescriptor, $this->destOverwrite, $jobId, $this->getAsync());
			}
            else { // MOVE/RENAME
                if (!$this->isDestLocalFile || !$this->isSourceLocalFile) {
                	throw new \Exception('UNSUPPORTED_OPERATION', 400);
				}
				if (!moveFile($this->sourcePathLocal, $this->destPathLocal) ) {
					throw new \Exception('MOVE_FILE_FAILED', 500);
				}
                else {
                    if($this->getAsync()) {
                        \Jobs\JobManager::getInstance()->setWorkComplete($jobId, 1);
                    }
                }
			} // MOVE/RENAME
			//Set Mtime for the New file
			if(isset($this->queryParams["mtime"])){
    			if(!changeMtime($this->destPathLocal, $this->queryParams["mtime"])){
    			        throw new \Exception('FILE_MTIME_UPDATE_FAILED', 500);
    			}
			}
		}// if ( !empty($newPath) )
		else{
		    // if destPath is empty, the request is not to move or copy - set the mtime on source file
		    if(isset($this->queryParams["mtime"])){
    			if(!changeMtime($this->sourcePathLocal, $this->queryParams["mtime"])){
    			        throw new \Exception('FILE_MTIME_UPDATE_FAILED', 500);
    			}
		    }
		}
	}//execute

	public function results() {
		$results = array('status' => 'success');
		if (!empty($mtime)) {
        	$attributes   = getAttributes($this->sourcePathLocal, $this->sourcePathRelative, null, null);
            $results['mtime'] = $attributes['mtime']['VALUE'];
        }
        return $results;
	}//results

	private function _validateFileSourcePathLocal($shareName) {
        \Core\Logger::getInstance()->info($this);
		if (trim($shareName) == '') {
			throw new \Exception('SHARE_NAME_MISSING', 400);
		}
		if (!file_exists($this->sourcePathLocal)) {
			throw new \Exception('FILE_NOT_FOUND', 404);
		}
		if (is_dir($this->sourcePathLocal)) {
			throw new \Exception('PATH_NOT_FILE', 404);
		}
                if (is_link($this->sourcePathLocal)) {
                    throw new \Exception('PATH_IS_LINK', 400);
                }
		if (!isPathLegal($this->sourcePathLocal)) {
			throw new \Exception('PATH_NOT_VALID', 404);
		}
	}//_validateFileSourcePathLocal

	private function _validateFileDestPathLocal($destPathShareName, $destDirRelative) {
		$sharePath = getSharePath();
		
		if (!file_exists($sharePath . DS . $destPathShareName)) {
			throw new \Exception('INVALID_SHARE', 403);
		}
		if (invalidFat32Path($this->destPathLocal, $destPathShareName)){
			throw new \Core\Rest\Exception('INVALID_CHARACTER', 400);
		}
		if (!file_exists($sharePath . DS . $destDirRelative)) {
			throw new \Exception('DIR_NOT_EXIST', 404);
		}
		if (strcmp($this->sourcePathLocal, $this->destPathLocal) === 0 ) {
			throw new \Exception('SOURCE_DEST_FILE_EQUAL', 400);
		}
		if (!$this->destOverwrite && !file_exists($this->sourcePathLocal) && file_exists($this->destPathLocal)) {
		//if (!$this->destOverwrite && file_exists($this->destPathLocal)) {
			throw new \Exception('FILE_EXISTS', 403);
		}
		if (!isPathLegal($this->destPathLocal)) {
			throw new \Exception('INVALID_PATH', 404);
		}
	}//validateFileDestPathLocal

	private function _constructSourcePathLocal($sourcePathRelative) {
		$sourcePathLocal = getSharePath() . DS . $sourcePathRelative;
		$sourcePathLocal = removeDuplicateForwardSlashes($sourcePathLocal);
		return $sourcePathLocal;
	}//constructSourcePathLocal

	private function _validateFilePUTQueryParam($queryParams) {
		$newPath = isset($queryParams['new_path']) ? $queryParams['new_path'] : null;
		$mtime = isset($queryParams['mtime']) ? trim($queryParams['mtime']) : null;
		$mtime = !is_numeric($mtime) ? strtotime($mtime) : $mtime;

		if (startsWith($newPath, '@')){
			// new_path does not support 'File Descriptors'.
			throw new \Exception('INVALID_PARAMETER', 400);
		}
		if (!empty($mtime)) {
			if(!isset($mtime) && !isset($newPath)) {
				throw new \Exception('INVALID_PARAMETER', 400);
			}
			if(!is_numeric($mtime)) {
				throw new \Exception('INVALID_MTIME', 400);
			}
		}
		return array('new_path' => $newPath, 'mtime' => $mtime);
	}//_validateFilePUTQueryParam


}