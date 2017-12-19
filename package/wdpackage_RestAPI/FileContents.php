<?php

namespace Filesystem\Controller;
use Filesystem\Model;
use \Shares\Model\Share\SharesDao;
/**
* \file filesystem/filecontents.php
* \author WDMV - Mountain View - Software Engineering
* \copyright Copyright (c) 2012, Western Digital Corp. All rights reserved.
*/

require_once(FILESYSTEM_ROOT . '/includes/contents.inc');
require_once(COMMON_ROOT . '/includes/globalconfig.inc');
require_once(COMMON_ROOT . '/includes/security.inc');
require_once(COMMON_ROOT . '/includes/util.inc');
require_once(FILESYSTEM_ROOT . '/includes/db/multidb.inc');
require_once FILESYSTEM_ROOT . '/includes/filemanagerutil.inc';

setlocale(LC_ALL, 'en_US.utf8');
/**
* \class FileContents
* \brief Downloads, uploads, or updates the contents of a file.
*
* - This component extends the Rest Component.
* - Supports xml and json formats for response data. Default format is xml.
* - This component can be executed from browser, flash UI app or any script.
* - User must be authenticated to use this component.
*
* \see File, Dir
*/
class FileContents
{

	use \Core\RestComponent;

	const COMPONENT_NAME = 'file_contents';
	/**
	* \par Description:
	* This GET request is used to download the transcoded contents for specified file.
	*
	* \par Security:
	* - User Authentication required.
	* - Works on WAN or LAN
    * - HMAC may be used as an alternative method of authentication.
	*
	* \par HTTP Method: GET
	* - http://localhost/api/@REST_API_VERSION/rest/file_contents/{share_name}/{file_name}
	*
	* \param share_name String  - required
	* \param file_name  String  - required
	* \param http_range  Integer - optional
	* \param tn_type     String  - optional [tn96s1, i1024s1]
	* \param is_download Boolean - optional
	* \param format      String  - optional (default is xml)
	* \param is_blocking Boolean - optional (default to true)
	*
	*  \par Parameter Details:
	* - share_name - the name of the share.
	* - file_name - the file to be downloaded.
	* - http_range - this is the byte range of the file that will be downloaded. The format is that of the Range header specified in RFC 2616
	* - tn_type - this is the transcoding type
	* - is_download - default is true. When true it'll show download dialog in broswer. If it is false it will display the content in the browser.
	* - is_blocking - default is true. When set, it's value other than 'true' will be considered as false
	*
	* \par Parameter Usages:
	*
	* \par NOTE: requesting a byte range from a file
	* - You can request a start and end byte number by either setting the Range header, or by passing  the http_range parameter in the URL. The format of either is according to HTTP 1.1 RFC 2616 (http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35)
	*
	* - Setting the Range header (the space between the : and the word 'bytes' is mandatory).
	*
	* - Range: bytes=<start>-<end>
	*
	* - altermatively you can set the http_range parameter, this must also conform to the HTTP 1.1 RFC 2616, so the '=' must be URL-endcoded
	*
	* - http_range=bytes%3D<start>-<end>
	*
	* - Get files via API:\n
	* http://localhost/api/1.0/rest/file_contents/{share name}/Animals/MP900178476.JPG?tn_type=tn96s1
	* http://localhost/api/1.0/rest/file_contents/{share name}/Animals/MP900178476.JPG?tn_type=tn96s1&is_download=true
	* http://localhost/api/1.0/rest/file_contents/{share name}/Animals/MP900178476.JPG?tn_type=tn96s1&is_download=false
	* http://localhost/api/1.0/rest/file_contents/{share name}/Animals/MP900178476.JPG? http_range=bytes%3D100-500
	*
	*
	* \return the file content if it's available
	*
	* \par HTTP Response Codes:
	* - 200 - On success
	* - 400 - Bad request
	* - 401 - User is not authorized
	* - 403 - Request is forbidden
	* - 404 - Request not found
	* - 500 - Internal server error
	*
	* \par Error Codes:
	* - 26 - FILE_NOT_FOUND - File not found
	* - 44 - PATH_NOT_FOUND - Path not found
	* - 47 - SHARE_NAME_MISSING - Share name is missing
	* - 57 - USER_NOT_AUTHORIZED - User not authorized
	* - 92 - FILE_PATH_MISSING - File path missing
	* - 378 - INVALID_VOLUME_FOR_SCANNING - Crawler scanning is switched off for this external volume
	*/
	function get($urlPath, $queryParams = null, $outputFormat = 'xml')
	{
		if (isset($queryParams['hmac'])) {
			try {
				\Auth\Model\Hmac::validatePacket($queryParams['hmac'], implode(DS, $urlPath));
			} catch (\Exception $e) {
				throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
			}
		}

        $shareName = $urlPath[0];
        if (trim($shareName) == '') {
        	throw new \Core\Rest\Exception('SHARE_NAME_MISSING', 400, NULL, static::COMPONENT_NAME);
        }
        $sharesDao = new \Shares\Model\Share\SharesDao();

        $share = $sharesDao->get($shareName);
        if (!$share) {
        	throw new \Core\Rest\Exception('FILE_NOT_FOUND', 404, NULL, static::COMPONENT_NAME);
        }

        if (!isset($queryParams['hmac']) && !$sharesDao->isShareAccessible($shareName, false, false)) {
        	throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
        }

		$urlPath = array_slice($urlPath, 1);
		$filePath = implode('/', $urlPath);
		$fullPath =  $share->getSymbolicPath() . DIRECTORY_SEPARATOR . $filePath;

		if ($filePath == ''){
			throw new \Core\Rest\Exception('FILE_PATH_MISSING', 400, NULL, static::COMPONENT_NAME);
		}

		if (!file_exists($fullPath)){
			throw new \Core\Rest\Exception('FILE_NOT_FOUND', 404, NULL, static::COMPONENT_NAME);
		}

		if (is_dir($fullPath)){
			throw new \Core\Rest\Exception('PATH_NOT_FILE', 400, NULL, static::COMPONENT_NAME);
		}

		if (!isPathLegal($filePath)){
			throw new \Core\Rest\Exception('INVALID_PATH', 400, NULL, static::COMPONENT_NAME);
		}

		foreach (['http_range', 'HTTP_RANGE'] as $index){
			if (isset($queryParams[$index]) && $queryParams[$index] < 0){
				throw new \Core\Rest\Exception('HTTP_RANGE_CANNOT_BE_NEGETIVE', 400, NULL, static::COMPONENT_NAME);
			}

			if(!empty($queryParams[$index])){
				$_SERVER['HTTP_RANGE'] = $queryParams[$index];
			}
		}

		//If isDownload is true, it'll show download dialog in broswer. It is false will display in browser.
		$isDownload      = getParameter($queryParams, 'is_download', \PDO::PARAM_BOOL, TRUE, FALSE);
		$transcodingType = !empty($queryParams['tn_type']) ? $queryParams['tn_type'] : NULL;
		$isBlocking      = isset($queryParams['is_blocking']) ? filter_var($queryParams['is_blocking'], \FILTER_VALIDATE_BOOLEAN) : TRUE;

		if($transcodingType != NULL && !in_array($transcodingType, ['tn96s1', 'i1024s1'])){
			throw new \Core\Rest\Exception('INVALID_TN_TYPE', 400, NULL, static::COMPONENT_NAME);
		}try{
			//if (preg_match('/\%|\s$/', $fullPath)){
				//JS - workaround for current version of X-Sendfile barfing on file paths containing '%' or ending in whitespace, even
				//if it is encoded
			//	readFileFromPathOld($shareName, $fullPath, $transcodingType, $isBlocking);
			//}else{
				readFileFromPathNew($shareName, $fullPath, $transcodingType, $isDownload, $isBlocking);
			//}
		}catch (\Exception $e){
			throw new \Core\Rest\Exception($e->getMessage(), $e->getCode(), $e, 'file_contents');
		}
	}

	/**
	* \par Description:
	* This POST request is used upload a specified file.
	*
	* * Note: File uploads are limited to 1GB. Any largers files must use chunked PUT data.
	**  On WAN on Relay connection the limitation is 800Mb
	*
	* \par Security:
	* - User Authentication required.
	* - Works on WAN or LAN
    * - HMAC with an access of RC may be used as an alternative method of authentication.
	*
	* \par HTTP Method: POST
	* - http://localhost/api/@REST_API_VERSION/rest/file_contents/{share_name}/{dir_name}/{file_name}
	*
	* \param share_name String  - required
	* \param dir_name   String  - optional
	* \param file_name  String  - optional
	* \param format    String  - optional (default is xml)
	* \param create_path Boolean - optional (default is false)
	* \param mtime      Integer - optional
	*
	* \par Parameter Details:
	* - share_name - the name of the share.
	* - dir_name - the directory where to upload the file.
	*    If  the path is to be created on a FAT32 formatted volume - the following characters are not permitted to be used: ':', '<', '>', '\', '?', '*', '"
	*   '|' pipe character is not supported on any filesystem as a part of a path
	* - file_name - the file to be uploaded. If filename is not specified - the name of the source file will be used
	* - create_path - if true and if the path to the file does not exist it will be recursively created
	* - mtime  - Modified time of file supplied as Unix time (number of seconds that have elapsed since 00:00:00 Coordinated Universal Time (UTC), Thursday, 1 January 1970)
	*
	* \retval status String - success
	*
	* \par HTTP Response Codes:
	* - 200 - On success
	* - 400 - Bad request
	* - 401 - User is not authorized
	* - 403 - Request is forbidden
	* - 404 - Request not found
	* - 500 - Internal server error
	*
	* \par Error Codes:
	* - 20 - DIR_NOT_EXIST - Directory does not exist
	* - 25 - FILE_EXISTS - File already exists
	* - 27 - FILE_UPLOAD_FAILED - Failed to upload file
	* - 33 - INVALID_PARAMETER - array(,'Invalid parameter
	* - 47 - SHARE_NAME_MISSING - Share name is missing
	* - 57 - USER_NOT_AUTHORIZED - User not authorized
	* - 71 - INVALID_CHARACTER - Invalid character
	* - 91 - SOURCE_FILE_MISSING - Source file missing
	* - 96 - INVALID_MTIME - Invalid modified time
	* - 45 - PATH_NOT_VALID - Path not valid
	* - 46 - SHARE_INACCESSIBLE - Share is inaccessible
	* - 75 - SHARE_NOT_FOUND - Share name does not exists
	* - 332 - DIR_NAME_LENGTH_INVALID - Dir name is longer than 255 characters
	* - 25 - FILE_EXISTS - File with the name same name as one of the folders to be created exists
	*
	* \par XML Response Example:
	* \verbatim
		<file_contents>
			<status>success</status>
		</file_contents>
	\endverbatim
	*/
	function post($urlPath, $queryParams = null, $outputFormat = 'xml')
	{
        if (isset($queryParams['hmac'])) {
			try {
				\Auth\Model\Hmac::validatePacket($queryParams['hmac'], implode(DS, $urlPath), 'RC');
			} catch (\Exception $e) {
				throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
			}
		}

        $shareName = $urlPath[0];
        if (trim($shareName) == '') {
        	throw new \Core\Rest\Exception('SHARE_NAME_MISSING', 400, NULL, static::COMPONENT_NAME);
        }

        $sharesDao = new \Shares\Model\Share\SharesDao();

        $share = $sharesDao->get($shareName);
        if (!$share) {
        	throw new \Core\Rest\Exception('SHARE_NOT_FOUND', 404, NULL, static::COMPONENT_NAME);
        }

        if (!isset($queryParams['hmac']) && !$sharesDao->isShareAccessible($shareName, TRUE, FALSE)) {
        	throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
        }

		$fileAbsolutePath =  $share->getSymbolicPath() . '/' . implode('/', array_slice($urlPath, 1));
        $dir = dirname($fileAbsolutePath);

		$fileContentsModelObject = new Model\FileContents();

		$createPath  = (isset($queryParams['create_path'])&&(filter_var($queryParams['create_path'], \FILTER_VALIDATE_BOOLEAN) == 1)) ? true : false;
		$mtime = false;
		if(isset($queryParams['mtime'])){
			$mtime = $queryParams['mtime'];
			if (!(int)$mtime == $mtime || $mtime<0){
				throw new \Core\Rest\Exception('INVALID_MTIME', 400, NULL, static::COMPONENT_NAME);
			}
		}

		if (!isset($_FILES['file']) || (isset($_FILES['file']['error']) && $_FILES['file']['error'] == 4)){
			throw new \Core\Rest\Exception('SOURCE_FILE_MISSING', 400, NULL, static::COMPONENT_NAME);
		}
		if (isset($_FILES['file']['error']) && $_FILES['file']['error'] > 0){
			throw new \Core\Rest\Exception('FILE_UPLOAD_ERROR', 400, NULL, static::COMPONENT_NAME);
		}
		if ($_FILES['file']['size'] > 1024*1024*1024) {
			throw new \Core\Rest\Exception('FILE_TOO_LARGE', 403, NULL, static::COMPONENT_NAME);
		}
		if (!isPathLegal($_FILES['file']['name'])) {
			throw new \Core\Rest\Exception('FILE_NOT_FOUND', 404, NULL, static::COMPONENT_NAME);
		}
		if (invalidFat32Path($fileAbsolutePath, $shareName)){
			throw new \Core\Rest\Exception('INVALID_CHARACTER', 400, NULL, static::COMPONENT_NAME);
		}
		if (file_exists($dir)){
			if(!is_dir($dir)){
				throw new \Core\Rest\Exception('FILE_EXISTS', 403, NULL, static::COMPONENT_NAME);
			}
		}elseif (!$createPath){
			throw new \Core\Rest\Exception('DIR_NOT_EXIST', 404, NULL, static::COMPONENT_NAME);
		}else{
			$fileContentsModelObject->createDir($dir);
		}

		if (is_dir($fileAbsolutePath)) {
			//no target file name supplied, so append source file name to dir path
			$fileAbsolutePath = $fileAbsolutePath . DS . $_FILES['file']['name'];
		}
		if(file_exists($fileAbsolutePath)) {
			throw new \Core\Rest\Exception('FILE_EXISTS', 403, NULL, static::COMPONENT_NAME);
		}

		if(!isPathLegal($fileAbsolutePath)){
			throw new \Core\Rest\Exception('PATH_NOT_VALID', 400, NULL, static::COMPONENT_NAME);
		}
		
		if (mb_strlen($dirPath, 'UTF-8') > 255){
			throw new \Core\Rest\Exception('DIR_NAME_LENGTH_INVALID', 400, NULL, static::COMPONENT_NAME);
		}

		try{
			$status = $fileContentsModelObject->writeFileFromPath($fileAbsolutePath, $_FILES['file']['tmp_name']);
			if ($status !== true){
				 throw new \Core\Rest\Exception('FILE_UPLOAD_FAILED', 500, NULL, static::COMPONENT_NAME);
			}
			if(!empty($mtime)) {
				changeMtime($fileAbsolutePath, $mtime);
			}
			else {
				//set file modified time to now
				changeMtime($fileAbsolutePath, time());
			}


			$this->generateItemOutput(201, 'file_contents', ['status' => 'success'], $outputFormat);
		}catch (\Exception $e){
			throw new \Core\Rest\Exception($e->getMessage(), $e->getCode(), $e, 'file_contents');
		}
	}

	/**
	* \par Description:
	* This PUT request is used modify or replace existing file. Also this API can be used to modify a file partially by providing specific ranges of the current file to be modified.
	*
	*Note: Depending on Content-Type header sent the API will use either regular or streaming approach. With regular approach the limit of 1Gb is applied, with streaming there is no size limitation.
	*On WAN on Relay connection the limitation is 800Mb
	*
	*Streaming will be applied with any Content-Type other than multipart/form-data (With multipart/form-data rest method of POST is expected to be used with parameter 'rest_method' equal to 'PUT'.
	*This will insure the required $_FILES[] array is set.) if rest_method parameter PUT (uppercase) is passed. If rest_method nis not passed or passed in lower case, the only content-type accepted is application/octet-stream
	*Streaming is a faster and preffered way of using PUT filecontents
	*If there is not enough storage on the device 400 "File upload error" will be returned.
	*If a new file is uploaded to the device with not enough storage the file will not get uploaded. If a file already exists in the case of non-streaming approach the file will remain unchanged, in the case of streaming approach, as much of the stream as there is room for will get uploaded.
	*
	* \par Security:
	* - User Authentication required.
	* - Works on WAN or LAN
    * - HMAC with an access of RC may be used as an alternative method of authentication, but only if the file does not exist.
	*
	* \par HTTP Method: PUT
	* - http://localhost/api/@REST_API_VERSION/rest/file_contents/{share_name}/{dir_name}/{file_name}
	*
	* \param share_name String  - required
	* \param dir_name   String  - required
	* \param file_name  String  - required
	* \param http_range String  - optional
	* \param mtime      Integer - optional
	* \param format     String  - optional (default is xml)
	* \param create_path Boolean - optional (default is false)
	* \param dest_path   string  - optional
	*
	* \par Parameter Details:
	* - share_name - the name of the share.
	* - dir_name - the directory of the file
	* - file_name - the file to be modified or replaced.
	* - http_range - this is the byte range of the file that will be modified. This parameter can be in following format: start_byte-end_byte. If en_byte is 0 or '' or a value greater than
	* total size of the current file, then new file will be appended to existing file fater the byte value pecified in start_byte. Otherwise, if value of end_byte is smaller than the size of existing file
	* then existing file will be replaced between start_byte to end_byte length, with data from new file
	* - mtime  - Modified time of file supplied as Unix time (number of seconds that have elapsed since 00:00:00 Coordinated Universal Time (UTC), Thursday, 1 January 1970)
	* - create_path - if true and if the path to the file does not exist it will be recursively created
	* - dest_path - this is the absolute path (as {share_name}/{dir_name}/{file_name}) to which the uploaded file should be moved to. If given dest_path is a folder and does not include a filename,
	* then the uploaded file is moved to the folder with the same name as specified by file_name parameter. If dest_path is a folder and does not exist, it will be created if the create_path parameter set to true,
	* otherwise, error thrown as folder does not exist. Given path will be considered as a directory path if it ends with a directory separator (i.e: '/') otherwise it will be considered as a filename with path.
	* If  the path is to be created on a FAT32 formatted volume - the following characters are not permitted to be used: ':', '<', '>', '\', '?', '*', '"
	* '|' pipe character is not supported on any filesystem as a part of a path. This is applied both to the original file path and to dest path
	*
	* \retval status String - success
	*
	* \par HTTP Response Codes:
	* - 200 - On success
	* - 400 - Bad request
	* - 401 - User is not authorized
	* - 403 - Request is forbidden
	* - 404 - Request not found
	* - 500 - Internal server error
	* - 400 - PATH_NOT_VALID - Path not valid
	* - 401 - SHARE_INACCESSIBLE - Share is inaccessible
	* - 404 - SHARE_NOT_FOUND - Share name does not exists
	* - 400 - DIR_NAME_LENGTH_INVALID - Dir name is longer than 255 characters
	* - 403 - FILE_EXISTS - File with the name same name as one of the folders to be created exists
	* - 400 - DEST_PATH_NOT_VALID - Destination path not Valid
	* - 400 - DEST_PATH_FILE_EXISTS - Destination file already Exists
     * - 71 - INVALID_CHARACTER - Invalid character
	*
	* \par XML Response Example:
	* \verbatim
    <file_contents>
    	<status>success</status>
    </file_contents>
	\endverbatim
	*/
	function put($urlPath, $queryParams = null, $outputFormat = 'xml')
	{
        if (isset($queryParams['hmac'])) {
			try {
				\Auth\Model\Hmac::validatePacket($queryParams['hmac'], implode(DS, $urlPath), 'RC');
			} catch (\Exception $e) {
				throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
			}
		}

        $shareName = $urlPath[0];
        if (trim($shareName) == '') {
        	throw new \Core\Rest\Exception('SHARE_NAME_MISSING', 400, NULL, static::COMPONENT_NAME);
        }

        $sharesDao = new \Shares\Model\Share\SharesDao();

        $share = $sharesDao->get($shareName);
        if (!$share) {
        	throw new \Core\Rest\Exception('SHARE_NOT_FOUND', 404, NULL, static::COMPONENT_NAME);
        }

        if (!isset($queryParams['hmac']) && !$sharesDao->isShareAccessible($shareName, TRUE, FALSE)) {
        	throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
        }

        $fileAbsolutePath =  $share->getSymbolicPath() . '/' . implode('/', array_slice($urlPath, 1));
        $fileDirPath = dirname($fileAbsolutePath);
        $fileAlreadyExists = file_exists($fileAbsolutePath);

        if (isset($queryParams['hmac']) && $fileAlreadyExists) {
            throw new \Core\Rest\Exception('USER_NOT_AUTHORIZED', 401, NULL, static::COMPONENT_NAME);
        }

		$httpRange  = $start = $end = $size = $stream = false;

		$createPath  = (isset($queryParams['create_path'])&&(filter_var($queryParams['create_path'], \FILTER_VALIDATE_BOOLEAN) == 1)) ? true : false;

		$mtime = false;
		if(isset($queryParams['mtime'])){
			$mtime = $queryParams['mtime'];
			if (!(int)$mtime == $mtime || $mtime<0){
				throw new \Core\Rest\Exception('INVALID_MTIME', 400, NULL, static::COMPONENT_NAME);
			}
		}

		if(isset($_SERVER['CONTENT_TYPE']) && strtolower(substr($_SERVER['CONTENT_TYPE'],0,19)) != "multipart/form-data"){
			$stream =true;
		}
	
		if(!empty($_SERVER['HTTP_RANGE']))
			$httpRange = $_SERVER['HTTP_RANGE'];

		if(!empty($queryParams['HTTP_RANGE']))
			$httpRange = $queryParams['HTTP_RANGE'];

		if(!empty($queryParams['http_range']))
			$httpRange = $queryParams['http_range'];

		if(!$stream){
			if (!isset($_FILES['file']) || (isset($_FILES['file']['error']) && $_FILES['file']['error'] == 4)){
				throw new \Core\Rest\Exception('SOURCE_FILE_MISSING', 400, NULL, static::COMPONENT_NAME);
			}
			if (isset($_FILES['file']['error']) && $_FILES['file']['error'] > 0){
				throw new \Core\Rest\Exception('FILE_UPLOAD_ERROR', 400, NULL, static::COMPONENT_NAME);
			}
			if (!isPathLegal($_FILES['file']['name'])) {
				throw new \Core\Rest\Exception('INVALID_PATH', 404, NULL, static::COMPONENT_NAME);
			}
		}
		//right now in http range "end" is ignored
		if(!empty($httpRange)) {
			list($start, $end) = explode('-', $httpRange);

			if(substr_count($httpRange, '-')>1){
				throw new \Core\Rest\Exception('HTTP_RANGE_CANNOT_BE_NEGETIVE', 400, NULL, static::COMPONENT_NAME);
			}

			if (!$fileAlreadyExists && $start > 0){
				throw new \Core\Rest\Exception('FILE_NOT_FOUND', 404, NULL, static::COMPONENT_NAME);
			}

			$fstat = fstatLfs($fileAbsolutePath);
			$size = $fstat['size'];

			if (!$fstat) {
				throw new \Core\Rest\Exception('FILE_READ_FAILED', 500, NULL, static::COMPONENT_NAME);
			}

		}else{
			if ($fileAlreadyExists && is_file($fileAbsolutePath) && !unlink($fileAbsolutePath)) {
				throw new \Core\Rest\Exception('DELETE_FILE_FAILED', 500, NULL, static::COMPONENT_NAME);
			}
		}
		
		$fileContentsModelObject = new Model\FileContents();
		if(invalidFat32Path($fileAbsolutePath, $shareName)){
			throw new \Core\Rest\Exception('INVALID_CHARACTER', 400, NULL, static::COMPONENT_NAME);
		}

		if (file_exists($fileDirPath)){
			if (!is_dir($fileDirPath)){
				throw new \Core\Rest\Exception('FILE_EXISTS', 403, NULL, static::COMPONENT_NAME);
			}
		}
		elseif (!$createPath){
			throw new \Core\Rest\Exception('DIR_NOT_EXIST', 404, NULL, static::COMPONENT_NAME);
		}
		else{
			$fileContentsModelObject->createDir($fileDirPath);
		}

		if(!isPathLegal($fileAbsolutePath)) {
			throw new \Core\Rest\Exception('PATH_NOT_VALID', 400, NULL, static::COMPONENT_NAME);
		}

		if (mb_strlen($fileAbsolutePath, 'UTF-8') > 255){
			throw new \Core\Rest\Exception('DIR_NAME_LENGTH_INVALID', 400, NULL, static::COMPONENT_NAME);
		}

		$destAbsolutePath = NULL;
		//if dest_path parameter is set verify that and determine the absolute path from the given path
		if(isset($queryParams['dest_path'])){
		    $destPath = $queryParams['dest_path'];

		    if(!isPathLegal($destPath)){
		        throw new \Core\Rest\Exception('DEST_PATH_NOT_VALID', 400, NULL, static::COMPONENT_NAME);
		    }
            //TODO: Check if it's a symLink?
            if(!empty($destPath)){
                //retrieve the absolute path from the value given in dest path parameter

                $destPathArray = explode(DS, $destPath);
                $endChar = substr($destPath, -1);
                array_shift($destPathArray);
                $destSharePath = $this->_getSharePathFromUrlPath($destPathArray, TRUE, FALSE, TRUE);
                $destAbsolutePath = $destSharePath->getAbsolutePath();

                if(invalidFat32Path($destPath, $destSharePath->getShareName())){
                	throw new \Core\Rest\Exception('INVALID_CHARACTER', 400, NULL, static::COMPONENT_NAME);
                }
                
                // If the last character is '/' then it is a directory path
                // dest_path=/share/folder/ or =/share/folder/file.ext
                if(strcmp($endChar, '/') == 0){
                    if(!file_exists($destAbsolutePath)){
                        //create dir, if asked
                        if($createPath){
                            $fileContentsModelObject->createDir($destAbsolutePath);
                        }
                        else{
                            throw new \Core\Rest\Exception('DIR_NOT_EXIST', 404, NULL, static::COMPONENT_NAME);
                        }
                    }

                    //it is a directory path then retrieve the file name from URL path
                    if(is_dir($destAbsolutePath)){
                        $destFileName = substr($fileAbsolutePath, strrpos($fileAbsolutePath, DS));
                        $destAbsolutePath = $destAbsolutePath . DS . trim($destFileName, DS);
                    }
                }
                else{
                    //Given path is a file path, check if it's parent directory exists
                    if(!file_exists(dirname($destAbsolutePath))){
                        //create dir, if asked
                        if($createPath){
                            $fileContentsModelObject->createDir(dirname($destAbsolutePath));
                        }
                        else{
                            throw new \Core\Rest\Exception('DIR_NOT_EXIST', 404, NULL, static::COMPONENT_NAME);
                        }
                    }
                }

                if(file_exists($destAbsolutePath)){
                    throw new \Core\Rest\Exception('DEST_PATH_FILE_EXISTS', 400, NULL, static::COMPONENT_NAME);
                }
            }
		}//isset($queryParams['dest_path'])

		try{
			set_time_limit(0);
			if(!$stream){
				$status = $fileContentsModelObject->writeFileFromPath($fileAbsolutePath, $_FILES['file']['tmp_name'], !empty($httpRange), $start, $size);
				if ($status!== TRUE){
					set_time_limit(ini_get('max_execution_time'));
					throw new \Core\Rest\Exception('FILE_UPLOAD_FAILED', 500, NULL, static::COMPONENT_NAME);
				}
			}else{
				$status = $fileContentsModelObject->writeFileFromStream($fileAbsolutePath, !empty($httpRange), $start, $size);
				if ($status!== TRUE){
					set_time_limit(ini_get('max_execution_time'));
					throw new \Core\Rest\Exception('FILE_UPLOAD_ERROR', 400, NULL, static::COMPONENT_NAME);
				}
			}

			//if dest_path set, means it's file upload and then move
			if(!empty($destAbsolutePath)){
			    if(!moveFile($fileAbsolutePath, $destAbsolutePath)){
			        set_time_limit(ini_get('max_execution_time'));
			        throw new \Exception('MOVE_FILE_FAILED', 500);
			    }
			    //Since the file has moved to a new location, $fileAbsolutePath is now the $destAbsolutePath
			    $fileAbsolutePath = $destAbsolutePath;
			}

			if(!empty($mtime)){
				changeMtime($fileAbsolutePath, $mtime);
			}
			else {
				changeMtime($fileAbsolutePath, time());
			}
			set_time_limit(ini_get('max_execution_time'));
			$this->generateItemOutput(200, static::COMPONENT_NAME, ['status' => 'success'], $outputFormat);
		}
		catch (\Exception $e){
			throw new \Core\Rest\Exception($e->getMessage(), $e->getCode(), $e, 'file_contents');
		}
	}
}
