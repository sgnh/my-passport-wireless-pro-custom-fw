<?php

namespace Storage\Transfer\Controller;

use Storage\Transfer\Model;

/**
 * \file StorageTransfer.php
 * \author WD
 * \copyright Copyright (c) 2012, Western Digital Corp. All rights reserved.
 */

/**
 * \class StorageTransfer
 * \brief Used for saving and retrieving the storage configuration.
 *
 * - This component extends the Rest Component.
 * - Supports xml and json formats for response data. Default format is xml.
 * - User must be authenticated to use this component.
 *
 */
class StorageTransfer {

    use \Core\RestComponent;

    const COMPONENT_NAME = 'storage_transfer';
    /**
     * \par Description:
     * Returns the storage transfer configuration properties.
     *
     * \par Security:
     * - Admin authentication is required.
     *
     * \par HTTP Method: GET
     * - http://localhost/api/@REST_API_VERSION/rest/storage_transfer/{storage_type}
     *
     * \param format    String   - optional (default is xml)
     * \param storage_type         String   - optional{usb/sdcard} - If not passed then config details for both usb and sdcard will be returned
     *
     * \retval storage_configuration - storage transfer configuration properties for each storage type
     * auto_transfer:  true/false
     * transfer_mode:  copy/move
     *
     * \par HTTP Response Codes:
     * - 200 - On successful return of the configuration location and/or configuration file.
     * - 400 - Bad request, if parameter or request does not correspond to the api definition
     * - 401 - User is not authorized
     * - 403 - Request is forbidden
     * - 404 - Requested resource not found
     * - 500 - Internal server error
     *
     * \par Error Codes:
     * - 146  - SYSTEM_CONFIGURATION_INTERNAL_ERROR - System configuration internal server error.
     *
     * \par XML Response Example:
     * \verbatim
     *  <storage_transfer>
     *    	<sdcard>
     *          <auto_transfer>false</auto_transfer>
     *          <transfer_mode>copy</transfer_mode>
     *      </sdcard>
     *      <usb>
     *          <auto_transfer>false</auto_transfer>
     *          <transfer_mode>copy</transfer_mode>
     *      </usb>
     *  </storage_transfer>
     * \endverbatim
     */
    public function get($urlPath, $queryParams = null, $outputFormat = 'xml') {

        if(isset($urlPath[0]) & in_array(strtolower($urlPath[0]), ['usb', 'sdcard'])){
            $storage=strtolower($urlPath[0]);
        }

    	$storageTransfer = new Model\StorageTransfer();

    	try {
    		$results = $storageTransfer->getStorageConfiguration($storage);
    	} catch (\Storage\Transfer\Exception $e) {
    		throw new \Core\Rest\Exception('STORAGE_TRANSFER_INTERNAL_SERVER_ERROR', 500, null, self::COMPONENT_NAME);
    	}

    	if(empty($results) || !(array_key_exists('usb', $results) || array_key_exists('sdcard', $results))){
    	    throw new \Core\Rest\Exception('STORAGE_TRANSFER_GET_ERROR', 500, null, self::COMPONENT_NAME);
    	}

    	$output = new \OutputWriter(strtoupper($outputFormat));
       	$output->pushElement(self::COMPONENT_NAME);

       	foreach($results as $device=>$config){
       	    if($device == 'usb' || $device == 'sdcard'){
       	        $output->pushElement($device);
       	        $output->element('auto_transfer', $config[0]);
       	        $output->element('transfer_mode', $config[1]);
       	        $output->popElement();
       	    }
       	}
       	$output->popElement();
       	$output->close();
    }

    /**
     * \par Description:
     * Used to update the storage transfer configuration properties.
     *
     * \par Security:
     * - Requires Admin User authentication and request is from LAN only.
     *
     * \par HTTP Method: POST
     * - http://localhost/api/@RST_API_VERSION/rest/storage_transfer/{storage_type}
     *
     * \param storage_type         String   - Required{usb/sdcard}
     * \param auto_transfer        Boolean  - conditionally required {true/false}
     * \param transfer_mode        String   - conditionally required {move/copy}
     *
     * \par Parameter Details
     * - storage_type - Will describe the type of external storage whose settings needs to be updated. Value of this parameter can be 'usb' or 'sdcard'
     * - auto_transfer - Type of content transfer(true/false).
     * - transfer_mode - Mode of content transfer(copy/move).
     *
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
     * - 146  - SYSTEM_CONFIGURATION_INTERNAL_ERROR - System configuration internal server error.
     * - 147  - SYSTEM_CONFIGURATION_BAD_REQUEST - System configuration bad request.
     *
     * \par XML Response Example:
     * \verbatim
      <storage_transfer>
      	<status>SUCCESS</status>
      </storage_transfer>
      \endverbatim
     */
    public function put($urlPath, $queryParams = null, $outputFormat = 'xml') {

    	$storageTransfer = new Model\StorageTransfer();

    	if (!isset($queryParams['auto_transfer']) && !isset($queryParams['transfer_mode'])) {
    		throw new \Core\Rest\Exception('STORAGE_TRANSFER_BAD_REQUEST', 400, null, self::COMPONENT_NAME);
    	}

    	if (isset($queryParams["auto_transfer"]) && !((strcasecmp($queryParams["auto_transfer"],'true') == 0) || (strcasecmp($queryParams["auto_transfer"],'false') == 0))) {
    		throw new \Core\Rest\Exception('STORAGE_TRANSFER_BAD_REQUEST', 400, null, self::COMPONENT_NAME);
    	}

    	if (isset($queryParams["transfer_mode"]) && !((strcasecmp($queryParams["transfer_mode"],'move') == 0) || (strcasecmp($queryParams["transfer_mode"],'copy') == 0)
    	 || (strcasecmp($queryParams["transfer_mode"],'copy_all') == 0))) {
    		throw new \Core\Rest\Exception('STORAGE_TRANSFER_BAD_REQUEST', 400, null, self::COMPONENT_NAME);
    	}
        $storage=strtolower($urlPath[0]);
    	if(!isset($urlPath[0]) & !in_array($storage, ['usb', 'sdcard'])){
    	    throw new \Core\Rest\Exception('STORAGE_TRANSFER_BAD_REQUEST', 400, null, self::COMPONENT_NAME);
    	}
    	$queryParams['storage_type'] = $storage;
    	try {
    		$storageTransfer->updateStorageConfiguration($queryParams);
    	} catch (\Storage\Transfer\Exception $e) {
    		throw new \Core\Rest\Exception('STORAGE_TRANSFER_INTERNAL_SERVER_ERROR', 500, null, self::COMPONENT_NAME);
    	}
    	$this->generateSuccessOutput(200, self::COMPONENT_NAME, array('status' => 'Success'), $outputFormat);

    }

}