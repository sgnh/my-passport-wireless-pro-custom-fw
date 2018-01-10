<?php

namespace Plex\Model;

class Firmware {

    public function modifyUpdateAvailable() {

        //Actually do change
        $output=$retVal=null;
        exec_runtime("sudo /usr/local/sbin/getNewPlexFirmwareUpgrade.sh immediate", $output, $retVal);
        if ($retVal !== 0) {
            return 'SERVER_ERROR';
        }

        return 'SUCCESS';
    }
    
    public function getPlexFirmwareInfo() {

        $output=$retVal=null;
        $retVal = file_get_contents('/tmp/plexfw_upgrade_info', true);
       
        return $retVal;
    }
}

