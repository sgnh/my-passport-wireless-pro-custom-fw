<?php
/*
   This script is a bridge from the AutoMounter Perl code to the Orion PHP code.
   Copyright (c) [2011-2013] Western Digital Technologies, Inc. All rights reserved.
*/

// Constants

define("RETURN_CODE_SUCCESS", 0);
define("RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS", 1);
define("RETURN_CODE_FAILURE_INVALID_REQUEST", 2);
define("RETURN_CODE_FAILURE_EXCEPTION", 3);
define("RETURN_CODE_FAILURE_REQUEST_FAILED", 4);
define('ADMIN_API_ROOT', realpath('/var/www/rest-api/'));

// Required Files

require(ADMIN_API_ROOT . '/api/Core/init_autoloader.php');

$moduleManager->loadModule('Shares');
$moduleManager->loadModule('Filesystem');

require_once(FILESYSTEM_ROOT . '/includes/db/volumesdb.inc');
require_once(SHARES_ROOT . '/includes/shareaccess.inc');
require_once(SHARES_ROOT . '/includes/db/usersharesdb.inc');

$returnCode = RETURN_CODE_SUCCESS;

/*
    If the request argument wasn't specified, fail the request.
*/

if ($argc < 2) {
    $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
}
else {
    $_SERVER['REMOTE_ADDR'] = 'Internal';
    putenv("INTERNAL_REQUEST=true");
    $request = $argv[1];

    /*
        Create a share with the command line arguments: share_name, description, public_access,
        media_serving, volume_id, capacity, read_only, usb_handle, file_system_type.
    */

    if ($request == 'createShare') {
        if ($argc != 11) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            try {
                $shareManager = \Shares\Manager::getManager();
                $public_access = $argv[4] == 'true' ? true : false;
                $read_only = $argv[8] == 'true' ? true : false;
                $shareManager->create($argv[2], array('description' => $argv[3],
                                      'public_access' => $public_access, 'media_serving' => $argv[5],
                                      'volume_id' => $argv[6], 'capacity' => $argv[7],
                                      'read_only' => $read_only, 'usb_handle' => $argv[9],
                                      'file_system_type' => $argv[10], 'dynamic_volume' => true,
                                      'remote_access' => false, 'username' => 'admin'));
            } catch (\Exception $exception) {
                system("logger -p local2.err \"ERR: Exception creating share $argv[2] - $exception\"");
                $returnCode = RETURN_CODE_FAILURE_EXCEPTION;
            }
        }
    }

    /*
        Delete a share specifying only the shareName.
    */

    elseif ($request == 'deleteShare') {
        if ($argc != 3) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            try {
                $shareManager = \Shares\Manager::getManager();
                $share = $shareManager->delete($argv[2]);
            } catch (\Exception $exception) {
                system("logger -p local2.err \"ERR: Exception deleting share $argv[2] - $exception\"");
                $returnCode = RETURN_CODE_FAILURE_EXCEPTION;
            }
        }
    }

    /*
       Delete all USB related shares.  This is only done when the auto-mount service is started.
       There are only USB shares at this point if the system had been powered off while USB drives
       were connected (without going through an orderly shutdown).
    */

    elseif ($request == 'deleteDynamicShares') {
        if ($argc != 2) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            $shareDb = new UserSharesDB();
            if (!$shareDb->deleteDynamicVolumeShares())
                $returnCode = RETURN_CODE_FAILURE_REQUEST_FAILED;
        }
    }

    /*
        Create access to a share with the arguments: shareName, username, and accessLevel.
    */

    elseif ($request == 'createAccess') {
        if ($argc != 5) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            try {
                $shareAccessManager = \Shares\Manager\Access::getManager();
                $shareAccessManager->create($argv[2], $argv[3], $argv[4]);
            } catch (\Shares\Exception $e) {
                system("logger -p local2.err \"ERR: Exception creating share access for $argv[2], $argv[3] - $exception\"");
                $returnCode = RETURN_CODE_FAILURE_EXCEPTION;
            }
        }
    }

    /*
       Create a volume with the following arguments: volumeId, label, basePath, drivePath,
       isConnected, capacity, fileSystemType, readOnly, usbHandle, mountTime.  Note: dynamicVolume
       is always set to true and crawlerStatus is always set to null.
    */

    elseif ($request == 'createVolume') {
        if ($argc != 12) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            $volumesDB = new VolumesDB();
            if (!$volumesDB->createVolume($argv[2], $argv[3], $argv[4], $argv[5], $argv[6], $argv[7],
                                          'true', $argv[8], $argv[9], $argv[10], null, $argv[11]))
                $returnCode = RETURN_CODE_FAILURE_REQUEST_FAILED;
        }
    }

    /*
       Update a volume with the following arguments: volumeId, label, basePath, drivePath,
       isConnected, capacity, fileSystemType, readOnly, usbHandle, mountTime.  Note: dynamicVolume
       is always set to true and crawlerStatus is always set to null.
    */

    elseif ($request == 'updateVolume') {
        if ($argc != 12) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            $volumesDB = new VolumesDB();
            if (!$volumesDB->updateVolume($argv[2], $argv[3], $argv[4], $argv[5], $argv[6], $argv[7],
                                          'true', $argv[8], $argv[9], $argv[10], null, $argv[11]))
                $returnCode = RETURN_CODE_FAILURE_REQUEST_FAILED;
        }
    }

    /*
        Delete a volume.
    */

    elseif ($request == 'deleteVolume') {
        if ($argc != 3) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            $volumesDB = new VolumesDB();
            if (!$volumesDB->deleteVolume($argv[2]))
                $returnCode = RETURN_CODE_FAILURE_REQUEST_FAILED;
        }
    }

    /*
        Get volume IDs.
    */

    elseif ($request == 'getVolumeIds') {
        if ($argc != 2) {
            $returnCode = RETURN_CODE_FAILURE_INCORRECT_NUMBER_OF_ARGUMENTS;
        }
        else {
            $volumesDB = new VolumesDB();
            $volumes = $volumesDB->getVolume();
            foreach ($volumes as $volume) {
                $volumeId = $volume['volume_id'];
                    print("$volumeId\n");
            }
        }
    }
    else {
        $returnCode = RETURN_CODE_FAILURE_INVALID_REQUEST;
    }
}

exit($returnCode);

