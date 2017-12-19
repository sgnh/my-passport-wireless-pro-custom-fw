<?php

class SshConfiguration{

	var $enablessh = '';

	function SshConfiguraion() {

	}

	function getConfig(){
		//!!!This where we gather up response
		//!!!Return NULL on error

		$sshServiceOutput=$retVal=null;
		exec_runtime("sudo /usr/local/sbin/getServiceStartup.sh ssh", $sshServiceOutput, $retVal);
		if($retVal !== 0) {
			return NULL;
		}

		if ($sshServiceOutput[0] === 'enabled') {
			$sshService ="true";
		}
		else {
			$sshService ="false";
		}

		return $sshService;
	}

	function modifyConfig($queryParams){
		//Require entire representation and not just a delta to ensure a consistant representation
		if( !isset($queryParams["enablessh"]) ){
			return 'BAD_REQUEST';
		}

		//Verify changes are valid
		if(!$this->isValidServiceState($queryParams["enablessh"])){

			return 'BAD_REQUEST';
		}
		
		$sshServiceStateRequested = (strtolower($queryParams["enablessh"]) === 'true') ? 'enabled' : 'disabled';
		$sshServiceOutput=$retVal=null;
		exec_runtime("sudo /usr/local/sbin/getServiceStartup.sh ssh", $sshServiceOutput, $retVal);
		if($retVal !== 0) {
			return 'SERVER_ERROR';
		}
		
		$sshServicepasswd=null;
		$sshServicepasswd=$queryParams["pwdssh"];
		//\Core\Logger::getInstance()->debug("sshServicepasswd: $sshServicepasswd");
		// if the service is currently in the requested state then exit with sucess
		//if ($sshServiceStateRequested === $sshServiceOutput[0]){
		//	return 'SUCCESS';
		//}
		
		$sshServiceOutput=$retVal=null;
		exec_runtime("sudo /usr/local/sbin/setServiceStartup.sh ssh \"$sshServiceStateRequested\" \"$sshServicepasswd\"", $sshServiceOutput, $retVal);
		if($retVal !== 0) {
			return 'SERVER_ERROR';
		}
		return 'SUCCESS';
	}

	function isValidServiceState($serviceState){
		if ((strcasecmp($serviceState,'true') == 0) ||
		(strcasecmp($serviceState,'false') == 0)) {
			return TRUE;
		} else {
			return FALSE;
		}
	}
}