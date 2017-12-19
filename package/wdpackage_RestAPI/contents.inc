<?php
use Albums\Exception;
/**
 * \file filesystem\contents.inc
 * \author WDMV - Mountain View - Software Engineering
 * \copyright Copyright (c) 2012, Western Digital Corp. All rights reserved.
 */
require_once(COMMON_ROOT . '/includes/security.inc');
require_once(FILESYSTEM_ROOT . '/includes/transcoding.inc');


/**
 * Downloads the file from the specified absolute path using mod x-send, if it is installed,
 * else uses slightly slower PHP-native download (the old version of this function)
 * @return none
 */
function readFileFromPath($file, $transcodingType=null, $isDownload=true) {

	/*	$modules = apache_get_modules();
	 if (!in_array('mod_xsendfile', $modules)) {
		//mod x-send is not installed
		//printf("<PRE>%s.%s=[%s]</PRE>\n", __METHOD__, 'file', $file);
		return readFileFromPathOld($file, $transcodingType);
		}
		*/
	if (!empty($transcodingType)) {
		$transcodedFilePath = getTranscodedFilePath($file, $transcodingType);
		if ($transcodedFilePath == 400) {
			throw new Exception('INVALID_PARAMETER_VALUE', 400);
		}
		if (empty($transcodedFilePath)) {
			throw new Exception('FILE_NOT_FOUND', 404);
		}
		$file = $transcodedFilePath;
	}
	if (!file_exists($file)) {
		throw new Exception('FILE_NOT_FOUND', 404);
	}
	$ctype = mime_content_type($file);
	$filename = end(explode('/', $file));

	$dispositionType = $isDownload === 'true' ? 'attachment' : 'inline';

	header('X-Sendfile: ' . $file);
	header('Content-Type: ' . $ctype);
	header('Content-Disposition: ' . $dispositionType . "; filename*=UTF-8''".rawurlencode($filename));
}



/**
 * Downloads the file from the specified absolute path using mod x-send, if it is installed,
 * else uses slightly slower PHP-native download (the old version of this function)
 * @return none
 */
function readFileFromPathNew($shareName, $file, $transcodingType = NULL, $isDownload = TRUE, $isBlocking = TRUE)
{
	$fstatArray = fstatLfs($file);

	\Core\Logger::getInstance()->info('File Size: ' . $fstatArray['size']);

	$dispositionType = $isDownload ? 'attachment' : 'inline';

	//For Partial download, Lighttpd server works with X-Sendfile2, and when header 2.6 and content range is explicitly defined.
	//Since, this change is for Lighttpd only, we have to check for server name and process it.
	list($serverName, $version) = explode('/', $_SERVER['SERVER_SOFTWARE']);

	if ((isset($_SERVER['HTTP_RANGE']) && $serverName == 'lighttpd') &&
	    !preg_match('/Windows Mobile/', $_SERVER['HTTP_USER_AGENT']))
	{
		$range = substr($_SERVER['HTTP_RANGE'], 6);

		header('Content-Range: bytes ' . $range . '/' . $fstatArray['size']);
		header('HTTP/1.1 206 Partial content');
		header('X-Sendfile2: ' . rawurlencode($file) . ' ' . $range);
	}

	$ctype = mime_content_type($file) ?: mimeTypeHack($file);

	$transcodedBasePath = false;
	//\Core\Logger::getInstance()->debug("transcodingType: $transcodingType");
	if ((NULL !== $shareName) && (NULL !== $transcodingType))
	{
		list($file, $transcodedBasePath) = getTranscodedFilePathNew($shareName, $file, $transcodingType, $isBlocking);

		switch ($file)
		{
			case 412:
			    throw new Exception('FILE_NOT_FOUND', 412);
			case 400:
			    throw new Exception('INVALID_PARAMETER_VALUE', 400);
			case 404:
			    throw new Exception('FILE_NOT_FOUND', 404);
		}

		if (!file_exists($file))
		{
			throw new Exception('FILE_NOT_FOUND', 404);
		}

		header('Pragma: public');
		header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
		header('Cache-Control: private', FALSE);
	}
	else
	{
		header('Cache-Control: ');
		header('Pragma: ');
	}
	if ($shareName !== NULL){
        updatePendingAccelInfo($transcodedBasePath);
    }
    
	header('Content-Disposition: '. $dispositionType. "; filename*=UTF-8''".rawurlencode(basename($file)));
	header('Content-Type: ' . $ctype . '; charset=UTF-8');
	header('Content-Transfer-Encoding: binary');
	header('X-Sendfile: ' . $file);
	header('Expires: 0');
}

/**
 * Reads the file from the specified absolute path.  Accepts header options Content-Range and Content-Length.  Sets the mime-type.
 * @param $file the absolute path to the file to be read
 * @return none
 */
function readFileFromPathOld($shareName, $file, $transcodingType=null, $isDownload=true, $isBlocking = true) {

	if (!file_exists($file)) {
		throw new Exception('NOT_FOUND: File does not exist! ['.$file.']', 404);
	}

	if (isset($transcodingType)) {
		list($transcodedFilePath, ) = getTranscodedFilePathNew($shareName, $file, $transcodingType, $isBlocking);
		if ($transcodedFilePath == 400) {
			throw new Exception('INVALID_PARAMETER_VALUE', 400);
		}
		if (!isset($transcodedFilePath)) {
			throw new Exception('NOT_FOUND: Transcoded file not found! ['.$file.']', 404);
		}
		$file = $transcodedFilePath;
		if (!file_exists($file)) {
			throw new Exception('NOT_FOUND: Transcoded file does not exist! ['.$file.']', 404);
		}
	}
    setlocale(LC_ALL, "en_US.UTF-8");
	$filesize = trim(shell_exec("stat -c%s " . escapeshellarg($file)));
    $filename = basename($file);
	$file_ext = strtolower(substr(strrchr($filename,"."),1));

	$ctype = mime_content_type($file);

	/*
	 switch($file_ext) {
		case "avi" : $ctype = "video/x-msvideo"; break;
		case "exe" : $ctype = "application/octet-stream"; break;
		case "flv" : $ctype = "video/x-flv"; break;
		case "html": $ctype = "text/html"; break;
		case "jpg" : $ctype = "image/jpeg"; break;
		case "mp3" : $ctype = "audio/mp3"; break;
		case "mpg" : $ctype = "video/mpeg"; break;
		case "zip" : $ctype = "application/zip"; break;
		default    : $ctype = "application/force-download";
		} */

	//\Core\Logger::getInstance()->debug("HTTP_RANGE: $_SERVER['HTTP_RANGE']");
	if (isset($_SERVER['HTTP_RANGE'])) {
		$httpRange = $_SERVER['HTTP_RANGE'];
		//\Core\Logger::getInstance()->debug("HTTP_RANGE: $httpRange");
		if (!preg_match('^bytes=\d*-\d*(,\d*-\d*)*$', $_SERVER['HTTP_RANGE'])) {
        	header('HTTP/1.1 416 Requested Range Not Satisfiable');
        	header('Content-Range: bytes */' . filelength); // Required in 416.
        	throw new Exception('NOT_SATISFIABLE: Range start is greater than range end!', 416);
    	}
		
		// for current implementation, stripping out 'bytes='
		$ranges = explode(',', substr($_SERVER['HTTP_RANGE'], 6));
		
		//$httpRange = str_replace("bytes=", "", $httpRange);
		// http range can be multi part. bytes=0-100,900-1000
		//$ranges = explode(',', $httpRange);
		foreach ($ranges as $range) {
		    list($start, $end) = explode('-', $httpRange);
		    //\Core\Logger::getInstance()->debug("start: $start");
		    //\Core\Logger::getInstance()->debug("end: $end");
		    if ($start > $end) {
		        header('HTTP/1.1 416 Requested Range Not Satisfiable');
		        header('Content-Range: bytes */' . $filesize); // Required for 416.
		        throw new Exception('NOT_SATISFIABLE: Range start is greater than range end!', 416);
		    }
		}
		$contentLength = $end - $start + 1;
	} else {
	    $start = 0;
		$end = ($filesize != 0) ? $filesize - 1 : 0;
		$contentLength = $filesize;
	}
	$contentRange = $start."-".$end."/".$filesize;

	if ($start > $end) {
		throw new Exception('NOT_SATISFIABLE: Range start is greater than range end!', 416);
	}

	if ($start > $filesize - 1 && $filesize > 0) {
		throw new Exception('NOT_SATISFIABLE: Range start is greater than file length! ['.$filesize.']', 416);
	}

	$dispositionType = $isDownload ? 'attachment' : 'inline';
	//$aaa=rawurlencode($filename);
	header("Cache-Control:");
	header("Cache-Control: public");
	header("Content-Type: $ctype");
	header("Accept-Ranges: bytes");
	header("Content-Range: bytes ".$contentRange);
	//header("Content-Disposition: ". $dispositionType. "; filename*=UTF-8''".rawurlencode($filename));
	header("Content-Disposition: ". $dispositionType. "; filename*=UTF-8''"."\"$filename\"");
	header("Content-Length: ".$contentLength);
	

	//\Core\Logger::getInstance()->debug("filename: $filename");
	//$aaa=rawurlencode($filename);
	//\Core\Logger::getInstance()->debug("rawurlencode: $aaa");
	
	set_time_limit(0);
	$offset = $start;
	$maxChunkSize = 64 * 1024;
	$bytesRemaining = $contentLength;
	//set script execution time to unlimited so script will continue to run for huge file downloads
	set_time_limit(0);
	//\Core\Logger::getInstance()->debug("bytesRemaining: $bytesRemaining");
	while( $bytesRemaining > 0 ) {
		$chunkSize = ($bytesRemaining > $maxChunkSize)? $maxChunkSize : $bytesRemaining;
		$fileChunk = file_get_contents ( $file, NULL, NULL, $offset, $chunkSize );
		if (!$fileChunk && ($offset == $start)) {
			throw new Exception('INTERNAL_ERROR: Failed to get file contents! ['.$file.']', 500);
			set_time_limit(ini_get('max_execution_time'));
		}
		echo($fileChunk);
		$offset += $chunkSize;
		$bytesRemaining -= $chunkSize;
		flush();
	}
	ob_flush();
	set_time_limit(ini_get('max_execution_time'));
	return true;
}


?>
