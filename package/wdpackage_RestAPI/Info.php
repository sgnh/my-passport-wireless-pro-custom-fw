<?php

namespace Plex\Controller;

use Plex\Model;

/**
 * \class Info
 * \brief Returns an array of current and available update packages and immediately checks for any firmware update available.
 *
 * - This component extends the Rest Component.
 * - Supports xml and json formats for response data. Default format is xml.
 * - User need not be authenticated to use this component.
 *
 */
class Info {

    use \Core\RestComponent;

    const COMPONENT_NAME = 'plex_firmware_info';

    function get($urlPath, $queryParams = null, $outputFormat = 'xml') {
        
        $fwUInfoObj = new Model\Firmware();
        $fwStatus = $fwUInfoObj->getPlexFirmwareInfo();
        if ($fwStatus !== NULL) {
            $results = array('status' => $fwStatus);
            $this->generateSuccessOutput(200, 'firmware_info', $results, $outputFormat);
        } else {
            //Failed to collect info
            throw new \Core\Rest\Exception('FIRMWARE_INFO_INTERNAL_SERVER_ERROR', 500, NULL, self::COMPONENT_NAME);
        }
    }
    
    function put($urlPath, $queryParams = null, $outputFormat = 'xml') {
        $fwInfoObj = new Model\Firmware();
        $result = $fwInfoObj->modifyUpdateAvailable();

        switch ($result) {
            case 'SUCCESS':
                $results = array('status' => 'success');
                $this->generateSuccessOutput(200, 'query_firmware', $results, $outputFormat);
                break;
            //case 'SERVER_ERROR':
                //throw new \Core\Rest\Exception('FIRMWARE_INFO_INTERNAL_SERVER_ERROR', 500, NULL, self::COMPONENT_NAME);
        }
    }
}