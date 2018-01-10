<?php

namespace System\Reporting\System\Linux;

require_once(FILESYSTEM_ROOT . '/includes/db/volumesdb.inc');

class SystemUtil {

    /**
     * This Util class should be inside the Implementation class... It needs to refactored to be fixed.
     */

	public function getInfo() {
		$nasConfig = parse_ini_file('/etc/nas/config/wd-nas.conf', true);
		$systemConfig = parse_ini_file('/etc/system.conf', true);

		$success = false;

		$capacity = apc_fetch('capacity', $success);
	    // for testing, set success and serial number
        if  ('testing' == $_SERVER['APPLICATION_ENV']) {
            $success = true;
            $capacity = 1 * 1024 * 1024 * 1024;
        }
		if (!$success) {
			$diskTotalSpace = disk_total_space($nasConfig['global']['DATA_VOLUME']);
			if (isset($diskTotalSpace)) {
				//$size = ceil((float) $diskTotalSpace / 1024 / 1024 / 1024);
				//changed to base 10 computation
				$size = ceil((float) $diskTotalSpace / 1000 / 1000 / 1000);
				if($size < 950){
					if($size > 450)
						$capacity = '500GB';
					else
						$capacity = '250GB';
				} else {
					$size += 500;
					$remainder = $size % 1000;
					$whole = (int) ($size / 1000);
					if ($remainder > 550) {
						$capacity = $whole . '.5TB';
					} else {
						$capacity = $whole . 'TB';
					}
				}
				apc_store('capacity', $capacity);
			}
		}

		$serial_number = apc_fetch('serial_number', $success);
        // for testing, set success and serial number
        if  ('testing' == $_SERVER['APPLICATION_ENV']) {
            $success = true;
            $serial_number[0] = 'WXL1E61KEPM2';
        }
		if (!$success) {
			$retVal=null;
			exec_runtime("sudo /usr/local/sbin/getSerialNumber.sh", $serial_number, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getSerialNumber.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			if (isset($serial_number) && !empty($serial_number)) {
				apc_store('serial_number', $serial_number);
			}
		}

		unset($master_drive_serial_number);
		$master_drive_serial_number = apc_fetch('master_drive_serial_number', $success);

		//For testing Purpose
		if($_SERVER["APPLICATION_ENV"] == 'testing'){
			$master_drive_serial_number[0] = '1234';
			$success = true;
		}

		if (!$success) {
            $volumesDB = new \VolumesDB();
            $allVolumes = $volumesDB->getVolume();
            foreach($allVolumes as $allVolumesV){
                $master_drive_serial_number = array($allVolumesV['volume_id']);
                break;
            }
			
			if(isset($master_drive_serial_number)) {
    			apc_store('master_drive_serial_number',$master_drive_serial_number);
			} else {
                $master_drive_serial_number = array('');
            }
		}

		$mac_address = apc_fetch('mac_address', $success);
        // for testing, set success and mac address
        if  ('testing' == $_SERVER['APPLICATION_ENV']) {
            $success = true;
            $mac_address = 1;
        }
		if (!$success) {
			$retVal=null;
			exec_runtime("sudo /usr/local/sbin/getMacAddress.sh", $mac_address, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getMacAddress.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			apc_store('mac_address', $mac_address);
		}

		$uuid = apc_fetch('uuid', $success);
        // for testing, set success and uuid
        if  ('testing' == $_SERVER['APPLICATION_ENV']) {
            $success = true;
            $uuid = 1;
        }
		if (!$success) {
			$retVal=null;
			exec_runtime("sudo /usr/local/sbin/getUpnp_uuid.sh", $uuid, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getUpnp_uuid.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			apc_store('uuid', $uuid);
		}

        $hosts = file_get_contents('/etc/hosts');
        $pattern = "/^.*wd2go.com.*\$/m";
        // search, and store all matching occurences in $matches
        if(preg_match_all($pattern, $hosts, $matches)) {
           $wd2goServer = implode("\n", $matches[0]);
        }
        else{
           $wd2goServer = '';
        }
        $response = array(
				'manufacturer' => $systemConfig['manufacturer'],
				'manufacturer_url' => $systemConfig['manufacturerURL'],
				'model_description' => $systemConfig['modelDescription'],
				'model_name' => $systemConfig['modelName'],
				'model_url' => $systemConfig['modelURL'],
				'model_number' => $systemConfig['modelNumber'],
                'host_name' => gethostname(),
				'capacity' => $capacity,
				'serial_number' => $serial_number[0],
				'master_drive_serial_number' => $master_drive_serial_number[0],
				'mac_address' => $mac_address[0],
				'uuid' => $uuid[0],
				'wd2go_server' => $wd2goServer,
			);

		// optional components
		$dlna_server = apc_fetch('dlna_server', $success);
		if (!$success) {
			$retVal=null;
			exec_runtime("sudo /usr/local/sbin/getDlnaServer.sh", $dlna_server, $retVal);
			if($retVal == 0) {
    			apc_store('dlna_server', $dlna_server);
			}
		}

        if ( $dlna_server ) {
            $response['dlna_server'] = $dlna_server[0];
        }

		return $response;
	}

	public function getState() {
		$output = $retVal = null;

		if (is_file("/usr/local/sbin/getSystemState.sh")) {

			exec_runtime("sudo /usr/local/sbin/getSystemState.sh", $output, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getSystemState.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			$status = $output[0];
		} else {
			$status = "ready";
		}
        // for testing, return system state
        if  ('testing' == $_SERVER['APPLICATION_ENV']) {
            return( array(
				'status' => "ready",
		    ));
        }

		if (strcasecmp($status, "ready") === 0) {

			exec_runtime("sudo /usr/local/sbin/getTemperatureStatus.sh", $output, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getTemperatureStatus.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			$temperature = $output[0];

			exec_runtime("sudo /usr/local/sbin/getSmartStatus.sh", $output, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getSmartStatus.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			$smart = $output[0];

			exec_runtime("sudo /usr/local/sbin/getFreeSpaceStatus.sh", $output, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getFreeSpaceStatus.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			$free_space = $output[0];

			exec_runtime("sudo /usr/local/sbin/getVolumeStatus.sh", $output, $retVal);
			if ($retVal !== 0) {
				throw new \System\Reporting\Exception('"getVolumeStatus.sh" call failed. Returned with "' . $retVal . '"', 500);
			}
			$volume = $output[0];
		}

		$stateArr = array('status' => $status,
				'temperature' => $temperature,
				'smart' => $smart,
				'volume' => $volume,
				'free_space' => $free_space
		);
		$stateArr['reported_status'] = in_array('warn', array_values($stateArr)) ? 'warn' : 'good';
		$stateArr['reported_status'] = in_array('bad', array_values($stateArr)) ? 'bad' : $stateArr['reported_status'];
		$stateArr['reported_status'] = in_array('unknown', array_values($stateArr)) ? 'unknown' : $stateArr['reported_status'];
		
		return $stateArr;
	}

	public function getLog() {
        // for testing, set path to log
        if  ('testing' == $_SERVER['APPLICATION_ENV']) {
            return (array('path_to_log' => '/temp/file.zip'));
        }

	    //Create a file of all logs and return it/put it someplace where upper layer can get to it

		$output = $retVal = null;
		exec_runtime("sudo /usr/local/sbin/getSystemLog.sh", $output, $retVal);
		if ($retVal !== 0) {
            return NULL;
		}
		return (array('path_to_log' => $output[0]));
	}

	public function sendLog() {
		//Create a file of all logs and return it/put it someplace where upper layer can get to it

		$output = $retVal = null;
		exec_runtime("sudo /usr/local/sbin/sendLogToSupport.sh", $output, $retVal);
		if ($retVal !== 0) {
			return NULL;
		}
		if ($output[0] === 'server_connection_failed') {
			return (array('transfer_success' => "failed", 'logfilename' => ''));
		} else {
			return (array('transfer_success' => "succeeded", 'logfilename' => $output[0]));
		}
	}

}