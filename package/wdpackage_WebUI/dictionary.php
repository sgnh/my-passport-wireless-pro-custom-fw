<?php
    include_once('../lib/language.php');
    //include_once('../lib/device_description.php');
    //include_once('../lib/system_information.php');
    include_once('./../views/common/languages.php');

    $language = new Language();
    $languageStr = $language->getLanguage();
    setlocale(LC_ALL, $languageStr.".UTF-8");
    bindtextdomain("default", "../locale");
    textdomain("default");

    if(isset($langMap[$languageStr])){
        $Language3Letter = $langMap[$languageStr];
    }
    else{
        $Language3Letter = 'eng';
    }		

    /*
    $device_description = new DeviceDescription();
    $deviceName = $device_description->getDeviceName();
    $deviceDescription = $device_description->getDeviceDescription();

    $system_information = new SystemInformation();
    $modelName = $system_information->getModelName();
    $modelNumber = $system_information->getModelNumber();
    $serialNumber = $system_information->getSerialNumber();
    $MACAddress = $system_information->getMACAddress(); 
    */ 

    // global variable initialization
    //echo "gDeviceName = \"".$deviceName."\";\n";
    //echo "gDeviceDescription = \"".$deviceDescription."\";\n";
    echo "gIPAddress = \"".$_SERVER['SERVER_ADDR']."\";\n";
    //echo "gModelName = \"".$modelName."\";\n";
    //echo "gModelNumber = \"".$modelNumber."\";\n";
    //echo "gSerialNumber = \"".$serialNumber."\";\n";

    $gRemoteIp=$_SERVER['REMOTE_ADDR'];
    $MACAddress_string = shell_exec("arp -i br0 -a $gRemoteIp");
    $MACAddress_array = explode(" ",$MACAddress_string);
    $MACAddress = $MACAddress_array[3];
    echo "test1 = \"".$MACAddress_array[3]."\";\n";
    echo "gRemoteMacAddress = \"".$MACAddress."\";\n";
    echo "gRemoteAddr = \"".$gRemoteIp."\";\n";
    
    
    echo "gLanguage = \"".$languageStr."\";\n";
    echo "gLanguage3Letter = \"".$Language3Letter."\";\n";
    echo "gDateTime = ".time().";\n";


    $dictionary = array();

    $dictionary['labelgenericKBtxt'] = _("GENERIC_KB");
	$dictionary['labelgenericMBtxt'] = _("GENERIC_MB");
	$dictionary['labelgenericGBtxt'] = _("GENERIC_GB");
    $dictionary['labelgenericTBtxt'] = _("GENERIC_TB");

    /* Legacy Sequoia
    $dictionary['statusdisabledtxt'] =                  _("LABEL_STATUS_DISABLED");
    $dictionary['statusreadytxt'] =                     _("LABEL_STATUS_READY");
    $dictionary['statusportforwardedtxt'] =             _("LABEL_STATUS_PORTFORWARDED");
    $dictionary['statusrelayedtxt'] =                   _("LABEL_STATUS_RELAYED");
    $dictionary['statusfailedtxt'] =                    _("LABEL_STATUS_FAILED");
    $dictionary['statusconnectingtxt'] =                _("LABEL_STATUS_CONNECTING");
    $dictionary['statusdisconnectingtxt'] =             _("CONTENT_SETTINGS_STRING_DISCONNECTING");
    $dictionary['statusdisabledexplainedtxt'] =         _("CONTENT_CLOUD_ACCESS_STRING_CLOUD_ACCESS_DISABLED_EXPLANATION");
    $dictionary['statusdisabledexplained2txt'] =        _("CONTENT_CLOUD_ACCESS_STRING_CLOUD_ACCESS_DISABLED_EXPLANATION_2");
    $dictionary['statusreadyexplainedtxt'] =            _("LABEL_STATUS_READY_EXPLANATION");
    $dictionary['statusportforwardedexplainedtxt'] =    _("LABEL_STATUS_PORTFORWARDED_EXPLANATION");
    $dictionary['statusrelayedexplainedtxt'] =          _("LABEL_STATUS_RELAYED_EXPLANATION");

    $dictionary['statusmanualrelayedexplainedtxt_part1'] = _("CONTENT_SETTINGS_DIALOG_STRING_MANUAL_RELAYED_EXPLANATION_PART1");
    $dictionary['statusmanualrelayedexplainedtxt_part2'] = _("CONTENT_SETTINGS_DIALOG_STRING_MANUAL_RELAYED_EXPLANATION_PART2");
    */

    /* Legacy Sequoia
    $dictionary['statusfailedexplainedtxt'] =           _("LABEL_STATUS_FAILED_EXPLANATION");
    $dictionary['statusconnectingexplainedtxt'] =       _("LABEL_STATUS_CONNECTING_EXPLANATION");
    $dictionary['statusretrievingtxt'] =                _("LABEL_STATUS_RETRIEVING_INFORMATION");
    $dictionary['waitingtxt'] =                         _("LABEL_CODE_WAITING");
    $dictionary['waitingtooltiptxt'] =                  _("TOOLTIP_REMOTE_ACCESS_DAC_WAITING");
    $dictionary['expiredtxt'] =                         _("CONTENT_CLOUD_ACCESS_STRING_EXPIRED");
    $dictionary['expiredtooltiptxt'] =                  _("TOOLTIP_REMOTE_ACCESS_DAC_EXPIRED");
    $dictionary['connectedtxt'] =                       _("LABEL_MOBILE_DEVICE_CONNECTED");
    $dictionary['connectivitymanualtxt'] =              _("LABEL_MANUAL");
    $dictionary['expirestxt'] =                         _("CONTENT_CLOUD_ACCESS_STRING_EXPIRES");
    */

    $dictionary['loadingtxt'] =                         _("LABEL_DESCR_LOADER_UPDATING");
    $dictionary['retrievingtxt'] =                      _("GENERIC_LABEL_DESCR_RETRIEVE");

    /* Legacy Sequoia
    $dictionary['NewUnregisteredDeviceTxt'] =        _("CONTENT_CLOUD_ACCESS_STRING_NEW_UNREGISTERED_DEVICE");

    $dictionary['CalendarTxt'] =    _("CONTENT_SETTINGS_DIALOG_BUTTON_CALENDAR"); 
    */ 

    $dictionary['Januarytxt'] =     _("GENERIC_MONTH_JANUARY");
    $dictionary['Februarytxt'] =    _("GENERIC_MONTH_FEBRUARY");
    $dictionary['Marchtxt'] =       _("GENERIC_MONTH_MARCH");
    $dictionary['Apriltxt'] =       _("GENERIC_MONTH_APRIL");
    $dictionary['Maytxt'] =         _("GENERIC_MONTH_MAY");
    $dictionary['Junetxt'] =        _("GENERIC_MONTH_JUNE");
    $dictionary['Julytxt'] =        _("GENERIC_MONTH_JULY");
    $dictionary['Augusttxt'] =      _("GENERIC_MONTH_AUGUST");
    $dictionary['Septembertxt'] =   _("GENERIC_MONTH_SEPTEMBER");
    $dictionary['Octobertxt'] =     _("GENERIC_MONTH_OCTOBER");
    $dictionary['Novembertxt'] =    _("GENERIC_MONTH_NOVEMBER");
    $dictionary['Decembertxt'] =    _("GENERIC_MONTH_DECEMBER");

    /* Legacy Sequoia
    $dictionary['Suntxt'] = _("CONTENT_SETTINGS_STRING_SUN");
    $dictionary['Montxt'] = _("CONTENT_SETTINGS_STRING_MON");
    $dictionary['Tuetxt'] = _("CONTENT_SETTINGS_STRING_TUE");
    $dictionary['Wedtxt'] = _("CONTENT_SETTINGS_STRING_WED");
    $dictionary['Thutxt'] = _("CONTENT_SETTINGS_STRING_THU");
    $dictionary['Fritxt'] = _("CONTENT_SETTINGS_STRING_FRI");
    $dictionary['Sattxt'] = _("CONTENT_SETTINGS_STRING_SAT");
    */ 

    $dictionary['Sundaytxt'] =    _("LABEL_DESCR_SUNDAY");
    $dictionary['Mondaytxt'] =    _("LABEL_DESCR_MONDAY");
    $dictionary['Tuesdaytxt'] =   _("LABEL_DESCR_TUESDAY");
    $dictionary['Wednesdaytxt'] = _("LABEL_DESCR_WEDNESDAY");
    $dictionary['Thursdaytxt'] =  _("LABEL_DESCR_THURSDAY");
    $dictionary['Fridaytxt'] =    _("LABEL_DESCR_FRIDAY");
    $dictionary['Saturdaytxt'] =  _("LABEL_DESCR_SATURDAY");

    $dictionary['AM'] =  _("LABEL_DESCR_TIME_AM");
    $dictionary['PM'] =  _("LABEL_DESCR_TIME_PM");

    $dictionary['labeldrivetxt'] =          _("LABEL_DRIVE");
    $dictionary['labelfaileddiagtesttxt'] = _("LABEL_FAILED_DIAGNOSTIC_TEST");

    $dictionary['FreeSpaceTxt'] = _('CONTENT_HOME_BIG_BOX_STRING_FREE');
    $dictionary['VideosTxt'] = _('LABEL_DESCR_MEDIA_SERVING_VIDEOS');
    $dictionary['MusicTxt'] = _('CONTENT_HOME_DIALOG_LABEL_MUSIC');
    $dictionary['PhotosTxt'] = _('LABEL_DESCR_MEDIA_SERVING_PHOTOS');
    $dictionary['OtherTxt'] = _('CONTENT_HOME_DIALOG_LABEL_OTHER');
    
    /* Legacy Sequoia
    $dictionary['Initializing'] = _('CONTENT_HOME_STRING_INITIALIZING');
    //$dictionary['Sick'] = _('CONTENT_HOME_STRING_SICK');
    $dictionary['Healthy'] = _('STATUS_HEALTHY');
    $dictionary['Warning'] = _('GLOB_NAV_NOTIFICATIONS_LABEL_WARNING');
    $dictionary['Critical'] = _('GLOB_NAV_NOTIFICATIONS_LABEL_CRITICAL');
    
    $dictionary['good'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_GOOD');
    $dictionary['bad'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_BAD');
	$dictionary['mounted'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_MOUNTED');
	$dictionary['notMounted'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_NOT_MOUNTED');
	$dictionary['statusOK'] = _('BUTTON_OK');
	$dictionary['statusFailed'] = _('LABEL_STATUS_FAILED');
	$dictionary['statusNormal'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_NORMAL');
	$dictionary['statusOvertemp'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_OVERHEATED');
    $dictionary['statusTempWarning'] = _('GLOB_NAV_NOTIFICATIONS_LABEL_WARNING');
	$dictionary['sufficient'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_SUFFICIENT');
	$dictionary['lowFreeSpace'] = _('CONTENT_HOME_DIALOG_STRING_DIAGNOSIS_LOW_FREE_SPACE');
    */

    $dictionary['idle'] = _('CONTENT_HOME_STRING_IDLE');
    $dictionary['error'] = _('CONTENT_HOME_STRING_ERROR');
    $dictionary['unknown'] = _('ERROR_ID_0'); 
    $dictionary['_unknown'] = '-';
    
    /* Legacy Sequoia
    $dictionary['mediaScanInProgress'] = _('CONTENT_HOME_DIALOG_STRING_MEDIA_SCAN_IN_PROGRESS');
    
    $dictionary['rw'] = _('CONTENT_GENERIC_STRING_RW_ACCESS');
    $dictionary['ro'] = _('CONTENT_GENERIC_STRING_RO_ACCESS');
    $dictionary['no'] = _('CONTENT_GENERIC_STRING_NO_ACCESS');
    $dictionary['public'] = _('CONTENT_GENERIC_STRING_PUBLIC');
    */ 
    
    /* Legacy Sequoia
    $dictionary['gettingStartedWizardTitle'] = _('GLOB_NAV_HELP_DIALOG_TITLE_GETTING_STARTED'); 
    */ 

    /* Legacy Sequoia*/ 
    $dictionary['FreeOfTxt'] = _("GLOB_NAV_USB_STRING_FREE_OF");
    $dictionary['DriveLockedTxt'] = _("GLOB_NAV_USB_STRING_DRIVE_LOCKED"); 
    $dictionary['copyingfilesprogress'] = _("CONTENT_SETTINGS_STRING_COPYING_FILES");
    $dictionary['copyingfilesfailed'] = _("CONTENT_SETTINGS_STRING_COPYING_FILES_FAILED");
    $dictionary['copyingfilescompleted'] = _("CONTENT_SETTINGS_STRING_ALL_FILES_COPIED");
    $dictionary['ejectExternalDeviceTitle'] = _("HEADING_EJECT_USB");
    $dictionary['ejectExternalDeviceHeader'] = _("LABEL_DESCR_EJECT_USB");

	$dictionary['NoAlertsTxt'] = _('GLOB_NAV_NOTIFICATIONS_STRING_NO_NOTIFICATIONS_FOUND_AVATAR');
	$dictionary['NoCritWarnAlertsTxt'] = _('GLOB_NAV_NOTIFICATIONS_STRING_NO_CRIT_WARN_NOTIFICATIONS_FOUND');
	$dictionary['NoCritAlertsTxt'] = _('GLOB_NAV_NOTIFICATIONS_STRING_NO_CRIT_NOTIFICATIONS_FOUND');
	
    /* Legacy Sequoia
	$dictionary['safepointTitleCreate'] = _('CONTENT_SAFEPOINTS_DIALOG_TITLE_CREATE_SAFEPOINT');
	$dictionary['safepointTitleRecover'] = _('CONTENT_SAFEPOINTS_DIALOG_TITLE_RECOVER_SAFEPOINT');
	//$dictionary['safepointNasDiscoverTimeout'] = _('CONTENT_SAFEPOINTS_DIALOG_LABEL_NAS_TIMEOUT_ERROR');
	$dictionary['safepointUSBDiscover'] = _('CONTENT_SAFEPOINTS_LABEL_SEARCHING_FOR_USB_DEVICES');
	$dictionary['safepointNASDiscover'] = _('LABEL_SCANNING_YOUR_NETWORK_FOR_DEVICES');
	$dictionary['safepointGettingPartitions'] = _('CONTENT_SAFEPOINTS_DIALOG_LABEL_GETTING_PARTITIONS');

	$dictionary['safepointGettingShares'] = _('CONTENT_SAFEPOINTS_DIALOG_LABEL_GETTING_SHARES');
	$dictionary['safepointSelectADevice'] = _('LABEL_SELECT_A_DEVICE');
	
    $dictionary['safepointSelectADrive'] = _('LABEL_SELECT_A_DRIVE'); 
    */ 

	
	$dictionary['on'] = _('CONTENT_GENERIC_TOGGLE_MIXED_CASE_ON');
	$dictionary['off'] = _('CONTENT_GENERIC_TOGGLE_MIXED_CASE_OFF');

    /* Legacy Sequoia
    $dictionary['model_number_sq'] = 'WD My Cloud\u2122';
    $dictionary['model_number_sqwifi'] = 'WD My Cloud\u2122 WiFi';
    $dictionary['model_number_AP2NC'] = 'MY BOOK\u00AE LIVE\u2122 DUO';
    */
    //$dictionary['model_number_AV1W'] = 'My Passport\u00AE Wireless';
    $dictionary['model_number_WDBLJT'] = 'My Passport\u00AE Wireless';
    $dictionary['model_number_WDBK8Z'] = 'My Passport\u00AE Wireless';
    $dictionary['model_number_WDBDAF'] = 'My Passport\u00AE Wireless';
    $dictionary['default_ssid'] = 'MyPassport';

    /* Legacy Sequoia
    $dictionary['generic_media_receiver'] = _('CONTENT_SETTINGS_STRING_GENERIC_MEDIA_RECEIVER'); 
    */ 

    $dictionary['system_only_factory_restore_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE_SYSTEM_ONLY_FACTORY_RESTORE');
    $dictionary['quick_factory_restore_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE__SYSTEM_AND_DISK_RESTORE');
    //$dictionary['full_factory_restore_title'] = _('LABEL_DESCR_FULL_FACTORY_RESTORE');

    $dictionary['DHCP'] = _('CONTENT_SETTINGS_NETWORK_BUTTON_DHCP');     // 'DHCP';
	$dictionary['Static'] = _('CONTENT_SETTINGS_NETWORK_BUTTON_STATIC');      //'Static';

    $dictionary['begin_update'] = _('CONTENT_DIALOG_ALERTS_STRING_BEGIN_UPDATE');
    $dictionary['releasenotestxt'] = _('CONTENT_SETTINGS_LINK_RELEASE_NOTES');
    $dictionary['install_update'] = _('CONTENT_SETTINGS_BUTTON_INSTALL_UPDATE');
    $dictionary['learnMoreTxt'] = _('CONTENT_SETTINGS_DIALOG_STRING_LEARN_MORE');

    $dictionary['nonetxt'] = _('LABEL_DESCR_MEDIA_SERVING_NONE');
    $dictionary['freetxt'] = _('CONTENT_HOME_BIG_BOX_STRING_FREE');

    $dictionary['noInternetAccess'] = _('CONTENT_SETTINGS_NETWORK_STRING_NO_INTERNET_ACCESS');

    /* Legacy Sequoia
    $dictionary['scanning'] = _('CONTENT_HOME_STRING_SCANNING');
    $dictionary['videos_scanned'] = _('CONTENT_HOME_DIALOG_TOOLTIP_VIDEOS_SCANNED');
    $dictionary['music_scanned'] = _('CONTENT_HOME_DIALOG_TOOLTIP_MUSIC_SCANNED');
    $dictionary['photos_scanned'] = _('CONTENT_HOME_DIALOG_TOOLTIP_PHOTOS_SCANNED');
    $dictionary['other_scanned'] = _('CONTENT_HOME_DIALOG_TOOLTIP_OTHERS_SCANNED');
    */ 
    
    $dictionary['header_license_agreement'] = _('PAGE_HEADER_2_LICENSE_AGREEMENT');
    $dictionary['header_privacy_center'] = _('CONTENT_SETTINGS_LINK_PRIVACY_POLICY');
    

    //$dictionary['building'] = _('CONTENT_HOME_STRING_BUILDING');
    $dictionary['scanning_inprogress'] = _('CONTENT_DIALOG_STRING_SCANNING_IN_PROGRESS');
    $dictionary['building_inprogress'] = _('CONTENT_DIALOG_STRING_BUILDING_IN_PROGRESS');
    //$dictionary['additional_transcoding_inprogress'] = _('CONTENT_DIALOG_STRING_BUILDING_MORE_THUMBNAIL');
    $dictionary['building_preview_images'] = _('CONTENT_DIALOG_STRING_BUILDING_PREVIEW_IMAGES');
        
    $dictionary['splashAuthenticate'] = _('CONTENT_SPLASH_STRING_AUTHENTICATE_AVATAR');
    $dictionary['splashConfiguration'] = _('CONTENT_SPLASH_STRING_CONFIGURATION_AVATAR');
    

    $dictionary['battery_status_state_charging'] = _('CONTENT_SETTINGS_STRING_CHARGING');
    $dictionary['battery_status_state_discharging'] = _('CONTENT_SETTINGS_STRING_DISCHARGING');

    $dictionary['totalTxt'] = _('GENERIC_LABEL_TOTAL');

    $dictionary['copy_now'] = _('CONTENT_SETTINGS_STRING_COPY_NOW');
    $dictionary['move_now'] = _('CONTENT_SETTINGS_STRING_MOVE_NOW');
    $dictionary['copy_all_now'] = _('CONTENT_SETTINGS_STRING_COPY_ALL_NOW');
    $dictionary['copy_new_now'] = _('CONTENT_SETTINGS_STRING_COPY_NEW_NOW');

    $dictionary['trusted_network'] = _('CONTENT_SETTINGS_TITLE_HOME_NETWORK');
    $dictionary['untrusted_network'] = _('CONTENT_SETTINGS_TITLE_NETWORK_HOTSPOT');

    $dictionary['title_error'] = _('GLOB_NAV_DIALOG_TITLE_ERROR');
    $dictionary['title_invalid_password'] = _('ERROR_DIALOG_TITLE_INVALID_PASSWORD');
    $dictionary['title_mismatch_password'] = _('ERROR_DIALOG_TITLE_PASSWORD_MISMATCH');

    $dictionary['title_invalid_ssid_and_password'] = _('ERROR_DIALOG_TITLE_INVALID_SSID_AND_PASSWORD');
    $dictionary['title_invalid_ssid_name'] = _('ERROR_DIALOG_TITLE_INVALID_SSID_NAME');

    $dictionary['Me'] = _('CONTENT_SETTINGS_STRING_ME');
    $dictionary['sign_in_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE_SIGN_IN_TO');
    $dictionary['connecting_to_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE_CONNECTING_TO');
    $dictionary['unable_to_connect_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE_UNABLE_TO_CONNECT_TO');
    $dictionary['other_network'] = _('CONTENT_SETTINGS_LABEL_OTHER');

    $dictionary['modify_wifi_network_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE_MODIFY');
    $dictionary['modifying_wifi_network_title'] = _('CONTENT_SETTINGS_DIALOG_TITLE_MODIFYING');

    $dictionary['wifi_2_4_GHZ_title'] = _('CONTENT_SETTINGS_LABEL_WIFI_2_4_GHZ');
    $dictionary['wifi_5_GHZ_title'] = _('CONTENT_SETTINGS_LABEL_WIFI_5_GHZ');
    $dictionary['wifi_both_GHZ_title'] = _('CONTENT_SETTINGS_LABEL_WIFI_BOTH'); 
    $dictionary['wifi_ap_2_4_GHZ_title'] = _('CONTENT_SETTINGS_LABEL_WIFI_LOW_BAND');
    $dictionary['wifi_ap_5_GHZ_title'] = _('CONTENT_SETTINGS_LABEL_WIFI_HIGH_BAND');
	
    $dictionary['wifiInactivityNever'] = _('CONTENT_SETTINGS_LABEL_NEVER');
    $dictionary['wifiInactivity1'] = _('CONTENT_SETTINGS_LABEL_1_MIN');
    $dictionary['wifiInactivity3'] = _('CONTENT_SETTINGS_LABEL_3_MINS');
    $dictionary['wifiInactivity5'] = _('CONTENT_SETTINGS_LABEL_5_MINS');
    $dictionary['wifiInactivity10'] = _('CONTENT_SETTINGS_LABEL_10_MINS');
    $dictionary['wifiInactivity15'] = _('CONTENT_SETTINGS_LABEL_15_MINS');
    
    $dictionary['home_mode_reconnect_intro'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ON_HOME_NETWORK');
    $dictionary['home_network_reconnect_tip_1'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ON_DIFFERENT_NETWORK_TO_RECONNECT_TIP_1');
    $dictionary['home_network_reconnect_tip_2'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ON_DIFFERENT_NETWORK_TO_RECONNECT_TIP_2');

    $dictionary['wifi_signin_network_changing_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ABOUT_TO_LOSE_HOME_CONNECTION_PARAGRAPH_2');
    $dictionary['wifi_modify_network_changing_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ABOUT_TO_LOSE_HOME_CONNECTION_TO_HOTSPOT');
    $dictionary['wifi_disconnect_network_changing_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ABOUT_TO_LOSE_HOME_CONNECTION_PARAGRAPH_2');

    $dictionary['hotspot_direct_connection_reconnect_tip_1'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ON_DIRECT_CONNECTION_TO_RECONNECT_TIP_1');
    $dictionary['hotspot_direct_connection_reconnect_tip_2'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_ON_DIRECT_CONNECTION_TO_RECONNECT_TIP_2');

    //$dictionary['choose_internet_connection'] = _('CONTENT_SETTINGS_LABEL_CHOOSE_INTERNET_CONNECTION');
    //$dictionary['choose_home_router'] = _('CONTENT_SETTINGS_LABEL_CHOOSE_HOME_ROUTER');

    $dictionary['no_connections_found'] = _('CONTENT_SETTINGS_DIALOG_STRING_NO_CONNECTIONS_FOUND');
    $dictionary['no_devices_found'] = _('CONTENT_SETTINGS_STRING_NO_DEVICES_FOUND');

    $dictionary['capacity_txt'] = _('CONTENT_HOME_BIG_BOX_TITLE_CAPACITY');

    $dictionary['create_admin_password'] = _('CONTENT_USERS_DIALOG_TITLE_CREATE_ADMIN_PASSWORD');
    $dictionary['edit_admin_password'] = _('CONTENT_USERS_DIALOG_TITLE_EDIT_ADMIN_PASSWORD');

    //$dictionary['reconnect_wireless_network_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_GENERIC_RECONNECT_MESSAGE');
    //$dictionary['reboot_reconnect_factory_restore_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_FACTORY_RESTORE_SUCCESS_MESSAGE');

    $dictionary['ap_ipaddress_changed_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_IPADDRESS_CHANGED');

    //$dictionary['ap_ssid_broadcast_on_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_SSID_BROADCAST_ON');
    $dictionary['ap_ssid_broadcast_off_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_SSID_BROADCAST_OFF');

    $dictionary['ap_dhcp_on_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_DHCP_SERVICE_ON');
    $dictionary['ap_dhcp_off_msg'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_DHCP_SERVICE_OFF');

    $dictionary['ap_security_on'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_WIFI_SECURED');
    $dictionary['ap_security_off'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_WIFI_UNSECURED');
    $dictionary['ap_security_password_changed'] = _('CONTENT_SETTINGS_DIALOG_STRING_AVATAR_WIFI_PASSWORD_CHANGED');
    
    $dictionary['find_wifi'] = _('GLOB_NAV_DIALOG_STRING_FIND_AVATAR_WIFI_NETWORK');
    $dictionary['connect_wifi'] = _('GLOB_NAV_DIALOG_STRING_CONNECT_TO_AVATAR_WIFI_NETWORK');
    $dictionary['select_avatar_wifi'] = _('GLOB_NAV_DIALOG_STRING_SELECT_AVATAR_FROM_THE_WIFI_LIST');
    $dictionary['select_other_network'] = _('GLOB_NAV_DIALOG_STRING_SELECT_OTHER_NETWORK_FROM_THE_WIFI_LIST_AND_ENTER_AVATAR');
    $dictionary['devicename_url'] = _('GLOB_NAV_DIALOG_STRING_AVATAR_DEVICENAME_URL');

    $dictionary['sd_card_location'] = _('CONTENT_SETTINGS_STRING_AFTER_TRANSFER_FILE_LOCATION');
    $dictionary['importing_x_of_y'] = _('CONTENT_SETTINGS_STRING_IMPORTING_X_OF_Y');
    $dictionary['successful_import_x_bytes'] = _('CONTENT_SETTINGS_LABEL_SUCCESSFUL_IMPORT_X_BYTES');

	   
    $dictionary['usb_location'] = _('CONTENT_SETTINGS_STRING_AFTER_TRANSFER_FILE_LOCATION');

    /*
    $dictionary['security_none'] = _('GENERIC_WIFI_SECURITY_NONE');
    $dictionary['security_wpa2psk/tkipaes'] = _('GENERIC_WIFI_SECURITY_WPA2_PERSONAL');
    $dictionary['security_wpapsk1wpapsk2/tkipaes'] = _('GENERIC_WIFI_SECURITY_WPA_WPA2_PERSONAL_MIXED_MODE'); 
    */
    
    $dictionary['wifi_disable_confirmation'] = _('CONTENT_SETTINGS_DIALOG_STRING_DISABLE_WIFI');

    $dictionary['help_getting_started_more_info'] = _('HELP_GET_STARTED_DESC_MORE_INFO_LINE1');
    $dictionary['help_connect_with_usb_more_info'] = _('HELP_GET_CONNECT_WITH_USB_GET_MORE_INFO');
    $dictionary['help_first_connect_status_for_pc'] = _('HELP_FIRST_CONNECT_STATUS_DESC_ITEM1');
    $dictionary['help_first_connect_status_for_mac'] = _('HELP_FIRST_CONNECT_STATUS_DESC_ITEM2');
    
    $dictionary['page_header_updating_firmware'] = _('PAGE_HEADER_UPDATING_FIRMWARE');
    $dictionary['page_header_download_plex_media_server'] = _('PAGE_HEADER_DOWNLOAD_PLEX_MEDIA_SERVER');
    $dictionary['page_header_install_plex_media_server'] = _('PAGE_HEADER_INSTALL_PLEX_MEDIA_SERVER');
    $dictionary['twonky_server_string'] = _('CONTENT_SETTINGS_HEAD2_DLNA');
    $dictionary['twonky_server_string_2'] = _('CONTENT_SETTINGS_HEAD2_DLNA_2');
    $dictionary['plex_install_disable_twonky_warning'] = _('CONTENT_SETTINGS_STRING_PLEX_INSTALL');
    
    $dictionary['battery_note'] = _('CONTENT_SETTING_STRING_BATTERY_NOTE');
    $dictionary['update_progress_note'] = _('LABEL_DESCR_AVATAR_FIRMWARE_UPDATE_PROGRESS');
    
    $dictionary['registration_success'] = _('NEWKORRA_ONBOARDING_REGISTER_SUCCESS');
    $dictionary['ssh_password_maxlength'] = _('NEWKORRA_SSH_PASSWORD_MAXLENGTH');
    $dictionary['ssh_password_minlength'] = _('NEWKORRA_SSH_PASSWORD_MINLENGTH');
    $dictionary['ssh_password_special_char'] = _('NEWKORRA_SSH_PASSWORD_SPECIAL_CHAR');
    $dictionary['enter_password'] = _('CONTENT_WIFI_LABEL_PASSWORD');
    $dictionary['create_user_confirm_password'] = _("ERROR_PASSWORDS_DONT_MATCH");
    $dictionary['connection_lost'] = _("GLOB_NAV_DIALOG_TITLE_CONNECTION_LOST");
	
?>

var dictionaryList = new Array();
<?php
    foreach ($dictionary as $key => $translation) {
        echo "dictionaryList[\"".$key."\"] = \"".$translation."\";\n";
    }
?>

<?php
    //include_once('../lib/language.php');
    //$language = new Language();
    //$languageStr = $language->getLanguage();    
    //setlocale(LC_ALL, $languageStr.".UTF-8");
    //bindtextdomain("default", "../locale");
    //textdomain("default");

	$errors = array();
        //--------------- Generic errors 
        /* deprecated 
        $errors['unk'] = _("ERROR_UNKNOWN") . " (30000)";
        $errors['timeout'] = _("ERROR_TIMEOUT") . " (30001)";
        $errors['system_error'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (30002)";
        $errors['parsererror'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (30003)";
        $errors['get_unk'] = _("ERROR_GET_UNKNOWN_ERROR") . " (30004)";
        $errors['get_error'] = _("ERROR_GET_ERROR") . " (30005)";
        */ 
        
        //--------------- Standard HTTP error codes 
        /* deprecated 
        $errors['400'] = _("ERROR_BAD_REQUEST") . " (30400)";
        $errors['401'] = _("ERROR_NOT_AUTHORIZED_TASK") . " (30401)";
        $errors['403'] = _("ERROR_FORBIDDEN") . " (30403)";
        $errors['404'] = _("ERROR_SERVICE_NOT_FOUND") . " (30404)";
        $errors['405'] = _("ERROR_SERVICE_NOT_ALLOWED") . " (30405)";
        $errors['500'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (30500)";
        $errors['503'] = _("ERROR_SERVICE_NOT_FOUND") . " (30503)";
        */ 
        
        //--------------- Settings->System errors (310xx range) 
        //$errors['reboot_no_return'] = _("ERROR_REBOOT_TIMEOUT") . " (31001)";
        $errors['SettingDeviceName'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_INVALID") . ' ' . _("ERROR_ENTER_ALPHANUMERIC_DEVICE_NAME") . " (31002)";
        /* Legacy Sequoia
        $errors['SettingDescription'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_DESCRIPTION") . " (31003)";
        //$errors['SettingsEmail'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS") . " (31004)";
        $errors['registration_first_name'] = _("ERROR_FIRST_NAME_INVALID_SYNTAX") . " (31005)";
        $errors['registration_last_name'] = _("ERROR_LAST_NAME_INVALID_SYNTAX") . " (31006)";
        $errors['registration_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS") . " (31007)";
        $errors['registration_confirm_email'] = _("ERROR_EMAIL_ADDRESS_DONT_MATCH") . " (31008)";
        $errors['nosuccess'] = _("ERRORS_REGISTRATION_FAILED") . " (31009)";
        $errors['TestEmailFail'] = _("ERROR_TEST_EMAIL_SEND_FAILED") . " (31010)";
        $errors['SettingsSender'] = _("ERROR_PROVIDE_VALID_NAME") . " (31011)";
        $errors['resubmit_email_sender'] = _("ERROR_PROVIDE_VALID_NAME") . " (31012)"; 
        */ 
        
        $errors['SettingDeviceName_dash'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_INVALID") . ' ' . _("ERROR_ENTER_ALPHANUMERIC_DEVICE_NAME_DASH") . " (31013)";
        $errors['SettingDeviceName_number'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_INVALID") . ' ' . _("ERROR_ENTER_ALPHANUMERIC_DEVICE_NAME_NUMBER") . " (31014)";
        
        $errors['alerts_unk'] = _("LABEL_IGNORING_ALERTS") . ' ' . _("ERROR_UNKNOWN") . " (31021)";
		$errors['alerts_timeout'] = _("LABEL_IGNORING_ALERTS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31022)";

        /* Legacy Sequoia
		$errors['alert_email_0'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); //. " (31023)";        
		$errors['alert_email_1'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); //. " (31023)";
		$errors['alert_email_2'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); //. " (31023)";
		$errors['alert_email_3'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); //. " (31023)";
        $errors['alert_email_4'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); //. " (31023)"; 
        */ 

        //deprecated, new errorcode below 
        //$errors['register_device_unk'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31023)";
        //$errors['register_device_timeout'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_TIMEOUT") . " (31024)";
        
        $errors['reboot_unk'] = _("LABEL_REBOOTING_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31025)";
        $errors['reboot_timeout'] = _("LABEL_REBOOTING_DEVICE") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31026)";
        
        $errors['shutdown_unk'] = _("LABEL_SHUTTING_DOWN_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31027)";
        $errors['shutdown_timeout'] = _("LABEL_SHUTTING_DOWN_DEVICE") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31028)";
        
        $errors['system_notifications_unk'] = _("LABEL_SENDING_TEST_ALERT_EMAIL") . ' ' . _("ERROR_UNKNOWN") . " (31029)";
        $errors['system_notifications_timeout']= _("LABEL_SENDING_TEST_ALERT_EMAIL") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31030)";
        
        $errors['ssh_unk'] = _("LABEL_TOGGLING_SSH") . ' ' . _("ERROR_UNKNOWN") . " (31031)";
        $errors['ssh_timeout'] = _("LABEL_TOGGLING_SSH") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31032)";
        
        $errors['alerts_unk_error'] = _("LABEL_IGNORING_ALERTS") . ' '  . _("ERROR_UNKNOWN") . " (31033)";
        //$errors['register_device_unk_error'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31034)";
        $errors['reboot_unk_error'] = _("LABEL_REBOOTING_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31035)";
        $errors['shutdown_unk_error'] = _("LABEL_SHUTTING_DOWN_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31036)";
        $errors['system_notifications_unk_error'] = _("LABEL_SENDING_TEST_ALERT_EMAIL") . ' '. _("ERROR_UNKNOWN") . " (31037)";
        $errors['ssh_unk_error'] = _("LABEL_TOGGLING_SSH") . ' '  . _("ERROR_UNKNOWN") . " (31038)";
        
        $errors['no_usb_error'] = _("LABEL_NO_USB");
        $errors['no_sd_card_error'] = _("LABEL_NO_SD_CARD");
        
        $errors['registertion_failed'] = _("ERRORS_REGISTRATION_FAILED");
        $errors['registertion_no_first_name'] = _("NEWKORRA_ONBOARDING_REGISTER_FIRST_NAME_WARN");
        $errors['registertion_no_last_name'] = _("NEWKORRA_ONBOARDING_REGISTER_LAST_NAME_WARN");
        $errors['registertion_no_email'] = _("NEWKORRA_ONBOARDING_REGISTER_EMAIL_WARN");
        
        /* Legacy Sequoia
        $errors['change_centralserver_400'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_BAD_REQUEST") . " (31040)";
        $errors['change_centralserver_401'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31041)";
        $errors['change_centralserver_403'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_FORBIDDEN") . " (31043)";
        $errors['change_centralserver_404'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31044)";
        $errors['change_centralserver_500'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31045)";
        $errors['change_centralserver_unk'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_UNKNOWN") . " (31046)";
        $errors['change_centralserver_unk_error'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_UNKNOWN") . " (31047)";
        $errors['change_centralserver_timeout'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_TIMEOUT") . " (31048)";
        $errors['confirmAuthorizationPassword'] = _("ERROR_AUTHORIZATION_DO_NOT_MATCH") . " (31049)";
        
        $errors['centralserver_get_400'] = _("LABEL_GET_CENTRAL_SERVER") . ' ' . _("ERROR_BAD_REQUEST") . " (31050)";
        $errors['centralserver_get_401'] = _("LABEL_GET_CENTRAL_SERVER") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31051)";
        $errors['centralserver_get_403'] = _("LABEL_GET_CENTRAL_SERVER") . ' ' . _("ERROR_FORBIDDEN") . " (31053)";
        $errors['centralserver_get_404'] = _("LABEL_GET_CENTRAL_SERVER") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31054)";
        $errors['centralserver_get_500'] = _("LABEL_GET_CENTRAL_SERVER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31055)";
        
        $errors['change_centralserver_parsererror'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31060)";
        */
         
        $errors['reboot_parsererror'] = _("LABEL_REBOOTING_DEVICE") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31061)";
        $errors['shutdown_parsererror'] = _("LABEL_SHUTTING_DOWN_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31062)";
        //$errors['register_device_parsererror'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31063)";
        $errors['alerts_parsererror'] = _("LABEL_IGNORING_ALERTS") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31064)";
        $errors['system_notifications_parsererror'] = _("LABEL_SENDING_TEST_ALERT_EMAIL") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31065)";
        $errors['ssh_parsererror'] = _("LABEL_TOGGLING_SSH") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31066)";
        
        /* Legacy Sequoia
        $errors['register_device_400'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_BAD_REQUEST") . " (31570)";
        $errors['register_device_401'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31571)";
        $errors['register_device_403'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_FORBIDDEN") . " (31572)";
        $errors['register_device_404'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31573)";
        $errors['register_device_500'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31574)";
        $errors['register_device_unk'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31075)";
        $errors['register_device_timeout'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_TIMEOUT") . " (31076)";
        $errors['register_device_unk_error'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (31077)";
        $errors['register_device_parsererror'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31078)";
        $errors['register_device_error'] = _("LABEL_REGISTERING_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31079)";
        */ 
        
        $errors['reboot_error'] = _("LABEL_REBOOTING_DEVICE") . ' ' . _("ERROR_USER_ABORT") . " (31080)";
        //$errors['change_centralserver_error'] = _("LABEL_CHANGING_CENTRAL_SERVER") . ' ' . _("ERROR_USER_ABORT") . " (31081)";
        $errors['shutdown_error'] = _("LABEL_SHUTTING_DOWN_DEVICE") . ' ' . _("ERROR_USER_ABORT") . " (31082)";
        $errors['alerts_error'] = _("LABEL_IGNORING_ALERTS") . ' '  . _("ERROR_USER_ABORT") . " (31083)";
        $errors['system_notifications_error'] = _("LABEL_SENDING_TEST_ALERT_EMAIL") . ' '. _("ERROR_USER_ABORT") . " (31084)";
        $errors['ssh_error'] = _("LABEL_TOGGLING_SSH") . ' '  . _("ERROR_USER_ABORT") . " (31085)";
        
        //--------------- Settings->System, firmware errors (311xx range) 
        //deprecated, new errorcode below 
        /*
        $errors['update_200'] = _("ERROR_INVALID_FW_PACKAGE") . " (31101)";
        $errors['update_201'] = _("ERROR_OUT_OF_SPACE_FOR_UPGRADE") . " (31102)";
        $errors['update_202'] = _("ERROR_UPGRADE_DOWNLOAD_FAILED") . " (31103)";
        $errors['update_203'] = _("ERROR_UPGRADE_UNPACK_FAILED") . " (31104)";
        $errors['update_204'] = _("ERROR_UPGRADE_COPY_FAILED") . " (31105)";
        $errors['update_failed'] = _("ERROR_UPGRADE_FAILED") . " (31106)";
        $errors['update_205'] = _("ERROR_UPGRADE_ALL_DRIVE_MUST_BE_PRESENT") . " (31107)"; 
        */ 
        
        //deprecated, new errorcode below 
        //$errors['update_500'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31108)";
        
        //$errors['auto_update_error'] = _("ERROR_NO_INTERNET_CONNECTIVITY") . " (31109)";
        //$errors['auto_update_unk'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_UNKNOWN") . " (31110)";
        //$errors['auto_update_timeout'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_TIMEOUT") . " (31111)";
        
        //$errors['init_update_unk'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_UNKNOWN") . " (31112)";
        //$errors['init_update_timeout'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_TIMEOUT") . " (31113)";
        
        //$errors['update_status_unk'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_UNKNOWN") . " (31114)";
        //$errors['update_status_timeout'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_TIMEOUT") . " (31115)";
        
        //$errors['auto_update_unk_error'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_UNKNOWN") . " (31116)";
        //$errors['init_update_unk_error'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_UNKNOWN") . " (31117)";
        //$errors['update_status_unk_error'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_UNKNOWN") . " (31118)";
        
        //$errors['system_general_settings_unk'] = _("ERROR_UNKNOWN") . " (31119)";
        //$errors['system_general_settings_unk_error'] = _("ERROR_UNKNOWN") . " (31120)";
        
        $errors['system_updates_unk_error'] = _("ERROR_UNKNOWN") . " (31121)";
        $errors['system_updates_timeout'] = _("ERROR_AVATAR_TIMEOUT") . " (31122)";
        
        $errors['system_usage_timeout'] = _("LABEL_GET_USAGE") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31123)";
        $errors['system_usage_unk_error'] = _("LABEL_GET_USAGE") . ' ' . _("ERROR_UNKNOWN") . " (31124)";
        $errors['system_usage_parsererror'] = _("LABEL_GET_USAGE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31125)";
        $errors['system_usage_error'] = _("LABEL_GET_USAGE") . ' ' . _("ERROR_USER_ABORT") . " (31125)";
        
        $errors['system_updates_parsererror'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (31130)";
        //deprecated, new errorcode below 
        //$errors['auto_update_parsererror'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31131)";
        //$errors['init_update_parsererror'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31132)";
        //$errors['system_general_settings_parsererror'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (31133)";
        //$errors['update_status_parsererror'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31134)";
        
        /* deprecated, new errorcode below 
        $errors['update_400'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_BAD_REQUEST") . " (31140)";
        $errors['update_401'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_NOT_AUTHORIZED_TASK") . " (31141)";
        $errors['update_403'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_FORBIDDEN") . " (31142)";
        $errors['update_404'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_SERVICE_NOT_FOUND") . " (31143)";
        $errors['update_500'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31144)";
        */
        
        /* Legacy Sequoia
        $errors['auto_update_400'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_BAD_REQUEST") . " (31150)";
        $errors['auto_update_401'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31151)";
        $errors['auto_update_403'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_FORBIDDEN") . " (31152)";
        $errors['auto_update_404'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31153)";
        $errors['auto_update_500'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31154)";
        $errors['auto_update_data_error'] = _("ERROR_NO_INTERNET_CONNECTIVITY") . " (31155)";
        $errors['auto_update_unk'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_UNKNOWN") . " (31156)";
        $errors['auto_update_timeout'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_TIMEOUT") . " (31157)";
        $errors['auto_update_unk_error'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_UNKNOWN") . " (31158)";
        $errors['auto_update_parsererror'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31159)";
        
        $errors['init_update_400'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_BAD_REQUEST") . " (31160)";
        $errors['init_update_401'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31161)";
        $errors['init_update_403'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_FORBIDDEN") . " (31162)";
        $errors['init_update_404'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31163)";
        $errors['init_update_500'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31164)";
        $errors['init_update_unk'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_UNKNOWN") . " (31165)";
        $errors['init_update_timeout'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_TIMEOUT") . " (31166)";
        $errors['init_update_unk_error'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_UNKNOWN") . " (31167)";
        $errors['init_update_parsererror'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31168)";
        $errors['init_update_error'] = _("LABEL_UPDATING_FIRMWARE") . ' ' . _("ERROR_USER_ABORT") . " (31169)";
        */ 
        
        $errors['system_general_settings_400'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . ' ' . _("ERROR_BAD_REQUEST") . " (31170)";
        $errors['system_general_settings_401'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_NOT_AUTHORIZED_TASK") . " (31171)";
        $errors['system_general_settings_403'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_FORBIDDEN") . " (31172)";
        $errors['system_general_settings_404'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_SERVICE_NOT_FOUND") . " (31173)";
        $errors['system_general_settings_500'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_INTERNAL_SERVER_ERROR") . " (31174)";
        $errors['system_general_settings_unk'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_UNKNOWN") . " (31175)";
        $errors['system_general_settings_unk_error'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_UNKNOWN") . " (31176)";
        $errors['system_general_settings_timeout'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_AVATAR_TIMEOUT") . " (31177)";
        $errors['system_general_settings_parsererror'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_INTERNAL_SERVER_ERROR") . " (31178)";
        $errors['system_general_settings_error'] = _("LABEL_CONFIGURING_SETTINGS_GENERAL") . _("ERROR_USER_ABORT") . " (31179)";
        
        $errors['update_status_unk'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_UNKNOWN") . " (31180)";
        $errors['update_status_timeout'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_AVATAR_TIMEOUT") . " (31181)";
        $errors['update_status_unk_error'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_UNKNOWN") . " (31182)";
        $errors['update_status_parsererror'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_INTERNAL_SERVER_ERROR") . " (31183)";
        $errors['update_status_error'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '. _("ERROR_USER_ABORT") . " (31184)";
        
        $errors['system_updates_error'] = _("ERROR_USER_ABORT") . " (31190)";
        $errors['auto_update_error'] = _("LABEL_AUTO_UPDATING_FIRMWARE") . ' ' . _("ERROR_USER_ABORT") . " (31191)";
        
        //--------------- Settings->System->Network errors (312xx range) 
        $errors['SettingIp'] = _("ERROR_INVALID_IP_ADDRESS"); // . " (31201)";
        $errors['SettingGateway'] = _("ERROR_INVALID_GATEWAY"); // . " (31202)";
        $errors['SettingNetmask'] = _("ERROR_INVALID_NETMASK"); // . " (31203)";
        $errors['SettingDNS'] = _("ERROR_INVALID_DNS_SERVER"); // . " (31204)";
        $errors['missing_dns'] = _("ERROR_AT_LEAST_ONE_DNS_REQUIRED"); // . " (31205)";
        //$errors['SettingWorkgroupName'] = _("ERROR_ENTER_ALPHANUMERIC_WORKGROUP") . " (31206)";
        
        $errors['network_lan_configuration_unk'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_UNKNOWN") . " (31207)";
        $errors['network_lan_configuration_timeout']= _("ERROR_AVATAR_TIMEOUT_IPADDRESS_CHANGED") . " (31208)";
        $errors['network_lan_configuration_unk_error'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_UNKNOWN") . " (31209)";
        
        /*
        $errors['Setting_IPADDRESS_1000'] = _("ERROR_INVALID_IP_ADDRESS") . " (31210)";
        $errors['Setting_IPADDRESS_1001'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_EMPTY") . " (31211)";
        $errors['Setting_IPADDRESS_1002'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL") . " (31212)";
        $errors['Setting_IPADDRESS_1003'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION") . " (31213)";
        $errors['Setting_IPADDRESS_1004'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_LOOPBACK") . " (31214)";
        $errors['Setting_IPADDRESS_1005'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_LINKLOCAL") . " (31215)";
        $errors['Setting_IPADDRESS_1006'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_ANYCAST") . " (31216)";
        $errors['Setting_IPADDRESS_1007'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_MULTICAST") . " (31217)";
        $errors['Setting_IPADDRESS_1008'] = _("LABEL_HEADER_IP_ADDRESS") . ' ' . _("ERROR_NETWORK_RESERVED") . " (31218)";
        $errors['Setting_IPADDRESS_1009'] = _("ERROR_INVALID_HOST_IPADDRESS_AND_WITH_NETMASK") . " (31219)";
        
        $errors['Setting_NETMASK_1000'] = _("ERROR_INVALID_NETMASK") . " (31220)";
        $errors['Setting_NETMASK_1001'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_EMPTY") . " (31221)";
        $errors['Setting_NETMASK_1002'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL") . " (31222)";
        */
        /* 
        $errors['Setting_NETMASK_1003'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION") . " (31223)";
        $errors['Setting_NETMASK_1004'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_LOOPBACK") . " (31224)";
        $errors['Setting_NETMASK_1005'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_LINKLOCAL") . " (31225)";
        $errors['Setting_NETMASK_1006'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_ANYCAST") . " (31226)";
        $errors['Setting_NETMASK_1007'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_MULTICAST") . " (31227)";
        $errors['Setting_NETMASK_1008'] = _("LABEL_HEADER_NETMASK") . ' ' . _("ERROR_NETWORK_RESERVED") . " (31228)";
        */ 
        /*
        $errors['Setting_NETMASK_1009'] = _("ERROR_NETMASK_NOT_CONTIGUOUS") . " (31229)";
        
        $errors['Setting_GATEWAY_1000'] = _("ERROR_INVALID_GATEWAY") . " (31230)";
        $errors['Setting_GATEWAY_1001'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_EMPTY") . " (31231)";
        $errors['Setting_GATEWAY_1002'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL") . " (31232)";
        $errors['Setting_GATEWAY_1003'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION") . " (31233)";
        $errors['Setting_GATEWAY_1004'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_LOOPBACK") . " (31234)";
        $errors['Setting_GATEWAY_1005'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_LINKLOCAL") . " (31235)";
        $errors['Setting_GATEWAY_1006'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_ANYCAST") . " (31236)";
        $errors['Setting_GATEWAY_1007'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_MULTICAST") . " (31237)";
        $errors['Setting_GATEWAY_1008'] = _("LABEL_HEADER_GATEWAY") . ' ' . _("ERROR_NETWORK_RESERVED") . " (31238)";
        $errors['Setting_GATEWAY_1009'] = _("ERROR_GATEWAY_WRONG_SUBNET") . " (31239)";
        
        $errors['Setting_DNS_1000'] = _("ERROR_INVALID_DNS_SERVER") . " (31240)";
        $errors['Setting_DNS_1001'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_EMPTY") . " (31241)";
        $errors['Setting_DNS_1002'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL") . " (31242)";
        $errors['Setting_DNS_1003'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION") . " (31243)";
        $errors['Setting_DNS_1004'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_LOOPBACK") . " (31244)";
        $errors['Setting_DNS_1005'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_LINKLOCAL") . " (31245)";
        $errors['Setting_DNS_1006'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_ANYCAST") . " (31246)";
        $errors['Setting_DNS_1007'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_MULTICAST") . " (31247)";
        $errors['Setting_DNS_1008'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED") . " (31248)";
        
        $errors['Setting_NTP_1000'] = _("ERROR_INVALID_NTP_SERVER") . " (31250)";
        $errors['Setting_NTP_1001'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_EMPTY") . " (31251)";
        $errors['Setting_NTP_1002'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL") . " (31252)";
        $errors['Setting_NTP_1003'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION") . " (31253)";
        $errors['Setting_NTP_1004'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_LOOPBACK") . " (31254)";
        $errors['Setting_NTP_1005'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_LINKLOCAL") . " (31255)";
        $errors['Setting_NTP_1006'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_ANYCAST") . " (31256)";
        $errors['Setting_NTP_1007'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_MULTICAST") . " (31257)";
        $errors['Setting_NTP_1008'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED") . " (31258)";
        
        $errors['network_lan_configuration_ping_timeout'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_TIMEOUT") . " (31260)";
        $errors['network_lan_configuration_ping_unk_error'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31261)";
        
        $errors['network_lan_configuration_parsererror'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31262)";
        $errors['network_lan_configuration_ping_parsererror'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31263)";
        
        $errors['network_lan_configuration_error'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_USER_ABORT") . " (31264)";
        $errors['network_lan_configuration_ping_error'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_USER_ABORT") . " (31265)"; 
        */ 
        
        //--------------- Settings->System->Utilities errors (313xx range) 
        $errors['invalid_config_file_type'] = _("ERROR_INVALID_CONFIG_FILE_SELECTED") . " (31301)";
        $errors['invalid_firmware_file_type'] = _("ERROR_INVALID_AVATAR_FIRMWARE_FILE_SELECTED") . " (31302)";
        $errors['space_issue_for_file'] = _("ERROR_OUT_OF_SPACE_FOR_UPGRADE"); // . " (31303)";
        $errors['reboot_112'] = _("ERROR_RESTORE_FILE_IS_NOT_CORRECT_FORMAT") . " (31304)";
        
        //deprecated, new errorcode below 
        //$errors['start_factoryrestore_unk'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_UNKNOWN") . " (31305)";
        //$errors['start_factoryrestore_timeout']= _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_TIMEOUT") . 31306
        
        //$errors['get_factoryrestore_unk'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31307)";
        //$errors['get_factoryrestore_timeout'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_TIMEOUT") . " (31308)";
        
        //$errors['start_selftest_unk'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31309)";
        //$errors['start_selftest_timeout'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_TIMEOUT") . " (31310)";
        
        //$errors['cancel_selftest_unk'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31311)";
        //$errors['cancel_selftest_timeout'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_TIMEOUT") . " (31312)";
        
        //$errors['get_selftest_unk'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' '  . _("ERROR_UNKNOWN") . " (31313)";
        //$errors['get_selftest_timeout'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' '  . _("ERROR_TIMEOUT") . " (31314)";
        
        //$errors['start_factoryrestore_unk_error'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_UNKNOWN") . " (31315)";
        //$errors['get_factoryrestore_unk_error'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' '. _("ERROR_UNKNOWN") . " (31316)";
        //$errors['start_selftest_unk_error'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31317)";
        //$errors['cancel_selftest_unk_error'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31318)";
        //$errors['get_selftest_unk_error'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31319)";
        
        $errors['config_file_timeout'] = _("ERROR_AVATAR_TIMEOUT_IPADDRESS_CHANGED") . " (31320)";
        
        //$errors['diagnostic_get_500'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31330)";
        //$errors['start_selftest_500'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31331)";
        //$errors['cancel_selftest_500'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31332)";
        
        //$errors['start_selftest_400'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("LABEL_DESCR_DIAGNOSTIC_IN_PROGRESS") . " (31333)";
        //$errors['start_selftest_401'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31334)";
        
        //$errors['diagnostic_get_400'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (31335)";
        //$errors['diagnostic_get_401'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31336)";
        
        //$errors['cancel_selftest_400'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_BAD_REQUEST") . " (31337)";
        //$errors['cancel_selftest_401'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31338)";
        
        //$errors['start_factoryrestore_parsererror'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31340)";
        //$errors['get_factoryrestore_parsererror'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31341)";
        //$errors['start_selftest_parsererror'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31342)";
        //$errors['cancel_selftest_parsererror'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31343)";
        //$errors['get_selftest_parsererror'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31344)";
        
        $errors['diagnostic_get_400'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (31321)";
        $errors['diagnostic_get_401'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31322)";
        $errors['diagnostic_get_403'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_FORBIDDEN") . " (31323)";
        $errors['diagnostic_get_404'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31324)";
        $errors['diagnostic_get_500'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31325)";
        
        $errors['start_selftest_400'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("LABEL_DESCR_DIAGNOSTIC_IN_PROGRESS") . " (31340)";
        $errors['start_selftest_401'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31341)";
        $errors['start_selftest_403'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_FORBIDDEN") . " (31342)";
        $errors['start_selftest_404'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31343)";
        $errors['start_selftest_500'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31344)";
        $errors['start_selftest_unk'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31345)";
        $errors['start_selftest_timeout'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31346)";
        $errors['start_selftest_unk_error'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31347)";
        $errors['start_selftest_parsererror'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31348)";
        $errors['start_selftest_error'] = _("LABEL_STARTING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_USER_ABORT") . " (31349)";
        
        $errors['get_selftest_400'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31350)";
        $errors['get_selftest_401'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31351)";
        $errors['get_selftest_403'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_FORBIDDEN") . " (31352)";
        $errors['get_selftest_404'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31353)";
        $errors['get_selftest_500'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31354)";
        $errors['get_selftest_unk'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31355)";
        $errors['get_selftest_timeout'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31356)";
        $errors['get_selftest_unk_error'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31357)";
        $errors['get_selftest_parsererror'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31358)";
        $errors['get_selftest_error'] = _("LABEL_GET_SELFTEST_PROGRESS") . ' ' . _("ERROR_USER_ABORT") . " (31358)";
        
        $errors['cancel_selftest_400'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_BAD_REQUEST") . " (31360)";
        $errors['cancel_selftest_401'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31361)";
        $errors['cancel_selftest_403'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_FORBIDDEN") . " (31362)";
        $errors['cancel_selftest_404'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31363)";
        $errors['cancel_selftest_500'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31364)";
        $errors['cancel_selftest_unk'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31365)";
        $errors['cancel_selftest_timeout'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31366)";
        $errors['cancel_selftest_unk_error'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_UNKNOWN") . " (31367)";
        $errors['cancel_selftest_parsererror'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31368)";
        $errors['cancel_selftest_error'] = _("LABEL_CANCELLING_DIAGNOSTIC_TEST") . ' ' . _("ERROR_USER_ABORT") . " (31369)";
        
        $errors['start_factoryrestore_400'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_BAD_REQUEST") . " (31370)";
        $errors['start_factoryrestore_401'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31371)";
        $errors['start_factoryrestore_403'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_FORBIDDEN") . " (31372)";
        $errors['start_factoryrestore_404'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_MOBILEACCESS_NOT_FOUND") . " (31373)";
        $errors['start_factoryrestore_500'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31374)";
        $errors['start_factoryrestore_unk'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_UNKNOWN") . " (31375)";
        $errors['start_factoryrestore_timeout']= _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31376)";
        $errors['start_factoryrestore_unk_error'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_UNKNOWN") . " (31377)";
        $errors['start_factoryrestore_parsererror'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31378)";
        $errors['start_factoryrestore_error'] = _("LABEL_RESTORING_FACTORY_DEFAULT") . ' ' . _("ERROR_USER_ABORT") . " (31379)";
        
        $errors['get_factoryrestore_400'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31380)";
        $errors['get_factoryrestore_401'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31381)";
        $errors['get_factoryrestore_403'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_FORBIDDEN") . " (31382)";
        $errors['get_factoryrestore_404'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31383)";
        $errors['get_factoryrestore_500'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31384)";
        $errors['get_factoryrestore_unk'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31385)";
        $errors['get_factoryrestore_timeout'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31386)";
        $errors['get_factoryrestore_unk_error'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31387)";
        $errors['get_factoryrestore_parsererror'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31388)";
        $errors['get_factoryrestore_error'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_USER_ABORT") . " (31389)";
        
        //--------------- Settings->System->Remote Access (MioNet) errors (314xx range) 
        /* 
        $errors['mionet_error_101'] = _("ERROR_USERNAME_ALREADY_EXISTS") . " (31401)";
        $errors['mionet_error_102'] = _("ERROR_EXCEPTION_DURING_USER_FIND") . " (31402)";
        $errors['mionet_error_103'] = _("ERROR_EXCEPTION_DURING_USER_CREATION") . " (31403)";
        $errors['mionet_error_104'] = _("ERROR_EXCEPTION_DURING_REGISTRATION") . " (31404)";
        $errors['mionet_error_105'] = _("ERROR_EMAIL_ALREADY_REGISTERED") . " (31405)";
        $errors['mionet_error_106'] = _("ERROR_INVALID_ACCOUNT") . " (31406)";
        $errors['mionet_error_107'] = _("ERROR_MIONET_NODE_NAME_CONFLICT") . " (31407)";
        $errors['mionet_error_110'] = _("ERROR_MIONET_PASSWORD_CONTAINS_INVALID_CHARACTERS") . " (31410)";
        $errors['mionet_error_111'] = _("ERROR_MIONET_CONNECTION_FAILED") . " (31411)";
         
        $errors['confirm_mionet_unk'] = _("ERROR_UNKNOWN") . " (31420)";
        $errors['confirm_mionet_timeout'] = _("ERROR_TIMEOUT") . " (31421)";
         
        $errors['create_mionet_unk'] = _("ERROR_UNKNOWN") . " (31422)";
        $errors['create_mionet_timeout'] = _("ERROR_TIMEOUT") . " (31423)";
         
        $errors['unregister_mionet_unk'] = _("ERROR_UNKNOWN") . " (31424)";
        $errors['unregister_mionet_timeout'] = _("ERROR_TIMEOUT") . " (31425)";
         
        $errors['mionet_status_form_unk'] = _("ERROR_UNKNOWN") . " (31426)";
        $errors['mionet_status_form_timeout'] = _("ERROR_TIMEOUT") . " (31427)";
         
        $errors['confirm_mionet_unk_error'] = _("ERROR_UNKNOWN") . " (31428)";
        $errors['create_mionet_unk_error'] = _("ERROR_UNKNOWN") . " (31429)";
        $errors['unregister_mionet_unk_error'] = _("ERROR_UNKNOWN") . " (31430)";
        $errors['mionet_status_form_unk_error'] = _("ERROR_UNKNOWN") . " (31431)";
        */ 
        /* 
        $errors['SettingMionetUsername'] = _("ERROR_ENTER_MIONET_USERNAME") . " (31451)";
        $errors['SettingMionetPassword'] = _("ERROR_ENTER_MIONET_PASSWORD") . " (31452)";
        $errors['SettingMionetFirstname'] = _("ERROR_ENTER_FIRST_NAME_FOR_MIONET") . " (31453)";
        $errors['SettingMionetLastname'] = _("ERROR_ENTER_LAST_NAME_FOR_MIONET") . " (31454)";
        $errors['SettingMionetCreateUsername'] = _("ERROR_MIONET_USERNAME_INCORRECT_SYNTAX") . " (31455
        $errors['SettingMionetCreatePassword'] = _("ERROR_MIONET_PASSWORD_INCORRECT_SYNTAX") . " (31456
        $errors['SettingMionetConfirmPassword']= _("ERROR_MIONET_PASSWORDS_DONT_MATCH") . " (31457
        $errors['SettingMionetEmail'] = _("ERROR_INVALID_EMAIL_ADDRESS_FOR_MIONET") . " (31458)";
        $errors['SettingMionetConfirmEmail'] = _("ERROR_MIONET_EMAIL_ADDRESESS_DONT_MATCH") . " (31459)";
        */ 
        
        //--------------- Settings->System->Remote Access (Orion) configuration errors (315xx range) 
        /* Legacy Sequoia
        $errors['remoteaccess_invalid_dac'] = _("ERROR_DAC_INVALID") . " (31501)";
        //$errors['remoteaccess_error'] = _("LABEL_REMOTE_CONNECTION_FAILED") . " (31502)";
        
        //deprecated, new errorcode below 
        //$errors['register_device_500'] = _("ERROR_DEVICE_REG_FAILED") . " (31503)";
        //$errors['configure_remote_access_403'] = _("ERROR_DEVICE_NOT_REGISTERED") . " (31504
        //$errors['configure_remote_access_500'] = _("ERROR_DEVICE_UPDATE_FAILED") . " (31505
        
        //$errors['configure_remote_access_unk'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31510)";
        //$errors['configure_remote_access_timeout'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_TIMEOUT") . 31511
        
        $errors['update_remote_access_timeout'] = _("LABEL_UPDATING_REMOTE_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31512)";
        
        $errors['remoteaccess_unk'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31513)";
        $errors['remoteaccess_timeout'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31514)";
        
        //$errors['configure_remote_access_unk_error'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31515)";
        $errors['remoteaccess_unk_error'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31516)";
        
        //$errors['configure_remote_access_parsererror'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31517)";
        $errors['remoteaccess_parsererror'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31518)";
        $errors['remoteaccess_error'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_USER_ABORT") . " (31519)";
        
        $errors['remoteaccess_failed'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_FAILED"); // . " (31520)";
        $errors['remoteaccess_disabled'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_DISABLED"); // . " (31521)";
        $errors['remoteaccess_conecting'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_CONNECTING"); // . " (31522)";
        $errors['remoteaccess_ready'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_READY"); // . " (31523)";
        $errors['remoteaccess_relay'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_RELAYED"); // . " (31524)";
        $errors['remoteaccess_portforward'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_PORTFORWARDED"); // . " (31525)";
        $errors['remoteaccess_relay_portfailed'] = _("LABEL_HEADER_CONNECTION_STATUS") . ' ' . _("LABEL_STATUS_RELAYED"); // . " (31526)";
        
        $errors['remoteaccess_get_500'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31550)";
        $errors['remoteaccess_get_400'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31551)";
        $errors['remoteaccess_get_401'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31552)";
        $errors['remoteaccess_get_403'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31553)";
        $errors['remoteaccess_get_404'] = _("LABEL_ADDING_REMOTE_DEVICE_ACCESS") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31554)";
        
        $errors['configure_remote_access_400'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31560)";
        $errors['configure_remote_access_401'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31561)";
        $errors['configure_remote_access_403'] = _("ERROR_DEVICE_NOT_REGISTERED") . " (31562)";
        $errors['configure_remote_access_404'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31563)";
        $errors['configure_remote_access_500'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_DEVICE_UPDATE_FAILED") . " (31564)";
        $errors['configure_remote_access_unk'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31565)";
        $errors['configure_remote_access_timeout'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31566)";
        $errors['configure_remote_access_unk_error'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31567)";
        $errors['configure_remote_access_parsererror'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31568)";
        $errors['configure_remote_access_error'] = _("LABEL_CONFIGURATING_REMOTE_ACCESS") . ' ' . _("ERROR_USER_ABORT") . " (31569)"; 
        */ 
        
        //--------------- Settings->System->Remote Access (Orion) device_users errors (316xx range) 
        /* Legacy Sequoia 
        $errors['save_webaccount_unk'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31600)";
        $errors['save_webaccount_404'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_WEBACCOUNT_NOT_FOUND") . " (31601)";
        $errors['save_webaccount_500'] = _("ERROR_WEBACCOUNT_CREATE_FAILED") . " (31602)";
        $errors['save_webaccount_timeout'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31603)";
        $errors['save_webaccount_unk_error'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31604)";
        $errors['save_webaccount_duplicate'] = _("ERROR_WEBACCOUNT_DUPLICATE") . " (31605)";
        $errors['save_webaccount_400'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31606)";
        $errors['save_webaccount_401'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31607)";
        $errors['save_webaccount_parsererror'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31608)";
        $errors['save_webaccount_error'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_USER_ABORT") . " (31609)";
        $errors['save_webaccount_403'] = _("LABEL_REGISTERING_WEB_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31610)";
        
        $errors['get_webaccount_404'] = _("LABEL_GET_WEB_ACCESS") . ' ' . _("ERROR_WEBACCOUNT_NOT_FOUND") . " (31611)";
        $errors['get_webaccount_500'] = _("LABEL_GET_WEB_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31612)";
        $errors['get_webaccount_400'] = _("LABEL_GET_WEB_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31613)";
        $errors['get_webaccount_401'] = _("LABEL_GET_WEB_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31614)";
        $errors['get_webaccount_403'] = _("LABEL_GET_WEB_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31615)";
        
        $errors['resubmit_email_unk'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_UNKNOWN") . " (31620)";
        $errors['resubmit_email_404'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_WEBACCOUNT_NOT_FOUND") . " (31621)";
        $errors['resubmit_email_500'] = _("ERROR_WEBACCOUNT_RESUBMIT_EMAIL_FAILED") . " (31622)";
        $errors['resubmit_email_timeout'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_TIMEOUT") . " (31623)";
        $errors['resubmit_email_unk_error'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_UNKNOWN") . " (31624)";
        $errors['resubmit_email_400'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_BAD_REQUEST") . " (31625)";
        $errors['resubmit_email_401'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31626)";
        $errors['resubmit_email_parsererror'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31627)";
        $errors['resubmit_email_403'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_FORBIDDEN") . " (31628)";
        $errors['resubmit_email_error'] = _("LABEL_RESUBMITTING_REGISTRATION_EMAIL") . ' ' . _("ERROR_USER_ABORT") . " (31629)";
        
        $errors['delete_webaccount_unk'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31630)";
        $errors['delete_webaccount_404'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_WEBACCOUNT_NOT_FOUND") . " (31631)";
        $errors['delete_webaccount_500'] = _("ERROR_WEBACCOUNT_DELETE_FAILED") . " (31632)";
        $errors['delete_webaccount_timeout'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31633)";
        $errors['delete_webaccount_unk_error'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31634)";
        $errors['delete_webaccount_400'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31635)";
        $errors['delete_webaccount_401'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31636)";
        $errors['delete_webaccount_parsererror'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31637)";
        $errors['delete_webaccount_403'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31638)";
        $errors['delete_webaccount_error'] = _("LABEL_DELETING_WEB_ACCESS") . ' ' . _("ERROR_USER_ABORT") . " (31639)";
        
        $errors['get_mobileaccess_404'] = _("LABEL_RETRIEVING_MOBILE_ACCESS") . ' ' . _("ERROR_MOBILEACCESS_NOT_FOUND") . " (31641)";
        $errors['get_mobileaccess_500'] = _("LABEL_RETRIEVING_MOBILE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31642)";
        $errors['get_mobileaccess_400'] = _("LABEL_RETRIEVING_MOBILE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31643)";
        $errors['get_mobileaccess_401'] = _("LABEL_RETRIEVING_MOBILE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31644)";
        $errors['get_mobileaccess_403'] = _("LABEL_RETRIEVING_MOBILE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31645)";
        
        $errors['save_mobileaccess_unk'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31650)";
        $errors['save_mobileaccess_404'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_MOBILEACCESS_NOT_FOUND") . " (31651)";
        $errors['save_mobileaccess_500'] = _("ERROR_MOBILEACCESS_CREATE_FAILED") . " (31652)";
        $errors['save_mobileaccess_timeout'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31653)";
        $errors['save_mobileaccess_unk_error'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31654)";
        $errors['save_mobileaccess_403'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31655)";
        $errors['save_mobileaccess_400'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31656)";
        $errors['save_mobileaccess_401'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31657)";
        $errors['save_mobileaccess_parsererror'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31658)";
        $errors['save_mobileaccess_error'] = _("LABEL_GENERATING_CODE_FOR_MOBILE_ACCESS") . ' ' . _("ERROR_USER_ABORT") . " (31659)";
        
        $errors['delete_mobileaccess_unk'] = _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31660)";
        $errors['delete_mobileaccess_404'] = _("ERROR_MOBILEACCESS_NOT_FOUND") . " (31661)";
        $errors['delete_mobileaccess_500'] = _("ERROR_MOBILEACCESS_DELETE_FAILED") . " (31662)";
        $errors['delete_mobileaccess_timeout'] = _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_TIMEOUT") . " (31663)";
        $errors['delete_mobileaccess_unk_error']= _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_UNKNOWN") . " (31664)";
        $errors['delete_mobileaccess_400'] = _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31665)";
        $errors['delete_mobileaccess_401'] = _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31666)";
        $errors['delete_mobileaccess_parsererror']= _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31667)";
        $errors['delete_mobileaccess_403'] = _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (31668)";
        $errors['delete_mobileaccess_error']= _("LABEL_REMOVING_MOBILE_ACCESS") . ' ' . _("ERROR_USER_ABORT") . " (31669)";
        
        $errors['rebuild_wd2go_media_unk'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_UNKNOWN") . " (31670)";
        $errors['rebuild_wd2go_media_timeout'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_TIMEOUT") . " (31671)";
        $errors['rebuild_wd2go_media_unk_error'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_UNKNOWN") . " (31672)";
        $errors['rebuild_wd2go_media_parsererror'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31673)";
        $errors['rebuild_wd2go_media_400'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_BAD_REQUEST") . " (31674)";
        $errors['rebuild_wd2go_media_401'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31675)";
        $errors['rebuild_wd2go_media_403'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_FORBIDDEN") . " (31676)";
        $errors['rebuild_wd2go_media_404'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31677)";
        $errors['rebuild_wd2go_media_500'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31678)";
        $errors['rebuild_wd2go_media_error'] = _("LABEL_REBUILDING_WD2GO_DATABASE") . ' ' . _("ERROR_USER_ABORT") . " (31679)";
        
        $errors['configure_connectivity_unk'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_UNKNOWN") . " (31680)";
        $errors['configure_connectivity_timeout'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_TIMEOUT") . " (31681)";
        $errors['configure_connectivity_unk_error'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_UNKNOWN") . " (31682)";
        $errors['configure_connectivity_400'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_BAD_REQUEST") . " (31683)";
        $errors['configure_connectivity_401'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31684)";
        $errors['configure_connectivity_404'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31685)";
        $errors['configure_connectivity_500'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31686)";
        
        $errors['http_port_id'] = _("ERROR_HTTP_PORTNUMBER"); // . " (31687)";
        $errors['https_port_id'] = _("ERROR_HTTPS_PORTNUMBER"); // . " (31688)";
        // deprecated
        //$errors['https_port_dup'] = _("ERROR_DUPLICATE_HTTPS_PORTNUMBER") . " (31689)";
        //
        
        $errors['configure_connectivity_parsererror'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31690)";
        $errors['configure_connectivity_error'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_USER_ABORT") . " (31691)";
        $errors['configure_connectivity_403'] = _("LABEL_CONFIGURATING_CONNECTION_OPTION") . ' ' . _("ERROR_FORBIDDEN") . " (31692)";
        
        */
        //--------------- Settings->System->Media errors (317xx range) 
        $errors['toggle_connected_device_unk'] = _("LABEL_BLOCKING_MEDIA_PLAYER") . ' '  . _("ERROR_UNKNOWN") . " (31700)";
        $errors['toggle_connected_device_timeout'] = _("LABEL_BLOCKING_MEDIA_PLAYER") . ' '  . _("ERROR_AVATAR_TIMEOUT") . " (31701)";
        
        $errors['refresh_media_server_list_unk'] = _("AVATAR_LABEL_RESCANNING_MEDIA_PLAYERS") . ' ' . _("ERROR_UNKNOWN") . " (31702)";
        $errors['refresh_media_server_list_timeout']= _("AVATAR_LABEL_RESCANNING_MEDIA_PLAYERS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31703)";
        
        $errors['rescan_dlna_unk'] = _("AVATAR_LABEL_RESCANNING_DLNA_SERVER") . ' '  . _("ERROR_UNKNOWN") . " (31710)";
        $errors['rescan_dlna_timeout'] = _("AVATAR_LABEL_RESCANNING_DLNA_SERVER") . ' '  . _("ERROR_AVATAR_TIMEOUT") . " (31711)";
        
        $errors['rebuild_dlna_unk'] = _("LABEL_REBUILDING_DLNA_SERVER_DATABASE") . ' ' . _("ERROR_UNKNOWN") . " (31712)";
        $errors['rebuild_dlna_timeout'] = _("LABEL_REBUILDING_DLNA_SERVER_DATABASE") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31713)";
        
        $errors['get_dlna_status_unk'] = _("LABEL_GET_DLNA_RESCAN_PROGRESS") . ' '  . _("ERROR_UNKNOWN") . " (31714)";
        $errors['get_dlna_status_timeout'] = _("LABEL_GET_DLNA_RESCAN_PROGRESS") . ' '  . _("ERROR_AVATAR_TIMEOUT") . " (31715)";
        
        $errors['enable_dlna_unk'] = _("LABEL_ENABLING_DLNA_SERVICE") . ' '  . _("ERROR_UNKNOWN") . " (31716)";
        $errors['enable_dlna_timeout'] = _("LABEL_ENABLING_DLNA_SERVICE") . ' '  . _("ERROR_AVATAR_TIMEOUT") . " (31717)";
        
        $errors['enable_itunes_unk'] = _("LABEL_ENABLING_ITUNES_SERVICE") . ' '  . _("ERROR_UNKNOWN") . " (31720)";
        $errors['enable_itunes_timeout'] = _("LABEL_ENABLING_ITUNES_SERVICE") . ' '  . _("ERROR_AVATAR_TIMEOUT") . " (31721)";
        
        $errors['rescan_itunes_unk'] = _("AVATAR_LABEL_RESCANNING_ITUNES_SERVER") . ' ' . _("ERROR_UNKNOWN") . " (31722)";
        $errors['rescan_itunes_timeout'] = _("AVATAR_LABEL_RESCANNING_ITUNES_SERVER") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (31723)";
        
        $errors['toggle_connected_device_unk_error'] = _("LABEL_BLOCKING_MEDIA_PLAYER") . ' '  . _("ERROR_UNKNOWN") . " (31730)";
        $errors['refresh_media_server_list_unk_error'] = _("AVATAR_LABEL_RESCANNING_MEDIA_PLAYERS") . ' ' . _("ERROR_UNKNOWN") . " (31731)";
        $errors['rescan_dlna_unk_error'] = _("AVATAR_LABEL_RESCANNING_DLNA_SERVER") . ' '  . _("ERROR_UNKNOWN") . " (31732)";
        $errors['rebuild_dlna_unk_error'] = _("LABEL_REBUILDING_DLNA_SERVER_DATABASE") . ' ' . _("ERROR_UNKNOWN") . " (31733)";
        $errors['get_dlna_status_unk_error'] = _("LABEL_GET_DLNA_RESCAN_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31734)";
        $errors['enable_dlna_unk_error'] = _("LABEL_ENABLING_DLNA_SERVICE") . ' '  . _("ERROR_UNKNOWN") . " (31735)";
        $errors['enable_itunes_unk_error'] = _("LABEL_ENABLING_ITUNES_SERVICE") . ' '  . _("ERROR_UNKNOWN") . " (31736)";
        $errors['rescan_itunes_unk_error'] = _("AVATAR_LABEL_RESCANNING_ITUNES_SERVER") . ' ' . _("ERROR_UNKNOWN") . " (31737)";
        
        $errors['toggle_connected_device_parsererror'] = _("LABEL_BLOCKING_MEDIA_PLAYER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31740)";
        $errors['refresh_media_server_list_parsererror'] = _("AVATAR_LABEL_RESCANNING_MEDIA_PLAYERS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31741)";
        $errors['rescan_dlna_parsererror'] = _("AVATAR_LABEL_RESCANNING_DLNA_SERVER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31742)";
        $errors['rebuild_dlna_parsererror'] = _("LABEL_REBUILDING_DLNA_SERVER_DATABASE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31743)";
        $errors['get_dlna_status_parsererror'] = _("LABEL_GET_DLNA_RESCAN_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31744)";
        $errors['enable_dlna_parsererror'] = _("LABEL_ENABLING_DLNA_SERVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31745)";
        $errors['enable_itunes_parsererror'] = _("LABEL_ENABLING_ITUNES_SERVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31746)";
        $errors['rescan_itunes_parsererror'] = _("AVATAR_LABEL_RESCANNING_ITUNES_SERVER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31747)";
        
        $errors['get_dlna_500'] = _("LABEL_GET_DLNA_INFORMATION") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (31750)";
        $errors['get_dlna_503'] = _("LABEL_GET_DLNA_INFORMATION") . ' '  . _("ERROR_SERVICE_NOT_FOUND") . " (31751)";
        $errors['get_dlna_400'] = _("LABEL_GET_DLNA_INFORMATION") . ' '  . _("ERROR_BAD_REQUEST") . " (31752)";
        $errors['get_dlna_401'] = _("LABEL_GET_DLNA_INFORMATION") . ' '  . _("ERROR_NOT_AUTHORIZED_TASK") . " (31753)";
        $errors['get_dlna_403'] = _("LABEL_GET_DLNA_INFORMATION") . ' '  . _("ERROR_FORBIDDEN") . " (31754)";
        $errors['get_dlna_404'] = _("LABEL_GET_DLNA_INFORMATION") . ' '  . _("ERROR_SERVICE_NOT_FOUND") . " (31755)";
         
        $errors['toggle_connected_device_error'] = _("LABEL_BLOCKING_MEDIA_PLAYER") . ' ' . _("ERROR_USER_ABORT") . " (31740)";
        $errors['refresh_media_server_list_error'] = _("AVATAR_LABEL_RESCANNING_MEDIA_PLAYERS") . ' ' . _("ERROR_USER_ABORT") . " (31741)";
        $errors['rescan_dlna_error'] = _("AVATAR_LABEL_RESCANNING_DLNA_SERVER") . ' ' . _("ERROR_USER_ABORT") . " (31742)";
        $errors['rebuild_dlna_error'] = _("LABEL_REBUILDING_DLNA_SERVER_DATABASE") . ' ' . _("ERROR_USER_ABORT") . " (31743)";
        $errors['get_dlna_status_error'] = _("LABEL_GET_DLNA_RESCAN_PROGRESS") . ' ' . _("ERROR_USER_ABORT") . " (31744)";
        $errors['enable_dlna_error'] = _("LABEL_ENABLING_DLNA_SERVICE") . ' ' . _("ERROR_USER_ABORT") . " (31745)";
        $errors['enable_itunes_error'] = _("LABEL_ENABLING_ITUNES_SERVICE") . ' ' . _("ERROR_USER_ABORT") . " (31746)";
        $errors['rescan_itunes_error'] = _("AVATAR_LABEL_RESCANNING_ITUNES_SERVER") . ' ' . _("ERROR_USER_ABORT") . " (31747)";
          
        //--------------- Settings->System->Storage->RAID errors (318xx range) 
        /* Legacy Zermatt
        if (isset($features['RAID'])) { 
         $errors['start_raid_conversion_unk'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_UNKNOWN") . " (31800)";
         $errors['start_raid_conversion_timeout'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_TIMEOUT") . " (31801)";
         $errors['start_raid_conversion_unk_error'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_UNKNOWN") . " (31802)";
         $errors['start_raid_conversion_1'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31803)";
         $errors['start_raid_conversion_400'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_BAD_REQUEST") . " (31804)";
         $errors['start_raid_conversion_401'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31805)";
         $errors['start_raid_conversion_404'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31806)";
         $errors['start_raid_conversion_500'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31807)";

         $errors['start_raid_conversion_space_limitation'] = _("ERROR_SPACE_LIMITATION") . " (31808)";
         $errors['start_raid_conversion_parsererror'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31809)";
        
         $errors['get_raidconversion_unk'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31810)";
         $errors['get_raidconversion_timeout'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_TIMEOUT") . " (31811)";
         $errors['get_raidconversion_unk_error'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31812)";
         $errors['get_raidconversion_1'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31813)";
         $errors['get_raidconversion_400'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_BAD_REQUEST") . " (31814)";
         $errors['get_raidconversion_401'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31815)";
         $errors['get_raidconversion_404'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31816)";
         $errors['get_raidconversion_parsererror'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31817)";
         $errors['get_raidconversion_error'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_USER_ABORT") . " (31818)";
        
         $errors['get_raid_details_unk'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (31820)";
         $errors['get_raid_details_timeout'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_TIMEOUT") . " (31821)";
         $errors['get_raid_details_unk_error'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (31822)";
         $errors['get_raid_details_1'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31823)";
         $errors['get_raid_details_400'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (31824)";
         $errors['get_raid_details_401'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31825)";
         $errors['get_raid_details_404'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31826)";
         $errors['get_raid_details_parsererror'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31827)";
         $errors['get_raid_details_error'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_USER_ABORT") . " (31828)";
         
         $errors['raid_conversion_failed'] = _("ERROR_CONVERSION_FAILED") . " (31830)";
         $errors['raid_conversion_unk'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (31831)";
        
         $errors['start_raid_conversion_403'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_FORBIDDEN") . " (31841)";
         $errors['get_raidconversion_403'] = _("LABEL_GET_STORAGE_CONVERSION_PROGRESS") . ' ' . _("ERROR_FORBIDDEN") . " (31842)";
         $errors['get_raid_details_403'] = _("LABEL_GET_STORAGE_DRIVE_INFORMATION") . ' ' . _("ERROR_FORBIDDEN") . " (31843)";
        
         $errors['start_raid_conversion_error'] = _("LABEL_STARTING_STORAGE_CONVERSION") . ' ' . _("ERROR_USER_ABORT") . " (31850)";
        } 
        */ 
          
        //--------------- Settings->System->Storage->USB errors (319xx range) 
        /* Legacy Sequoia
        //if (isset($features['USB'])) { 
         $errors['usb_unlock_timeout'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_TIMEOUT") . " (31900)";
         $errors['usb_unlock_unk_error'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_UNKNOWN") . " (31901)";
         $errors['usb_unlock_internal'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_UNKNOWN") . " (31902)";
         $errors['usb_unlock_drive_not_found'] = _("ERROR_DRIVE_NOT_FOUND") . " (31903)";
         $errors['usb_unlock_drive_handle_missing'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_UNKNOWN") . " (31904)";
         $errors['usb_unlock_password_missing'] = _("ERROR_PASSWORD_MISSING") . " (31905)";
         $errors['usb_unlock_invalid_save_value'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_UNKNOWN") . " (31906)";
         $errors['usb_unlock_drive_not_locked'] = _("ERROR_USB_DRIVE_NOT_LOCKED") . " (31907)";
         $errors['usb_unlock_failed'] = _("ERROR_USB_DRIVE_UNLOCK_FAILED") . " (31908)";
         $errors['usb_unlock_exceeded_attempts'] = _("ERROR_USB_DRIVE_EXCEEDED_ATTEMPTS") . " (31909)";
         $errors['usb_unlock_400'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_BAD_REQUEST") . " (31910)";
         $errors['usb_unlock_401'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31911)";
         $errors['usb_unlock_403'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_FORBIDDEN") . " (31912)";
         $errors['usb_unlock_404'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31913)";
         $errors['usb_unlock_500'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31914)";
         $errors['usb_unlock_parsererror'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31915)";
         $errors['usb_unlock_error'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_USER_ABORT") . " (31916)";
         $errors['usb_unlock_unk'] = _("LABEL_UNLOCKING_USB") . ' ' . _("ERROR_UNKNOWN") . " (31917)";
        
         $errors['usb_get_unk'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (31920)";
         $errors['usb_get_timeout'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_TIMEOUT") . " (31921)";
         $errors['usb_get_unk_error'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (31922)";
         $errors['usb_get_internal'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (31923)";
         $errors['usb_get_400'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (31924)";
         $errors['usb_get_401'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31925)";
         $errors['usb_get_403'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_FORBIDDEN") . " (31926)";
         $errors['usb_get_404'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31927)";
         $errors['usb_get_500'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31928)";
         $errors['usb_get_parsererror'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31929)";
        
         $errors['usb_delete_unk'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_UNKNOWN") . " (31930)";
         $errors['usb_delete_timeout'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_TIMEOUT") . " (31931)";
         $errors['usb_delete_unk_error'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_UNKNOWN") . " (31932)";
         $errors['usb_delete_internal'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_UNKNOWN") . " (31933)";
         $errors['usb_delete_drive_not_found'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_DRIVE_NOT_FOUND") . " (31934)";
         $errors['usb_delete_drive_handle_missing'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_UNKNOWN") . " (31935)";
         $errors['usb_delete_400'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_BAD_REQUEST") . " (31936)";
         $errors['usb_delete_401'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (31937)";
         $errors['usb_delete_403'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_FORBIDDEN") . " (31938)";
         $errors['usb_delete_404'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (31939)";
         $errors['usb_delete_500'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31940)";
         $errors['usb_delete_parsererror'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (31941)";
         $errors['usb_delete_error'] = _("LABEL_EJECT_USB") . ' ' . _("ERROR_USER_ABORT") . " (31942)";
        
         $errors['usb_get_error'] = _("LABEL_GET_USB_INFORMATION") . ' ' . _("ERROR_USER_ABORT") . " (31950)";
        //} 
        */

        //--------------- Users UI errors (320xx range) 
        $errors['user_duplicate'] = _("ERROR_USER_SAME_NAME_EXISTS") . " (32001)";
        $errors['user_missing'] = _("ERROR_USER_RENAMED_DELETED") . " (32002)";
        //$errors['create_user_first_name'] = _("ERROR_USERNAME_INCORRECT_SYNTAX") . " (32003)";
        //$errors['create_user_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS") . " (31004)";
        $errors['userFullname'] = _("ERROR_FULL_NAME_INCORRECT_SYNTAX"); // . " (32004)";
        $errors['ownerPassword'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");  // . " (32005)";
        $errors['userPassword'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");  // . " (32006)";
        //$errors['create_user_confirm_password'] = _("ERROR_PASSWORDS_DONT_MATCH") . " (32007)";
        $errors['ownerConfirmPassword'] = _("ERROR_PASSWORDS_DONT_MATCH");  // . " (32008)";
        $errors['ownerOldPassword'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");  // . " (32009)";
        
        //deprecated, new errorcode below 
        //$errors['update_ownerpassword_unk'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_UNKNOWN") . " (32010)";
        //$errors['update_ownerpassword_timeout'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_TIMEOUT") . " (32011)";
        
        //$errors['update_password_unk'] = _("LABEL_UPDATING_PASSWORD") . ' '  . _("ERROR_UNKNOWN") . " (32012)";
        //$errors['update_password_timeout'] = _("LABEL_UPDATING_PASSWORD") . ' '  . _("ERROR_TIMEOUT") . " (32013)";
        
        //$errors['update_ownerpassword_unk_error'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_UNKNOWN") . " (32014)";
        //$errors['update_password_unk_error'] = _("LABEL_UPDATING_PASSWORD") . ' '  . _("ERROR_UNKNOWN") . " (32015)";
        
        //$errors['update_ownerpassword_error'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_GET_ERROR") . " (32016)";
        //$errors['update_password_error'] = _("LABEL_UPDATING_PASSWORD") . ' '  . _("ERROR_GET_ERROR") . " (32017)";
        
        //$errors['update_ownerpassword_parsererror'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32018)";
        //$errors['update_password_parsererror'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32019)";

        //$errors['reserved_username'] = _("ERROR_USERNAME_RESERVED") . " (32020)";
        
        /* Legacy Sequoia
        $errors['update_ownerpassword_400'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_BAD_REQUEST") . " (32030)";
        $errors['update_ownerpassword_401'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (32031)";
        $errors['update_ownerpassword_403'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_FORBIDDEN") . " (32032)";
        $errors['update_ownerpassword_404'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (32033)";
        $errors['update_ownerpassword_500'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32034)";
        $errors['update_ownerpassword_unk'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_UNKNOWN") . " (32035)";
        $errors['update_ownerpassword_timeout'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_TIMEOUT") . " (32036)";
        $errors['update_ownerpassword_error'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_USER_ABORT") . " (32037)";
        $errors['update_ownerpassword_unk_error'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_UNKNOWN") . " (32038)";
        $errors['update_ownerpassword_parsererror'] = _("LABEL_UPDATING_OWNER_PASSWORD") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32039)";
        */ 
        
        $errors['update_password_400'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_BAD_REQUEST") . " (32050)";
        $errors['update_password_401'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (32051)";
        $errors['update_password_403'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_FORBIDDEN") . " (32052)";
        $errors['update_password_404'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (32053)";
        $errors['update_password_500'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32054)";
        $errors['update_password_unk'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_UNKNOWN") . " (32055)";
        $errors['update_password_timeout'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (32056)";
        $errors['update_password_unk_error'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_UNKNOWN") . " (32056)";
        $errors['update_password_error'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_USER_ABORT") . " (32057)";
        $errors['update_password_parsererror'] = _("LABEL_UPDATING_PASSWORD") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32059)";
        
        //--------------- Users API errors (321xx range) 
        $errors['users_get_unk'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (32100)";
        $errors['users_get_404'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_USER_NOT_FOUND") . " (32101)";
        $errors['users_get_500'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32102)";
        $errors['users_get_timeout'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (32103)";
        $errors['users_get_unk_error'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (32104)";
        $errors['users_get_400'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (32105)";
        $errors['users_get_401'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (32106)";
        $errors['users_get_403'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_FORBIDDEN") . " (32107)";
        $errors['users_get_parsererror'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32108)";
        $errors['users_get_error'] = _("LABEL_GET_USER_INFORMATION") . ' ' . _("ERROR_USER_ABORT") . " (32109)";
        
        /* Legacy Sequoia
        $errors['users_create_unk'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_UNKNOWN") . " (32110)";
        $errors['users_create_500'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_USER_CREATE_FAILED") . " (32111)";
        $errors['users_create_404'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_USER_NOT_FOUND") . " (32112)";
        $errors['users_create_timeout'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_TIMEOUT") . " (32113)";
        $errors['users_create_unk_error'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_UNKNOWN") . " (32114)";
        $errors['users_create_400'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_BAD_REQUEST") . " (32115)";
        $errors['users_create_401'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (32116)";
        $errors['users_create_403'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_FORBIDDEN") . " (32117)";
        $errors['users_create_parsererror'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32118)";
        $errors['users_create_error'] = _("LABEL_CREATING_USER") . ' ' . _("ERROR_USER_ABORT") . " (32119)";
        */ 
        
        $errors['users_update_unk'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_UNKNOWN") . " (32120)";
        $errors['users_update_404'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_USER_NOT_FOUND") . " (32121)";
        $errors['users_update_500'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_USER_UPDATE_FAILED") . " (32122)";
        $errors['users_update_timeout'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (32123)";
        $errors['users_update_unk_error'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_UNKNOWN") . " (32124)";
        $errors['users_update_400'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_BAD_REQUEST") . " (32125)";
        $errors['users_update_401'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (32126)";
        $errors['users_update_403'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_FORBIDDEN") . " (32127)";
        $errors['users_update_parsererror'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32128)";
        $errors['users_update_error'] = _("LABEL_UPDATING_USER") . ' ' . _("ERROR_USER_ABORT") . " (32129)";
        
        /* Legacy Sequoia
        $errors['users_delete_unk'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_UNKNOWN") . " (32130)";
        $errors['users_delete_404'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_USER_NOT_FOUND") . " (32131)";
        $errors['users_delete_500'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_USER_DELETE_FAILED") . " (32132)";
        $errors['users_delete_timeout'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_TIMEOUT") . " (32133)";
        $errors['users_delete_unk_error'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_UNKNOWN") . " (32134)";
        $errors['users_delete_400'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_BAD_REQUEST") . " (32135)";
        $errors['users_delete_401'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (32136)";
        $errors['users_delete_403'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_FORBIDDEN") . " (32137)";
        $errors['users_delete_parsererror'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (32138)";
        $errors['users_delete_error'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_USER_ABORT") . " (32139)";
        */ 
        
        $errors['update_password_500'] = _("ERROR_PASSWORD_UPDATE_FAILED") . " (32141)";
        
        //--------------- Shares UI errors (330xx range) 
        /* Legacy Sequoia
        $errors['share_duplicate'] = _("ERROR_SHARE_NAME_EXISTS") . " (33001)";
        $errors['share_missing'] = _("ERROR_SHARE_RENAMED_DELETED") . " (33002)";
        //$errors['create_share_name'] = _("ERROR_SHARE_NAME_INCORRECT_SYNTAX") . " (33003)";
        $errors['shareDescription'] = _("ERROR_SHARE_DESCRIPTION_INCORRECT_SYNTAX");  // . " (33004)";
        //$errors['reserved_sharename'] = _("ERROR_SHARE_NAME_RESERVED") . " (33010)";
        */ 
        
        //--------------- Shares API errors (331xx range) 
        /* Legacy Sequoia
        $errors['shareaccess_create_404'] = _("ERROR_SHAREACCESS_NOT_FOUND") . " (33101)";
        $errors['shareaccess_create_500'] = _("ERROR_SHAREACCESS_CREATE_FAILED") . " (33102)";
        $errors['shareaccess_create_400'] = _("LABEL_CREATING_SHARE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (33103)";
        $errors['shareaccess_create_401'] = _("LABEL_CREATING_SHARE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33104)";
        $errors['shareaccess_create_403'] = _("LABEL_CREATING_SHARE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (33105)";
        
        $errors['shareaccess_update_404'] = _("ERROR_SHAREACCESS_NOT_FOUND") . " (33111)";
        $errors['shareaccess_update_500'] = _("ERROR_SHAREACCESS_UPDATE_FAILED") . " (33112)";
        $errors['shareaccess_update_400'] = _("LABEL_UPDATING_SHARE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (33113)";
        $errors['shareaccess_update_401'] = _("LABEL_UPDATING_SHARE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33114)";
        $errors['shareaccess_update_403'] = _("LABEL_UPDATING_SHARE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (33115)";
        
        $errors['shareaccess_delete_404'] = _("ERROR_SHAREACCESS_NOT_FOUND") . " (33121)";
        $errors['shareaccess_delete_500'] = _("ERROR_SHAREACCESS_DELETE_FAILED") . " (33122)";
        $errors['shareaccess_delete_400'] = _("LABEL_DELETING_SHARE_ACCESS") . ' ' . _("ERROR_BAD_REQUEST") . " (33123)";
        $errors['shareaccess_delete_401'] = _("LABEL_DELETING_SHARE_ACCESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33124)";
        $errors['shareaccess_delete_403'] = _("LABEL_DELETING_SHARE_ACCESS") . ' ' . _("ERROR_FORBIDDEN") . " (33125)";
        
        $errors['shares_update_unk'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_UNKNOWN") . " (33130)";
        $errors['shares_update_404'] = _("ERROR_SHARE_NOT_FOUND") . " (33131)";
        $errors['shares_update_500'] = _("ERROR_SHARE_UPDATE_FAILED") . " (33132)";
        $errors['shares_update_timeout'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_TIMEOUT") . " (33133)";
        $errors['shares_update_unk_error'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_UNKNOWN") . " (33134)";
        $errors['shares_update_400'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_BAD_REQUEST") . " (33135)";
        $errors['shares_update_401'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33136)";
        $errors['shares_update_403'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_FORBIDDEN") . " (33137)";
        $errors['shares_update_parsererror'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33138)";
        $errors['shares_update_error'] = _("LABEL_UPDATING_SHARE") . ' ' . _("ERROR_USER_ABORT") . " (33139)";
        
        $errors['shares_delete_unk'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_UNKNOWN") . " (33140)";
        $errors['shares_delete_404'] = _("ERROR_SHARE_NOT_FOUND") . " (33141)";
        $errors['shares_delete_500'] = _("ERROR_SHARE_DELETE_FAILED") . " (33142)";
        $errors['shares_delete_timeout'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_TIMEOUT") . " (33143)";
        $errors['shares_delete_unk_error'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_UNKNOWN") . " (33144)";
        $errors['shares_delete_400'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_BAD_REQUEST") . " (33145)";
        $errors['shares_delete_401'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33146)";
        $errors['shares_delete_403'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_FORBIDDEN") . " (33147)";
        $errors['shares_delete_parsererror'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33148)";
        $errors['shares_delete_error'] = _("LABEL_DELETING_SHARE") . ' ' . _("ERROR_USER_ABORT") . " (33149)";
        
        $errors['shares_create_unk'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_UNKNOWN") . " (33150)";
        $errors['shares_create_404'] = _("ERROR_SHARE_NOT_FOUND") . " (33151)";
        $errors['shares_create_500'] = _("ERROR_SHARE_CREATE_FAILED") . " (33152)";
        $errors['shares_create_timeout'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_TIMEOUT") . " (33153)";
        $errors['shares_create_unk_error'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_UNKNOWN") . " (33154)";
        $errors['shares_create_400'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_BAD_REQUEST") . " (33155)";
        $errors['shares_create_401'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33156)";
        $errors['shares_create_403'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_FORBIDDEN") . " (33157)";
        $errors['shares_create_parsererror'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33158)";
        $errors['shares_create_error'] = _("LABEL_CREATING_SHARE") . ' ' . _("ERROR_USER_ABORT") . " (33159)";
        
        $errors['shares_get_unk'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (33160)";
        $errors['shares_get_timeout'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_TIMEOUT") . " (33161)";
        $errors['shares_get_unk_error'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (33162)";
        $errors['shares_get_400'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (33163)";
        $errors['shares_get_401'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33164)";
        $errors['shares_get_404'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (33165)";
        $errors['shares_get_500'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33166)";
        $errors['shares_get_403'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_FORBIDDEN") . " (33167)";
        $errors['shares_get_parsererror'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33168)";
        $errors['shares_get_error'] = _("LABEL_GET_SHARE_INFORMATION") . ' ' . _("ERROR_USER_ABORT") . " (33169)";
        */ 
        
        //--------------- Shares->TimeMachine errors (332xx range) 
        /* Legacy Sequoia
        $errors['update_time_machine_unk'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_UNKNOWN") . " (33200)";
        $errors['update_time_machine_timeout'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_TIMEOUT") . " (33201)";
        $errors['update_time_machine_unk_error'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_UNKNOWN") . " (33202)";
        $errors['update_time_machine_400'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_BAD_REQUEST") . " (33203)";
        $errors['update_time_machine_401'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (33204)";
        $errors['update_time_machine_403'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_FORBIDDEN") . " (33205)";
        $errors['update_time_machine_404'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_SHARE_NOT_FOUND") . " (33206)";
        $errors['update_time_machine_500'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33207)";
        $errors['update_time_machine_parsererror'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (33208)";
        $errors['update_time_machine_error'] = _("LABEL_UPDATING_TIME_MACHINE") . ' ' . _("ERROR_USER_ABORT") . " (33209)"; 
        */ 
        
        //--------------- Backups->Backup List errors (34xxx range) 
        /* Legacy Apollo
        $errors['delete_backup_unk'] = _("LABEL_DELETING_BACKUP") . ' ' . _("ERROR_UNKNOWN") . " (34000)";
        $errors['delete_backup_timeout'] = _("LABEL_DELETING_BACKUP") . ' ' . _("ERROR_TIMEOUT") . " (34001)";
        $errors['delete_backup_unk_error'] = _("LABEL_DELETING_BACKUP") . ' ' . _("ERROR_UNKNOWN") . " (34002)";
        $errors['delete_backup_parsererror'] = _("LABEL_DELETING_BACKUP") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (34004)";
        $errors['delete_backup_error'] = _("LABEL_DELETING_BACKUP") . ' ' . _("ERROR_USER_ABORT") . " (34005)"; 
        */ 
        
        //--------------- Backups->SafePoint errors (35xxx range) 
        /* Legacy Sequoia
        $errors['replication_share_username'] = _("ERROR_SHARE_USERNAME_INCORRECT_SYNTAX"); // . " (35001)";
        //$errors['replication_share_password'] = _("ERROR_SHARE_PASSWORD_INCORRECT_SYNTAX") . " (35002)";
        $errors['replication_device_username'] = _("ERROR_DEVICE_USERNAME_INCORRECT_SYNTAX"); // . " (35003)";
        //$errors['replication_device_password'] = _("ERROR_DEVICE_PASSWORD_INCORRECT_SYNTAX") . " (35004)";
        
        $errors['summary_safepoint_details_name_input'] = _("ERROR_SAFEPOINT_INCORRECT_SYNTAX"); // . " (35006)"; 
        */ 
        
        //--------------- Backups->SafePoint API GET errors (351xx-35999 range) 
        
        //--------------- Backups->SafePoint Device API errors (351xx range) 
        /* Legacy Sequoia
        $errors['nas_authenticate_2'] = _("ERROR_NAS_AUTHENTICATION_FAILED") . " (35102)";
        $errors['nas_authenticate_3'] = _("ERROR_NAS_AUTHENTICATION_NOTFOUND") . " (35103)";
        $errors['nas_authenticate_4'] = _("ERROR_NAS_AUTHENTICATION_UNAUTHORIZED") . " (35104)";
        $errors['nas_authenticate_7'] = _("ERROR_NAS_AUTHENTICATION_INVALID") . " (35107)";
        $errors['nas_authenticate_unk'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_UNKNOWN") . " (35140)";
        $errors['nas_authenticate_timeout'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_TIMEOUT") . " (35141)";
        $errors['nas_authenticate_unk_error'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_UNKNOWN") . " (35142)";
        $errors['nas_authenticate_parsererror'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35143)";
        $errors['nas_authenticate_400'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_BAD_REQUEST") . " (35144)";
        $errors['nas_authenticate_401'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35145)";
        $errors['nas_authenticate_403'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_FORBIDDEN") . " (35146)";
        $errors['nas_authenticate_404'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35147)";
        $errors['nas_authenticate_500'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35148)";
        $errors['nas_authenticate_error'] = _("LABEL_AUTHENTICATING_DEVICE_ON_NETWORK") . ' ' . _("ERROR_USER_ABORT") . " (35149)"; 
        */ 
        
        //--------------- Backups->SafePoint Share Discovery API errors (352xx range) 
        /* Legacy Sequoia
        $errors['share_discover_2'] = _("ERROR_SHARE_DISCOVER_FAILED") . " (35202)";
        $errors['share_discover_3'] = _("ERROR_SHARE_DISCOVER_NOTFOUND") . " (35203)";
        $errors['share_discover_4'] = _("ERROR_SHARE_DISCOVER_UNAUTHORIZED") . " (35204)";
        $errors['share_discover_7'] = _("ERROR_SHARE_DISCOVER_INVALID") . " (35207)";
        $errors['share_discover_unk'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (35240)";
        $errors['share_discover_timeout'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_TIMEOUT") . " (35241)";
        $errors['share_discover_unk_error'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (35242)";
        $errors['share_discover_parsererror'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35243)";
        $errors['share_discover_400'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_BAD_REQUEST") . " (35244)";
        $errors['share_discover_401'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35245)";
        $errors['share_discover_403'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_FORBIDDEN") . " (35246)";
        $errors['share_discover_404'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35247)";
        $errors['share_discover_500'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35248)";
        $errors['share_discover_error'] = _("LABEL_DISCOVERING_SHARES_ON_NETWORK_DEVICE") . ' ' . _("ERROR_USER_ABORT") . " (35249)"; 
        */ 
        
        //--------------- Backups->SafePoint Share Authenticate API errors (353xx range) 
        /* Legacy Sequoia
        $errors['share_authenticate_2'] = _("ERROR_SHARE_AUTHENTICATION_FAILED") . " (35302)";
        $errors['share_authenticate_3'] = _("ERROR_SHARE_AUTHENTICATION_NOTFOUND") . " (35303)";
        $errors['share_authenticate_4'] = _("ERROR_SHARE_AUTHENTICATION_UNAUTHORIZED") . " (35304)";
        $errors['share_authenticate_7'] = _("ERROR_SHARE_AUTHENTICATION_INVALID") . " (35307)";
        $errors['share_authenticate_unk'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (35340)";
        $errors['share_authenticate_timeout'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_TIMEOUT") . " (35341)";
        $errors['share_authenticate_unk_error'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (35342)";
        $errors['share_authenticate_parsererror'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35343)";
        $errors['share_authenticate_400'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_BAD_REQUEST") . " (35344)";
        $errors['share_authenticate_401'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35345)";
        $errors['share_authenticate_403'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_FORBIDDEN") . " (35346)";
        $errors['share_authenticate_404'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35346)";
        $errors['share_authenticate_500'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35348)";
        $errors['share_authenticate_error'] = _("LABEL_AUTHENTICATING_SHARE_ON_NETWORK_DEVICE") . ' ' . _("ERROR_USER_ABORT") . " (35349)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint API errors (354xx range) 
        /* Legacy Sequoia
        $errors['safepoint_discover_2'] = _("ERROR_SAFEPOINT_DISCOVER_FAILED") . " (35402)";
        $errors['safepoint_discover_3'] = _("ERROR_SAFEPOINT_DISCOVER_NOTFOUND") . " (35403)";
        $errors['safepoint_discover_4'] = _("ERROR_SAFEPOINT_DISCOVER_UNAUTHORIZED") . " (35404)";
        $errors['safepoint_discover_7'] = _("ERROR_SAFEPOINT_DISCOVER_INVALID") . " (35407)";
        $errors['safepoint_discover_unk'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (35440)";
        $errors['safepoint_discover_timeout'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_TIMEOUT") . " (35441)";
        $errors['safepoint_discover_unk_error'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_UNKNOWN") . " (35442)";
        $errors['safepoint_discover_parsererror'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35443)";
        $errors['safepoint_discover_400'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_BAD_REQUEST") . " (35444)";
        $errors['safepoint_discover_401'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35445)";
        $errors['safepoint_discover_403'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_FORBIDDEN") . " (35446)";
        $errors['safepoint_discover_404'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35447)";
        $errors['safepoint_discover_500'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35448)";
        $errors['safepoint_discover_error'] = _("LABEL_DISCOVERING_SAFEPOINT_ON_NETWORK_DEVICE") . ' ' . _("ERROR_USER_ABORT") . " (35449)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint GetList API errors (5500 range) 
        /* Legacy Sequoia
        $errors['safepoint_getlist_2'] = _("ERROR_SAFEPOINT_GET_LIST_FAILED") . " (35502)";
        $errors['safepoint_getlist_500'] = _("LABEL_RETRIEVING_SAFEPOINT_LIST_ON_NETWORK_DEVICE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35550)";
        $errors['safepoint_getlist_400'] = _("LABEL_RETRIEVING_SAFEPOINT_LIST_ON_NETWORK_DEVICE") . ' ' . _("ERROR_BAD_REQUEST") . " (35551)";
        $errors['safepoint_getlist_401'] = _("LABEL_RETRIEVING_SAFEPOINT_LIST_ON_NETWORK_DEVICE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35552)";
        $errors['safepoint_getlist_403'] = _("LABEL_RETRIEVING_SAFEPOINT_LIST_ON_NETWORK_DEVICE") . ' ' . _("ERROR_FORBIDDEN") . " (35552)";
        $errors['safepoint_getlist_404'] = _("LABEL_RETRIEVING_SAFEPOINT_LIST_ON_NETWORK_DEVICE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35552)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint GetStatus API errors (356xx range) 
        /* Legacy Sequoia
        $errors['safepoint_getstatus_2'] = _("ERROR_SAFEPOINT_GET_STATUS_FAILED") . " (35602)";
        $errors['safepoint_getstatus_3'] = _("ERROR_SAFEPOINT_GET_STATUS_NOTFOUND") . " (35603)";
        $errors['safepoint_getstatus_6'] = _("ERROR_SAFEPOINT_GET_STATUS_NOSPACE") . " (35606)";
        $errors['safepoint_getstatus_7'] = _("ERROR_SAFEPOINT_GET_STATUS_INVALID") . " (35607)";
        $errors['safepoint_getstatus_9'] = _("ERROR_SAFEPOINT_GET_STATUS_UNREACHABLE") . " (35609)";
        $errors['safepoint_getstatus_14'] = _("ERROR_SAFEPOINT_GET_STATUS_UNAVAILABLE") . " (35614)";
        $errors['safepoint_getstatus_unk'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (35640)";
        $errors['safepoint_getstatus_timeout'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_TIMEOUT") . " (35641)";
        $errors['safepoint_getstatus_unk_error'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_UNKNOWN") . " (35642)";
        $errors['safepoint_getstatus_parsererror'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35643)";
        
        $errors['safepoint_getstatus_400'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_BAD_REQUEST") . " (35644)";
        $errors['safepoint_getstatus_401'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35645)";
        $errors['safepoint_getstatus_403'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_FORBIDDEN") . " (35646)";
        $errors['safepoint_getstatus_404'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35647)";
        $errors['safepoint_getstatus_500'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35648)";
        $errors['safepoint_getstatus_error'] = _("LABEL_GET_SAFEPOINT_PROGRESS") . ' ' . _("ERROR_USER_ABORT") . " (35649)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint GetSchedule API errors (357xx range) 
        /* Legacy Sequoia
        $errors['safepoint_getschedule_2'] = _("ERROR_SAFEPOINT_GET_SCHEDULE_FAILED") . " (35702)";
        $errors['safepoint_getschedule_3'] = _("ERROR_SAFEPOINT_GET_SCHEDULE_NOT_FOUND") . " (35703)";
        $errors['safepoint_getschedule_7'] = _("ERROR_SAFEPOINT_GET_SCHEDULE_INVALID") . " (35707)";
        $errors['safepoint_getschedule_10'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_NOT_SUPPORTED") . " (35710)";
        $errors['safepoint_getschedule_13'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_SAFEPOINT_NOT_CREATED") . " (35714)";
        $errors['safepoint_getschedule_14'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_UNAVAILABLE") . " (35714)";
        $errors['safepoint_getschedule_15'] = _("ERROR_SAFEPOINT_GET_SCHEDULE_CORRUPTED") . " (35715)";
        $errors['safepoint_getschedule_unk'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (35740)";
        $errors['safepoint_getschedule_timeout'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_TIMEOUT") . " (35741)";
        $errors['safepoint_getschedule_unk_error'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_UNKNOWN") . " (35742)";
        $errors['safepoint_getschedule_parsererror'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35743)";
        $errors['safepoint_getschedule_400'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_BAD_REQUEST") . " (35744)";
        $errors['safepoint_getschedule_401'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35745)";
        $errors['safepoint_getschedule_403'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_FORBIDDEN") . " (35746)";
        $errors['safepoint_getschedule_404'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35747)";
        $errors['safepoint_getschedule_500'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35748)";
        $errors['safepoint_getschedule_error'] = _("LABEL_GET_SAFEPOINT_SCHEDULE_INFORMATION") . ' ' . _("ERROR_USER_ABORT") . " (35749)"; 
        */ 
        
        //--------------- Backups->SafePoint Discovery API errors (358xx range) 
        /* Legacy Sequoia
        $errors['nas_discover_2'] = _("ERROR_NAS_DISCOVER_FAILED") . " (35802)";
        $errors['nas_discover_16'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_ABORTED") . " (35816)";
        $errors['nas_discover_unk'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_UNKNOWN") . " (35840)";
        $errors['nas_discover_timeout'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_TIMEOUT") . " (35841)";
        $errors['nas_discover_unk_error'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_UNKNOWN") . " (35842)";
        $errors['nas_discover_parsererror'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35843)";
        $errors['nas_discover_500'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35844)";
        $errors['nas_discover_400'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_BAD_REQUEST") . " (35845)";
        $errors['nas_discover_401'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (35846)";
        $errors['nas_discover_403'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_FORBIDDEN") . " (35847)";
        $errors['nas_discover_404'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (35848)";
        $errors['nas_discover_error'] = _("LABEL_DISCOVERING_NETWORK_DEVICES") . ' ' . _("ERROR_USER_ABORT") . " (35849)"; 
        */ 
        
        //--------------- Backups->SafePoint Cancel Discovery API errors (359xx range) 
        /* Legacy Sequoia
        $errors['nas_cancel_2'] = _("LABEL_CANCELLING_DISCOVERY") . ' ' . _("ERROR_FAILED") . " (35902)";
        $errors['nas_cancel_unk'] = _("LABEL_CANCELLING_DISCOVERY") . ' ' . _("ERROR_UNKNOWN") . " (35940)";
        $errors['nas_cancel_timeout'] = _("LABEL_CANCELLING_DISCOVERY") . ' ' . _("ERROR_TIMEOUT") . " (35941)";
        $errors['nas_cancel_unk_error'] = _("LABEL_CANCELLING_DISCOVERY") . ' ' . _("ERROR_UNKNOWN") . " (35942)";
        $errors['nas_cancel_parsererror'] = _("LABEL_CANCELLING_DISCOVERY") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (35944)";
        $errors['nas_cancel_error'] = _("LABEL_CANCELLING_DISCOVERY") . ' ' . _("ERROR_USER_ABORT") . " (35945)"; 
        */ 
         
        
        //--------------- Backups->SafePoint POST, PUT, and DELETE API errors (36100-36999 range) 
        
        //--------------- Backups->SafePoint SafePoint Create API errors (361xx range) 
        /* Legacy Sequoia
        $errors['safepoint_create_2'] = _("ERROR_SAFEPOINT_CREATE_FAILED") . " (36102)";
        $errors['safepoint_create_3'] = _("ERROR_SAFEPOINT_CREATE_NOT_FOUND") . " (36103)";
        $errors['safepoint_create_4'] = _("ERROR_SAFEPOINT_CREATE_UNAUTHORIZED") . " (36104)";
        $errors['safepoint_create_5'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36105)";
        $errors['safepoint_create_6'] = _("ERROR_SAFEPOINT_CREATE_NOSPACE") . " (36106)";
		$errors['safepoint_create_7'] = _("ERROR_SAFEPOINT_CREATE_INVALID") . " (36107)";
        $errors['safepoint_create_10'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_NOT_SUPPORTED") . " (36110)";
        $errors['safepoint_create_11'] = _("ERROR_SAFEPOINT_CREATE_DUPLICATE") . " (36111)";
		$errors['safepoint_create_14'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_UNAVAILABLE") . " (36114)";
        $errors['safepoint_create_16'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_ABORTED") . " (36116)";
        $errors['safepoint_create_18'] = _("ERROR_SAFEPOINT_CREATE_NOT_ALLOWED") . " (36118)";
        
        $errors['safepoint_create_bad'] = _("ERROR_SAFEPOINT_CREATE_FAILED") . " (36121)";
        $errors['safepoint_create_not_complete'] = _("ERROR_SAFEPOINT_CREATE_INVALID") . " (36122)";
        $errors['safepoint_create_failed'] = _("ERROR_SAFEPOINT_CREATE_FAILED") . " (36123)";
        $errors['safepoint_create_notfound'] = _("ERROR_SAFEPOINT_CREATE_NOT_FOUND") . " (36124)";
        $errors['safepoint_create_unauthorized'] = _("ERROR_SAFEPOINT_CREATE_UNAUTHORIZED") . " (36125)";
        $errors['safepoint_create_busy'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36126)";
        $errors['safepoint_create_nospace'] = _("ERROR_SAFEPOINT_CREATE_NOSPACE") . " (36127)";
        $errors['safepoint_create_invalid'] = _("ERROR_SAFEPOINT_CREATE_INVALID") . " (36128)";
        //$errors['safepoint_create_notsupported'] = _("ERROR_SAFEPOINT_CREATE_NOTSUPPORTED") . " (36129)";
        $errors['safepoint_create_duplicate'] = _("ERROR_SAFEPOINT_CREATE_DUPLICATE") . " (36130)";
        //$errors['safepoint_create_unavailable'] = _("ERROR_SAFEPOINT_CREATE_UNAVAILABLE") . " (36131)";
        $errors['safepoint_create_notallowed'] = _("ERROR_SAFEPOINT_CREATE_NOT_ALLOWED") . " (36132)";
        
        $errors['safepoint_create_unk'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36140)";
        $errors['safepoint_create_timeout'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_TIMEOUT") . " (36141)";
        $errors['safepoint_create_unk_error'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36142)";
        $errors['safepoint_create_parsererror'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36143)";
        $errors['safepoint_create_error'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_USER_ABORT") . " (36144)";
        
        $errors['safepoint_create_50'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36150)";
        $errors['safepoint_create_60'] = _("ERROR_SAFEPOINT_CREATE_BAD_TIME_VALUE") . " (36160)";
        
        $errors['safepoint_create_400'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_BAD_REQUEST") . " (36171)";
        $errors['safepoint_create_401'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36172)";
        $errors['safepoint_create_403'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_FORBIDDEN") . " (36173)";
        $errors['safepoint_create_404'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36174)";
        $errors['safepoint_create_500'] = _("LABEL_CREATING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36175)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint Destroy API errors (362xx range) 
        /* Legacy Sequoia
        $errors['safepoint_destroy_2'] = _("ERROR_SAFEPOINT_DESTROY_FAILED") . " (36202)";
        $errors['safepoint_destroy_3'] = _("ERROR_SAFEPOINT_DESTROY_NOT_FOUND") . " (36203)";
        $errors['safepoint_destroy_5'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36205)";
        $errors['safepoint_destroy_7'] = _("ERROR_SAFEPOINT_DESTROY_INVALID") . " (36207)";
        $errors['safepoint_destroy_9'] = _("ERROR_SAFEPOINT_DESTROY_UNREACHABLE") . " (36209)";
        $errors['safepoint_destroy_10'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_NOT_SUPPORTED") . " (36210)";
        $errors['safepoint_destroy_13'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_NOT_CREATED") . " (36213)";
        $errors['safepoint_destroy_14'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_UNAVAILABLE") . " (36214)";
        $errors['safepoint_destroy_15'] = _("ERROR_SAFEPOINT_DESTROY_CORRUPTED") . " (36215)";
        $errors['safepoint_destroy_18'] = _("ERROR_SAFEPOINT_DESTROY_NOT_ALLOWED") . " (36218)";
        $errors['safepoint_destroy_unk'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36240)";
        $errors['safepoint_destroy_timeout'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_TIMEOUT") . " (36241)";
        $errors['safepoint_destroy_unk_error'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36242)";
        $errors['safepoint_destroy_parsererror'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36243)";
        $errors['safepoint_destroy_400'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_BAD_REQUEST") . " (36244)";
        $errors['safepoint_destroy_401'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36245)";
        $errors['safepoint_destroy_403'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_FORBIDDEN") . " (36246)";
        $errors['safepoint_destroy_404'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36247)";
        $errors['safepoint_destroy_500'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36248)";
        $errors['safepoint_destroy_error'] = _("LABEL_DELETING_SAFEPOINT") . ' ' . _("ERROR_USER_ABORT") . " (36249)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint Update API errors (363xx range) 
        /* Legacy Sequoia
        $errors['safepoint_update_2'] = _("ERROR_SAFEPOINT_UPDATE_FAILED") . " (36302)";
        $errors['safepoint_update_3'] = _("ERROR_SAFEPOINT_CREATE_UPDATE_NOTFOUND") . " (36303)";
        $errors['safepoint_update_5'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36305)";
        $errors['safepoint_update_6'] = _("ERROR_SAFEPOINT_UPDATE_NOSPACE") . " (36306)";
        $errors['safepoint_update_7'] = _("ERROR_SAFEPOINT_UPDATE_INVALID") . " (36307)";
        $errors['safepoint_update_10'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_NOT_SUPPORTED") . " (36310)";
        $errors['safepoint_update_11'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_DUPLICATE") . " (36311)";
        $errors['safepoint_update_13'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_NOT_CREATED") . " (36313)";
        $errors['safepoint_update_14'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_UNAVAILABLE") . " (36314)";
        $errors['safepoint_update_16'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_ABORTED") . " (36316)";
        $errors['safepoint_update_18'] = _("ERROR_SAFEPOINT_UPDATE_NOT_ALLOWED") . " (36318)";
        
        $errors['safepoint_update_bad'] = _("ERROR_SAFEPOINT_UPDATE_FAILED") . " (36321)";
        $errors['safepoint_update_not_complete'] = _("ERROR_SAFEPOINT_UPDATE_INVALID") . " (36322)";
        $errors['safepoint_update_failed'] = _("ERROR_SAFEPOINT_UPDATE_FAILED") . " (36323)";
        $errors['safepoint_update_notfound'] = _("ERROR_SAFEPOINT_CREATE_UPDATE_NOTFOUND") . " (36324)";
        $errors['safepoint_update_unauthorized'] = _("ERROR_SAFEPOINT_UPDATE_UNAUTHORIZED") . " (36325)";
        $errors['safepoint_update_busy'] = _("LABEL_SAFEPOINT_UPDATE_ABORTED") . " (36326)";
        $errors['safepoint_update_nospace'] = _("ERROR_SAFEPOINT_UPDATE_NOSPACE") . " (36327)";
        $errors['safepoint_update_invalid'] = _("ERROR_SAFEPOINT_UPDATE_INVALID") . " (36328)";
        //$errors['safepoint_update_notsupported'] = _("ERROR_SAFEPOINT_UPDATE_NOTSUPPORTED") . " (36329)";
        //$errors['safepoint_update_duplicate'] = _("ERROR_SAFEPOINT_UPDATE_DUPLICATE") . " (36330)";
        //$errors['safepoint_update_unavailable'] = _("ERROR_SAFEPOINT_UPDATE_UNAVAILABLE") . " (36331)";
        $errors['safepoint_update_notallowed'] = _("ERROR_SAFEPOINT_UPDATE_NOT_ALLOWED") . " (36332)";
        
        $errors['safepoint_update_unk'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36340)";
        $errors['safepoint_update_timeout'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_TIMEOUT") . " (36341)";
        $errors['safepoint_update_unk_error'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36342)";
        $errors['safepoint_update_parsererror'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36343)";
        $errors['safepoint_update_error'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_USER_ABORT") . " (36344)";
        $errors['safepoint_update_50'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36350)";
        
        $errors['safepoint_update_400'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_BAD_REQUEST") . " (36351)";
        $errors['safepoint_update_401'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36352)";
        $errors['safepoint_update_403'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_FORBIDDEN") . " (36353)";
        $errors['safepoint_update_404'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36354)";
        $errors['safepoint_update_500'] = _("LABEL_UPDATING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36355)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint Restore API errors (364xx range) 
        /* Legacy Sequoia
        $errors['safepoint_restore_2'] = _("ERROR_SAFEPOINT_RESTORE_FAILED") . " (36402)";
        $errors['safepoint_restore_3'] = _("ERROR_SAFEPOINT_RESTORE_NOTFOUND") . " (36403)";
        $errors['safepoint_restore_5'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36405)";
        $errors['safepoint_restore_6'] = _("ERROR_SAFEPOINT_RESTORE_NOSPACE") . " (36406)";
        $errors['safepoint_restore_7'] = _("ERROR_SAFEPOINT_RESTORE_INVALID") . " (36407)";
        $errors['safepoint_restore_9'] = _("ERROR_SAFEPOINT_RESTORE_UNREACHABLE") . " (36409)";
        $errors['safepoint_restore_10'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_NOT_SUPPORTED") . " (36410)";
        $errors['safepoint_restore_11'] = _("ERROR_SAFEPOINT_RESTORE_DUPLICATE") . " (36411)";
        $errors['safepoint_restore_14'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_UNAVAILABLE") . " (36414)";
        $errors['safepoint_restore_15'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_CORRUPTED") . " (36415)";
        $errors['safepoint_restore_16'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_ABORTED") . " (36416)";
        $errors['safepoint_restore_18'] = _("ERROR_SAFEPOINT_RESTORE_NOT_FACTORY_FRESH") . " (36418)";
        $errors['safepoint_restore_19'] = _("ERROR_SAFEPOINT_RESTORE_NOT_USABLE") . " (36419)";
        
        $errors['safepoint_restore_bad'] = _("ERROR_SAFEPOINT_RESTORE_FAILED") . " (36421)";
        $errors['safepoint_restore_not_complete'] = _("ERROR_SAFEPOINT_RESTORE_INVALID") . " (36422)";
        $errors['safepoint_restore_failed'] = _("ERROR_SAFEPOINT_RESTORE_FAILED") . " (36423)";
        $errors['safepoint_restore_notfound'] = _("ERROR_SAFEPOINT_RESTORE_NOTFOUND") . " (36424)";
        //$errors['safepoint_restore_unauthorized'] = _("ERROR_SAFEPOINT_RESTORE_UNAUTHORIZED") . " (36425)";
        $errors['safepoint_restore_busy'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36426)";
        $errors['safepoint_restore_nospace'] = _("ERROR_SAFEPOINT_RESTORE_NOSPACE") . " (36427)";
        $errors['safepoint_restore_invalid'] = _("ERROR_SAFEPOINT_RESTORE_INVALID") . " (36428)";
        //$errors['safepoint_restore_notsupported'] = _("ERROR_SAFEPOINT_RESTORE_NOTSUPPORTED") . " (36429)";
        $errors['safepoint_restore_duplicate'] = _("ERROR_SAFEPOINT_RESTORE_DUPLICATE") . " (36430)";
        //$errors['safepoint_restore_unavailable'] = _("ERROR_SAFEPOINT_RESTORE_UNAVAILABLE") . " (36431)";
        $errors['safepoint_restore_notallowed'] = _("ERROR_SAFEPOINT_RESTORE_NOT_FACTORY_FRESH") . " (36432)";
        $errors['safepoint_restore_unreachable'] = _("ERROR_SAFEPOINT_RESTORE_UNREACHABLE") . " (36433)";
        $errors['safepoint_restore_corrupted'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_CORRUPTED") . " (36434)";
        $errors['safepoint_restore_notusable'] = _("ERROR_SAFEPOINT_RESTORE_NOT_USABLE") . " (36435)";
        
        $errors['safepoint_restore_unk'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36440)";
        $errors['safepoint_restore_timeout'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_TIMEOUT") . " (36441)";
        $errors['safepoint_restore_unk_error'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_UNKNOWN") . " (36442)";
        $errors['safepoint_restore_parsererror'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36443)";
        $errors['safepoint_restore_error'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_USER_ABORT") . " (36444)";
        $errors['safepoint_restore_50'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36450)";
        
        $errors['safepoint_restore_400'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_BAD_REQUEST") . " (36460)";
        $errors['safepoint_restore_401'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36451)";
        $errors['safepoint_restore_403'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_FORBIDDEN") . " (36452)";
        $errors['safepoint_restore_404'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36453)";
        $errors['safepoint_restore_500'] = _("LABEL_RESTORING_SAFEPOINT") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36454)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint SetInfo API errors (365xx range) 
        /* Legacy Sequoia
        $errors['safepoint_setinfo_2'] = _("ERROR_SAFEPOINT_SET_INFO_FAILED") . " (36502)";
        $errors['safepoint_setinfo_3'] = _("ERROR_SAFEPOINT_SET_INFO_NOTFOUND") . " (36503)";
        $errors['safepoint_setinfo_4'] = _("ERROR_SAFEPOINT_SET_INFO_UNAUTHORIZED") . " (36504)";
        $errors['safepoint_setinfo_7'] = _("ERROR_SAFEPOINT_SET_INFO_INVALID") . " (36507)";
        $errors['safepoint_setinfo_11'] = _("ERROR_SAFEPOINT_SET_INFO_DUPLICATE") . " (36511)";
        $errors['safepoint_setinfo_13'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_SAFEPOINT_NOT_CREATED") . " (36513)";
        $errors['safepoint_setinfo_14'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_UNAVAILABLE") . " (36514)";
        $errors['safepoint_setinfo_15'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_CORRUPTED") . " (36515)";
        
        $errors['safepoint_setinfo_unk'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_UNKNOWN") . " (36540)";
        $errors['safepoint_setinfo_timeout'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_TIMEOUT") . " (36541)";
        $errors['safepoint_setinfo_unk_error'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_UNKNOWN") . " (36542)";
        $errors['safepoint_setinfo_parsererror'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36543)";
        $errors['safepoint_setinfo_error'] = _("LABEL_UPDATING_SAFEPOINT_SETTINGS") . ' ' . _("ERROR_USER_ABORT") . " (36544)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint SetSchedule API errors (366xx range) 
        /* Legacy Sequoia
        $errors['safepoint_setschedule_2'] = _("ERROR_SAFEPOINT_SET_SCHEDULE_FAILED") . " (36602)";
        $errors['safepoint_setschedule_3'] = _("ERROR_SAFEPOINT_SET_SCHEDULE_NOT_FOUND") . " (36603)";
        $errors['safepoint_setschedule_7'] = _("ERROR_SAFEPOINT_SET_SCHEDULE_INVALID") . " (36607)";
        $errors['safepoint_setschedule_11'] = _("ERROR_SAFEPOINT_SET_SCHEDULE_DUPLICATE") . " (36611)";
        $errors['safepoint_setschedule_13'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_SAFEPOINT_NOT_CREATED") . " (36613)";
        $errors['safepoint_setschedule_14'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_UNAVAILABLE") . " (36614)";
        $errors['safepoint_setschedule_15'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_CORRUPTED") . " (36615)";
        $errors['safepoint_setschedule_18'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_NOT_ALLOWED") . " (36618)";
        
        $errors['safepoint_setschedule_unk'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_UNKNOWN") . " (36640)";
        $errors['safepoint_setschedule_timeout'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_TIMEOUT") . " (36641)";
        $errors['safepoint_setschedule_unk_error'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_UNKNOWN") . " (36642)";
        $errors['safepoint_setschedule_parsererror'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36643)";
        $errors['safepoint_setschedule_error'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_USER_ABORT") . " (36644)";
        
        $errors['safepoint_setschedule_400'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_BAD_REQUEST") . " (36650)";
        $errors['safepoint_setschedule_401'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36651)";
        $errors['safepoint_setschedule_403'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_FORBIDDEN") . " (36652)";
        $errors['safepoint_setschedule_404'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36652)";
        $errors['safepoint_setschedule_500'] = _("LABEL_UPDATING_SAFEPOINT_SCHEDULE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36653)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint Cancel API errors (367xx range) 
        /* Legacy Sequoia
        $errors['safepoint_cancel_2'] = _("ERROR_SAFEPOINT_CANCEL_FAILED") . " (36702)";
        $errors['safepoint_cancel_3'] = _("ERROR_SAFEPOINT_CANCEL_NOT_FOUND") . " (36703)";
        $errors['safepoint_cancel_4'] = _("ERROR_SAFEPOINT_CANCEL_UNAUTHORIZED") . " (36704)";
        $errors['safepoint_cancel_5'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36705)";
        //$errors['safepoint_cancel_6'] = _("ERROR_SAFEPOINT_CANCEL_NOSPACE") . " (36706)";
        $errors['safepoint_cancel_7'] = _("ERROR_SAFEPOINT_CANCEL_INVALID") . " (36707)";
        $errors['safepoint_cancel_10'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_NOT_SUPPORTED") . " (36710)";
        //$errors['safepoint_cancel_11'] = _("ERROR_SAFEPOINT_CANCEL_DUPLICATE") . " (36711)";
        $errors['safepoint_cancel_14'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_UNAVAILABLE") . " (36714)";
        $errors['safepoint_cancel_16'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_ABORTED") . " (36716)";
        $errors['safepoint_cancel_18'] = _("ERROR_SAFEPOINT_CANCEL_NOT_ALLOWED") . " (36718)";
        
        $errors['safepoint_cancel_unk'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_UNKNOWN") . " (36740)";
        $errors['safepoint_cancel_timeout'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_TIMEOUT") . " (36741)";
        $errors['safepoint_cancel_unk_error'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_UNKNOWN") . " (36742)";
        $errors['safepoint_cancel_parsererror'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36743)";
        $errors['safepoint_cancel_error'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_USER_ABORT") . " (36744)";
        $errors['safepoint_cancel_50'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36750)";
        
        $errors['safepoint_cancel_400'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_BAD_REQUEST") . " (36760)";
        $errors['safepoint_cancel_401'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36761)";
        $errors['safepoint_cancel_403'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_FORBIDDEN") . " (36762)";
        $errors['safepoint_cancel_404'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36763)";
        $errors['safepoint_cancel_500'] = _("LABEL_CANCELLING_SAFEPOINT_CREATE_UPDATE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36764)"; 
        */ 
        
        //--------------- Backups->SafePoint SafePoint Cancel Restore API errors (368xx range) 
        /* Legacy Sequoia
        $errors['safepoint_cancel_restore_2'] = _("ERROR_SAFEPOINT_CANCEL_FAILED") . " (36802)";
        $errors['safepoint_cancel_restore_3'] = _("ERROR_SAFEPOINT_CANCEL_NOT_FOUND") . " (36803)";
        $errors['safepoint_cancel_restore_4'] = _("ERROR_SAFEPOINT_CANCEL_UNAUTHORIZED") . " (36804)";
        $errors['safepoint_cancel_restore_5'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36805)";
        //$errors['safepoint_cancel_restore_6'] = _("ERROR_SAFEPOINT_CANCEL_NOSPACE") . " (36806)";
        $errors['safepoint_cancel_restore_7'] = _("ERROR_SAFEPOINT_CANCEL_INVALID") . " (36807)";
        $errors['safepoint_cancel_restore_10'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_NOT_SUPPORTED") . " (36810)";
        //$errors['safepoint_cancel_restore_11'] = _("ERROR_SAFEPOINT_CANCEL_DUPLICATE") . " (36811)";
        $errors['safepoint_cancel_restore_14'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_UNAVAILABLE") . " (36814)";
        $errors['safepoint_cancel_restore_16'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_ABORTED") . " (36816)";
        $errors['safepoint_cancel_restore_18'] = _("ERROR_SAFEPOINT_CANCEL_NOT_ALLOWED") . " (36818)";
        
        $errors['safepoint_cancel_restore_unk'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_UNKNOWN") . " (36840)";
        $errors['safepoint_cancel_restore_timeout'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_TIMEOUT") . " (36841)";
        $errors['safepoint_cancel_restore_unk_error'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_UNKNOWN") . " (36842)";
        $errors['safepoint_cancel_restore_parsererror'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36843)";
        $errors['safepoint_cancel_restore_error'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_USER_ABORT") . " (36844)";
        $errors['safepoint_cancel_restore_50'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_SAFEPOINT_BUSY") . " (36850)";
        
        $errors['safepoint_cancel_restore_400'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_BAD_REQUEST") . " (36860)";
        $errors['safepoint_cancel_restore_401'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (36861)";
        $errors['safepoint_cancel_restore_403'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_FORBIDDEN") . " (36862)";
        $errors['safepoint_cancel_restore_404'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_SERVICE_NOT_FOUND") . " (36863)";
        $errors['safepoint_cancel_restore_500'] = _("LABEL_CANCELLING_SAFEPOINT_RESTORE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (36864)"; 
        */ 

//----------------------------------------------------------------------------------//
// SEQUOIA / AVATAR error codes                                                              //
//----------------------------------------------------------------------------------//

//--------------- Reserved legacy errors (30000 range - see above)

//--------------- Generic errors (200,000 + 1, 2, 3,...)
        $errors['unk'] = _("ERROR_UNKNOWN") . " (200000)";
        $errors['timeout'] = _("ERROR_AVATAR_TIMEOUT") . " (200001)";
        $errors['system_error'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (200002)";
        $errors['parsererror'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (200003)";
        $errors['get_unk'] = _("ERROR_GET_UNKNOWN_ERROR") . " (200004)";
        $errors['get_error'] = _("ERROR_GET_ERROR") . " (200005)";
        $errors['connection_lost'] = _("ERROR_CONNECTION_LOST") . " (200006)";

//--------------- Standard HTTP error codes (200,000 + http_code)
        $errors['http_400'] = _("ERROR_BAD_REQUEST") . " (200400)";
        $errors['http_401'] = _("ERROR_NOT_AUTHORIZED_TASK") . " (200401)";
        $errors['http_403'] = _("ERROR_FORBIDDEN") . " (200403)";
        $errors['http_404'] = _("ERROR_SERVICE_NOT_FOUND") . " (200404)";
        $errors['http_405'] = _("ERROR_SERVICE_NOT_ALLOWED") . " (200405)";
        $errors['http_500'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (200500)";
        $errors['http_503'] = _("ERROR_SERVICE_NOT_FOUND") . " (200503)";

//--------------- Toolbar (USB, Alerts, & Help) error codes (210,000 - 219,999 range)

//--------------- Home / Dashboard error codes (220,000 - 229,999 range)
        $errors['get_storage_usage_http_500'] = _("ERROR_STRING_GET_STORAGE_USAGE") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (220001)";
        $errors['get_mediacrawler_status_http_500'] = _("ERROR_STRING_GET_MEDIA_CRAWLER") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (220002)";

        $errors['login_username'] = _("GLOB_NAV_LOGIN_STRING_LOGIN_INTRO"); // . " (220003)";

        $errors['internet_access_error'] = _("ERROR_NO_INTERNET_CONNECTIVITY") . " (220004)";

        $errors['low_battery_for_upgrade'] = _("ERROR_UPGRADE_INSUFFICIENT_POWER") . " (220005)";
        $errors['low_battery_for_plex_upgrade'] = _("ERROR_PLEX_UPGRADE_INSUFFICIENT_POWER") . " (220006)";
		
        $errors['create_login_password'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");
        //$errors['create_login_password_confirm'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");
        //$errors['create_login_password_confirm_not_match'] = _("ERROR_MAKE_SURE_THE_PASSWORDS_ARE_IDENTICAL");

        $errors['wpa_password_error'] = _("ERROR_WPA_NETWORK_PASSWORD_INVALID_SYNTAX");
        $errors['wep_password_error'] = _("ERROR_WEP_NETWORK_PASSWORD_INVALID_SYNTAX");
        $errors['password_not_match'] = _("ERROR_MAKE_SURE_THE_PASSWORDS_ARE_IDENTICAL");

        $errors['create_network_ssid'] = _("ERROR_WIFI_NAME_BLANK");
        $errors['ssidname_begin_end_space'] = _("ERROR_SSID_INVALID_SYNTAX_BEGINNING_ENDING_CHARACTER");
        $errors['ssidname_invalid_syntax'] = _("ERROR_SSID_INVALID_SYNTAX");
        
        //$errors['create_network_password_wpa'] = _("ERROR_WPA_NETWORK_PASSWORD_INVALID_SYNTAX");
        //$errors['create_network_password_confirm'] = _("ERROR_WPA_NETWORK_PASSWORD_INVALID_SYNTAX");
        //$errors['create_network_password_confirm_not_match'] = _("ERROR_MAKE_SURE_THE_PASSWORDS_ARE_IDENTICAL");

        //$errors['wifi_edit_config_form_password_wep'] = _("ERROR_WEP_NETWORK_PASSWORD_INVALID_SYNTAX");
        //$errors['wifi_edit_config_form_password_wpa'] = _("ERROR_WPA_NETWORK_PASSWORD_INVALID_SYNTAX");
        //$errors['wifi_edit_config_form_password_confirm'] = _("ERROR_WPA_NETWORK_PASSWORD_INVALID_SYNTAX");
        //$errors['wifi_edit_config_form_password_confirm_not_match'] = _("ERROR_MAKE_SURE_THE_PASSWORDS_ARE_IDENTICAL");

        $errors['wifi_edit_config_form_ssid'] = _("ERROR_WIFI_NAME_BLANK");

        $errors['wifi_signin_form_password'] = _("ERROR_WIFI_PASSWORD_BLANK");
        $errors['wifi_signin_form_password_show'] = _("ERROR_WIFI_PASSWORD_BLANK");
        $errors['wifi_signin_to_other_network_form_password'] = _("ERROR_WIFI_PASSWORD_BLANK");
        $errors['wifi_signin_to_other_network_form_password_show'] = _("ERROR_WIFI_PASSWORD_BLANK");
        $errors['wifi_signin_to_other_network_form_ssid'] = _("ERROR_WIFI_NAME_BLANK");
        $errors['wifi_signin_to_other_network_form_ssid_h'] = _("ERROR_WIFI_NAME_BLANK");
        $errors['wifi_signin_wps_pin'] = _("ERROR_WPS_PIN");

        $errors['alerts_form_error'] = _("ERROR_ALERTS_INTERNAL_SERVER_ERROR");

        $errors['current_wifi_client_connection_10_wps_pin'] = _("ERROR_CURRENT_WIFI_CLIENT_CONNECTION_ERROR_10_INCORRECT_PIN");
        $errors['current_wifi_client_connection_10'] = _("ERROR_CURRENT_WIFI_CLIENT_CONNECTION_ERROR_10_INCORRECT_PASSWORD");
        $errors['current_wifi_client_connection_15'] = _("ERROR_CURRENT_WIFI_CLIENT_CONNECTION_ERROR_15");
        $errors['current_wifi_client_connection_20'] = _("ERROR_CURRENT_WIFI_CLIENT_CONNECTION_ERROR_20");
        $errors['current_wifi_client_connection_25'] = _("ERROR_CURRENT_WIFI_CLIENT_CONNECTION_ERROR_25");

//--------------- Users error codes (230,000 - 239,999 range)
        $errors['edit_users_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS");  // . " (230001)";
        $errors['edit_users_username_form_username'] = _("ERROR_USERNAME_INCORRECT_SYNTAX");  // . " (230002)";
        $errors['edit_users_username_form_username_dash'] = _("ERROR_USERNAME_INCORRECT_SYNTAX_DASH");
        $errors['edit_users_first_name_first_name'] = _("ERROR_EDIT_USER_FIRST_NAME_INCORRECT_SYNTAX");  // . " (230003)";
        $errors['edit_users_last_name_last_name'] = _("ERROR_LAST_NAME_INCORRECT_SYNTAX");  // . " (230004)";

        $errors['reserved_username'] = _("ERROR_USERNAME_RESERVED"); // . " (230005)";
        $errors['reserved_first_name'] = _("ERROR_NAME_RESERVED");  // . " (230006)";

        $errors['create_user_first_name'] = _("ERROR_ADD_USER_FIRST_NAME_INCORRECT_SYNTAX"); // . " (230007)";
        $errors['create_user_first_name_dash'] = _("ERROR_ADD_USER_FIRST_NAME_INCORRECT_SYNTAX_DASH");
        $errors['create_user_last_name'] = _("ERROR_LAST_NAME_INCORRECT_SYNTAX"); // . " (230008)";

        $errors['SettingsEmail'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); // . " (230009)";
        $errors['create_user_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS");  // . " (230010)";

        $errors['create_user_confirm_password'] = _("ERROR_PASSWORDS_DONT_MATCH");  // . " (230011)";
        
        /* Legacy Sequoia
        $errors['getting_started_wizard_add_user_edit_admin_username'] = _("ERROR_ADD_USER_FIRST_NAME_INCORRECT_SYNTAX");  // . " (230012)";
        $errors['getting_started_wizard_add_user_edit_admin_username_dash'] = _("ERROR_ADD_USER_FIRST_NAME_INCORRECT_SYNTAX_DASH");  // . " (230013)";
        $errors['getting_started_wizard_add_user_edit_admin_lastname'] = _("ERROR_LAST_NAME_INCORRECT_SYNTAX");  // . " (230014)";
        $errors['getting_started_wizard_add_user_edit_admin_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS");  // . " (230015)";
        
        $errors['getting_started_wizard_register_form_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS");        
        
        $errors['getting_started_wizard_add_user_username'] = _("ERROR_ADD_USER_FIRST_NAME_INCORRECT_SYNTAX"); // . " (230016)";
        $errors['getting_started_wizard_add_user_username_dash'] = _("ERROR_ADD_USER_FIRST_NAME_INCORRECT_SYNTAX_DASH"); // . " (230017)";
        $errors['getting_started_wizard_add_user_lastname'] = _("ERROR_LAST_NAME_INCORRECT_SYNTAX");  // . " (230018)";
        $errors['getting_started_wizard_add_user_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS");  // . " (230019)"; 
        */ 

        $errors['edit_old_user_password'] = _("ERROR_OLD_PASSWORD_INCORRECT_SYNTAX");
        $errors['edit_user_password'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");  // . " (230020)";
        $errors['edit_user_password_show'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");  // . " (230020)";
        //$errors['edit_user_password_confirm'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");  // . " (230021)";
        //$errors['edit_user_password_confirm_not_match'] = _("ERROR_MAKE_SURE_THE_PASSWORDS_ARE_IDENTICAL");  // . " (230022)";

        /* Legacy Sequoia
        $errors['delete_users_http_400'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_BAD_REQUEST") . " (230023)";
        $errors['delete_users_http_401'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_NOT_AUTHORIZED_TASK") . " (230024)";
        $errors['delete_users_http_403'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_FORBIDDEN") . " (230025)";
        $errors['delete_users_http_404'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_USER_NOT_FOUND") . " (230026)";
        $errors['delete_users_http_500'] = _("LABEL_DELETING_USER") . ' ' . _("ERROR_USER_DELETE_FAILED") . " (230027)";
        */ 

        $errors['settings_admin_user_form_password'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");
        //$errors['settings_admin_user_form_password_confirm'] = _("AVATAR_ERROR_PASSWORD_INCORRECT_SYNTAX");
        //$errors['settings_admin_user_form_password_confirm_not_match'] = _("ERROR_MAKE_SURE_THE_PASSWORDS_ARE_IDENTICAL");

//--------------- Shares error codes (240,000 - 249,999 range)
        /* Legacy Sequoia
        $errors['create_share_name'] = _("ERROR_SHARE_NAME_INCORRECT_SYNTAX");  // . " (240001)";
        $errors['create_share_description'] = _("ERROR_SHARE_DESCRIPTION_INCORRECT_SYNTAX");  // . " (240002)";

        $errors['share_new_share_name'] = _("ERROR_SHARE_NAME_INCORRECT_SYNTAX");  // . " (240003)";
        $errors['share_description'] = _("ERROR_SHARE_DESCRIPTION_INCORRECT_SYNTAX");  // . " (240004)";

        $errors['reserved_sharename'] = _("ERROR_SHARE_NAME_RESERVED");  // . " (240005)";
        */ 

//--------------- Remote Access / Personal Cloud error codes (250,000 - 259,999 range)
        /* Legacy Sequoia
        $errors['create_wd2go_account_sender'] = _("ERROR_PROVIDE_VALID_NAME"); // . " (250001)";
        $errors['create_wd2go_account_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); // . " (250002)";
        $errors['edit_wd2go_account_email'] = _("ERROR_PROVIDE_VALID_EMAIL_ADDRESS"); // . " (250003)";

        $errors['post_device_user_getcode_failed'] = _("ERROR_MOBILEACCESS_CREATE_FAILED") . " (250004)";
        $errors['post_device_user_clouddevices_add_failed'] = _("ERROR_MOBILEACCESS_CREATE_FAILED") . " (250005)";
        $errors['post_device_user_webuser_failed'] = _("ERROR_WEBACCOUNT_CREATE_FAILED") . " (250006)";
        $errors['post_device_user_email_failed'] = _("ERROR_WEBACCOUNT_CREATE_FAILED") . " (250007)";
        $errors['post_device_user_email_wizard_admin_failed'] = _("ERROR_WEBACCOUNT_CREATE_FAILED") . " (250008)";
        $errors['post_device_user_email_wizard_user_failed'] = _("ERROR_WEBACCOUNT_CREATE_FAILED") . " (250009)";
        $errors['post_device_user_email_edit_failed'] = _("ERROR_WEBACCOUNT_DELETE_FAILED") . " (250010)";
        $errors['delete_device_user_email_failed'] = _("ERROR_WEBACCOUNT_DELETE_FAILED") . " (250011)";

        $errors['user_created_successfully'] = _('LABEL_DESC_USER_ADDED_SUCCESSFULLY'); // . " (250012)"; 
        */ 

//--------------- Safepoint error codes (260,000 - 269,999 range)
        /* Legacy Sequoia
        $errors['replication_share_username'] = _("ERROR_SHARE_USERNAME_INCORRECT_SYNTAX");  // . " (260001)";
        $errors['replication_device_username'] = _("ERROR_DEVICE_USERNAME_INCORRECT_SYNTAX");  // . " (260003)";

        $errors['safepoint_name'] = _("ERROR_SAFEPOINT_INCORRECT_SYNTAX");  // . " (260005)";
        $errors['safepoint_detail_name'] = _("ERROR_SAFEPOINT_INCORRECT_SYNTAX");  // . " (260006)"; 
        */ 

//--------------- Reserved errors (300,000 - 309,999 range)

//--------------- Settings->General errors (310,000 - 319,999 range)
        /* Legacy Sequoia
        $errors['update_ntp_form_ntpsrv_user'] = _("ERROR_INVALID_NTP_SERVER");  // . " (310001)"; 
        */ 
        $errors['settings_device_name_form_machine_name'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_INVALID") . ' ' . _("ERROR_ENTER_ALPHANUMERIC_DEVICE_NAME");  // . " (310002)";
        $errors['settings_device_description_form_machine_desc'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_DESCRIPTION");  // . " (310003)";
        /* Legacy Sequoia
        $errors['remote_access_settings_manual_port1'] = _("ERROR_HTTP_PORTNUMBER");  // . " (310004)";
        $errors['remote_access_settings_manual_port2'] = _("ERROR_HTTPS_PORTNUMBER");  // . " (310005)";
        $errors['https_port_dup'] = _("ERROR_DUPLICATE_HTTPS_PORTNUMBER");  // . " (3100006)"; 
        */ 
        $errors['settings_device_name_form_machine_name_dash'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_INVALID") . ' ' . _("ERROR_ENTER_ALPHANUMERIC_DEVICE_NAME_DASH"); // . " (310007)";
        $errors['settings_device_name_form_machine_name_number'] = _("ERROR_ENTER_ALPHANUMERIC_DEVICE_INVALID") . ' ' . _("ERROR_ENTER_ALPHANUMERIC_DEVICE_NAME_NUMBER");  // . " (310008)";

        $errors['settings_device_name_form_error'] = _("CONTENT_SETTINGS_LABEL_DEVICE_NAME") . ': ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (310009)";
        $errors['settings_device_description_form_error'] = _("CONTENT_SETTINGS_LABEL_DESCRIPTION") . ': ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (310010)";

        $errors['factory_restore_progress_form_timeout'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310011)";
        $errors['factory_restore_progress_form_error'] = _("LABEL_GET_FACTORY_RESTORE_PROGRESS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310012)";

        $errors['battery_status_form_error'] = _("LABEL_GET_BATTERY_STATUS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310013)";
        $errors['battery_settings_power_profile_error'] = _("LABEL_GET_BATTERY_PROFILE_STATUS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310014)";
        $errors['settings_drive_lock_form_error'] = _("LABEL_GET_DRIVE_LOCK_STATUS") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310015)";
        $errors['diagnostics_tests_form_error'] = _("LABEL_GET_DIAGNOSTIC_TEST_INFORMATION") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310016)";
        $errors['settings_media_toggle_dlna_service_form_error'] = _("LABEL_GET_DLNA_SERVICE") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310017)";
        $errors['sdcard_automatic_transfer_form_error'] = _("LABEL_GET_SDCARD_AUTOMATIC_TRANSFER") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310018)";
        $errors['sdcard_after_transfer_form_error'] = _("LABEL_GET_SDCARD_AFTER_TRANSFER_OPTION") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310019)";
        $errors['ssh_form_error'] = _("LABEL_GET_SSH") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (310020)"; 

        $errors['get_jobs_500'] = _("ERROR_INTERNAL_SERVER_ERROR") . " (310021)";
        $errors['get_jobs_420'] = _("ERROR_DRIVE_OUT_OF_SPACE_TO_SYNC_SDCARD") . " (310021)";
        $errors['get_jobs_440'] = _("ERROR_DRIVE_OUT_OF_SPACE_TO_SYNC_USB") . " (310021)";
        $errors['get_jobs_450'] = _("ERROR_DELETED_FROM_SD_CARD") . " (310021)";
        $errors['get_jobs_460'] = _("ERROR_DELETED_FROM_USB") . " (310021)";
        
        $errors['get_jobs_402'] = _("ERROR_NO_SD_CARD") . " (310022)";

//--------------- Settings->Network errors (320,000 - 329,999 range)
        $errors['SettingWorkgroupName'] = _("ERROR_ENTER_ALPHANUMERIC_WORKGROUP");  // . " (320001)";

        $errors['Setting_IPADDRESS_1000'] = _("ERROR_INVALID_IP_ADDRESS");  // . " (320002)";
        $errors['Setting_IPADDRESS_1001'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_EMPTY");  // . " (320003)";
        $errors['Setting_IPADDRESS_1002'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_RESERVED_SPECIAL");  // . " (320004)";
        $errors['Setting_IPADDRESS_1003'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION");  // . " (320005)";
        $errors['Setting_IPADDRESS_1004'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_LOOPBACK");  // . " (320006)";
        $errors['Setting_IPADDRESS_1005'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_LINKLOCAL");  // . " (320007)";
        $errors['Setting_IPADDRESS_1006'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_ANYCAST");  // . " (320008)";
        $errors['Setting_IPADDRESS_1007'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_MULTICAST");  // . " (320009)";
        $errors['Setting_IPADDRESS_1008'] = _("LABEL_HEADER_IP_ADDRESS") . ': ' . _("ERROR_NETWORK_RESERVED");  // . " (320010)";
        $errors['Setting_IPADDRESS_1009'] = _("ERROR_INVALID_HOST_IPADDRESS_AND_WITH_NETMASK");  // . " (320011)";

        $errors['Setting_NETMASK_1000'] = _("ERROR_INVALID_NETMASK");  //  . " (320049)";
        $errors['Setting_NETMASK_1001'] = _("LABEL_HEADER_NETMASK") . ': ' . _("ERROR_NETWORK_EMPTY");  // . " (320012)";
        $errors['Setting_NETMASK_1002'] = _("LABEL_HEADER_NETMASK") . ': ' . _("ERROR_NETWORK_RESERVED_SPECIAL");  // . " (320013)";
        $errors['Setting_NETMASK_1009'] = _("ERROR_NETMASK_NOT_CONTIGUOUS");  // . " (320014)";

        $errors['Setting_GATEWAY_1000'] = _("ERROR_INVALID_GATEWAY"); // . " (320015)";
        $errors['Setting_GATEWAY_1001'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_EMPTY");  // . " (320016)";
        $errors['Setting_GATEWAY_1002'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_RESERVED_SPECIAL");  // . " (320017)";
        $errors['Setting_GATEWAY_1003'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION"); // . " (320018)";
        $errors['Setting_GATEWAY_1004'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_LOOPBACK");  // . " (320019)";
        $errors['Setting_GATEWAY_1005'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_LINKLOCAL");  // . " (320020)";
        $errors['Setting_GATEWAY_1006'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_ANYCAST");  // . " (320021)";
        $errors['Setting_GATEWAY_1007'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_MULTICAST");  // . " (320022)";
        $errors['Setting_GATEWAY_1008'] = _("LABEL_HEADER_GATEWAY") . ': ' . _("ERROR_NETWORK_RESERVED");  // . " (320023)";
        $errors['Setting_GATEWAY_1009'] = _("ERROR_GATEWAY_WRONG_SUBNET");  // . " (320024)";
        
        $errors['Setting_DNS_1000'] = _("ERROR_INVALID_DNS_SERVER");  // . " (320025)";
        $errors['Setting_DNS_1001'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_EMPTY");  // . " (320026)";
        $errors['Setting_DNS_1002'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL");  // . " (320027)";
        $errors['Setting_DNS_1003'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION");  // . " (320028)";
        $errors['Setting_DNS_1004'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_LOOPBACK");  // . " (320029)";
        $errors['Setting_DNS_1005'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_LINKLOCAL");  // . " (320030)";
        $errors['Setting_DNS_1006'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_ANYCAST");  // . " (320031)";
        $errors['Setting_DNS_1007'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_MULTICAST");  // . " (320032)";
        $errors['Setting_DNS_1008'] = _("LABEL_HEADER_DNS_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED");  // . " (320033)";
        
        /* Legacy Sequoia
        $errors['Setting_NTP_1000'] = _("ERROR_INVALID_NTP_SERVER");  // . " (320034)";
        $errors['Setting_NTP_1001'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_EMPTY");  // . " (320035)";
        $errors['Setting_NTP_1002'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SPECIAL");  //  . " (320036)";
        $errors['Setting_NTP_1003'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED_SELF_IDENTIFICATION");  // . " (320037)";
        $errors['Setting_NTP_1004'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_LOOPBACK");  // . " (320038)";
        $errors['Setting_NTP_1005'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_LINKLOCAL");  // . " (320039)";
        $errors['Setting_NTP_1006'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_ANYCAST");  // . " (320040)";
        $errors['Setting_NTP_1007'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_MULTICAST");  // . " (320041)";
        $errors['Setting_NTP_1008'] = _("LABEL_HEADER_PRIMARY_NTP_SERVER") . ' ' . _("ERROR_NETWORK_RESERVED");  // . " (320042)"; 
        */ 
        
        /* Legacy Sequoia
        $errors['network_lan_configuration_ping_timeout'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_TIMEOUT") . " (320043)";
        $errors['network_lan_configuration_ping_unk_error'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_UNKNOWN") . " (320044)";
        
        $errors['network_lan_configuration_parsererror'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (320045)";
        $errors['network_lan_configuration_ping_parsererror'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_INTERNAL_SERVER_ERROR") . " (320046)";
        
        $errors['network_lan_configuration_error'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_USER_ABORT") . " (320047)";
        $errors['network_lan_configuration_ping_error'] = _("LABEL_NETWORK_CONNECTIVITY_TEST") . ' ' . _("ERROR_USER_ABORT") . " (320048)";

        $errors['edit_network_lan_configuration_form_timeout'] = _("ERROR_AVATAR_TIMEOUT_IPADDRESS_CHANGED") . " (320050)";
        $errors['edit_network_lan_configuration_form_internal_error'] = _("LABEL_CONFIGURING_NETWORKS") . ' ' . _("ERROR_TIMEOUT") . " (320051)"; 
        */ 

//--------------- Settings->Media errors (330,000 - 339,999 range)

//--------------- Settings->Diagnostics/Utilities errors (340,000 - 349,999 range)
        $errors['system_factory_restore_error'] = _("CONTENT_SETTINGS_LABEL_FACTORY_RESTORE") . ': ' . _("ERROR_ID_170") . " (340001)";
        $errors['system_factory_restore_timeout'] = _("CONTENT_SETTINGS_LABEL_FACTORY_RESTORE") . ': ' . _("ERROR_AVATAR_TIMEOUT") . " (340002)";
        $errors['put_shutdown_reboot_timeout'] = _("LABEL_REBOOTING_DEVICE") . ' ' . _("ERROR_AVATAR_TIMEOUT") . " (340003)";
        $errors['restore_put_shutdown_reboot_timeout'] = _("CONTENT_SETTINGS_DIALOG_BUTTON_SWITCH_TO_QUICK") . ': ' . _("ERROR_AVATAR_TIMEOUT") . " (340004)";

//--------------- Settings->Storage (RAID) errors (350,000 - 359,999 range)

//--------------- Settings->Notifications errors (360,000 - 369,999 range)

//--------------- Settings->Firmware Update errors (370,000 - 379,999 range)
        $errors['update_200'] = _("ERROR_INVALID_FW_PACKAGE") . " (370001)";
        $errors['update_201'] = _("ERROR_OUT_OF_SPACE_FOR_UPGRADE") . " (370002)";
        $errors['update_202'] = _("ERROR_UPGRADE_DOWNLOAD_FAILED") . " (370003)";
        $errors['update_203'] = _("ERROR_UPGRADE_UNPACK_FAILED") . " (370004)";
        $errors['update_204'] = _("ERROR_UPGRADE_COPY_FAILED") . " (370005)";
        $errors['update_failed'] = _("ERROR_UPGRADE_FAILED") . " (370006)";
        //$errors['update_205'] = _("ERROR_UPGRADE_ALL_DRIVE_MUST_BE_PRESENT") . " (370007)"; 
        $errors['update_205'] = _("ERROR_PLEX_DOWNLOAD_FAILED") . " (370007)"; 
        $errors['update_plex_failed'] = _("ERROR_PLEX_INSTALL_FAILED") . " (370021)";

        $errors['update_400'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_BAD_REQUEST") . " (370008)";
        $errors['update_401'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_NOT_AUTHORIZED_TASK") . " (370009)";
        $errors['update_403'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_FORBIDDEN") . " (370010)";
        $errors['update_404'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_SERVICE_NOT_FOUND") . " (370011)";
        $errors['update_500'] = _("LABEL_UPDATING_FIRMWARE") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (370012)";

        $errors['get_firmware_info_unk'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '  . _("ERROR_UNKNOWN") . " (370013)";
        $errors['get_firmware_info_error'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (370014)";
        $errors['get_firmware_info_int_error'] = _("LABEL_GET_FIRMWARE_UPDATE_PROGRESS") . ' '  . _("ERROR_INTERNAL_SERVER_ERROR") . " (370015)";

        $errors['update_206'] = _("ERROR_UPGRADE_INSUFFICIENT_POWER") . " (3700016)"; 
        $errors['update_208'] = _("ERROR_DOWNGRAGE_OLDER_THEN_FACTORY_FIRMWARE") . " (3700021)"; 
        //$errors['update_no_return'] = _("ERROR_FIRMWARE_UPGRADE_TIMEOUT") . " (3700017)"; 
        $errors['avatar_update_no_return'] = _("ERROR_AVATAR_FIRMWARE_UPGRADE_TIMEOUT") . " (3700018)"; 
        $errors['avatar_reboot_no_return'] = _("ERROR_AVATAR_REBOOT_TIMEOUT") . " (3700019)";
        $errors['reboot_reconnect_no_return'] = _("ERROR_AVATAR_REBOOT_RECONNECT_TIMEOUT") . " (3700020)";
        
        $errors['get_content_database_error'] = _("LABEL_GET_CONTENT_DATABASE_INFORMATION");
		
//--------------- Error Codes based on error_id from API (400,000 - 409,999 range)
        $errors['error_id_0'] = _("ERROR_ID_0") . " (400000)";
        /*
        $errors['error_id_1'] = _("ERROR_ID_1") . " (400001)";
        $errors['error_id_2'] = _("ERROR_ID_2") . " (400002)";
        $errors['error_id_3'] = _("ERROR_ID_3") . " (400003)";
        $errors['error_id_4'] = _("ERROR_ID_4") . " (400004)";
        $errors['error_id_5'] = _("ERROR_ID_5") . " (400005)";
        $errors['error_id_6'] = _("ERROR_ID_6") . " (400006)";
        $errors['error_id_7'] = _("ERROR_ID_7") . " (400007)";
        $errors['error_id_8'] = _("ERROR_ID_8") . " (400008)";
        $errors['error_id_9'] = _("ERROR_ID_9") . " (400009)";
        */
        $errors['error_id_10'] = _("ERROR_ID_10") . " (400010)";
        $errors['error_id_11'] = _("ERROR_ID_11") . " (400011)";
        $errors['error_id_12'] = _("ERROR_ID_12") . " (400012)";
        $errors['error_id_13'] = _("ERROR_ID_13") . " (400013)";
        $errors['error_id_14'] = _("ERROR_ID_14") . " (400014)";
        $errors['error_id_15'] = _("ERROR_ID_15") . " (400015)";
        $errors['error_id_16'] = _("ERROR_ID_16") . " (400016)";
        $errors['error_id_17'] = _("ERROR_ID_17") . " (400017)";
        $errors['error_id_18'] = _("ERROR_ID_18") . " (400018)";
        $errors['error_id_19'] = _("ERROR_ID_19") . " (400019)";
        $errors['error_id_20'] = _("ERROR_ID_20") . " (400020)";
        $errors['error_id_21'] = _("ERROR_ID_21") . " (400021)";
        $errors['error_id_22'] = _("ERROR_ID_22") . " (400022)";
        $errors['error_id_23'] = _("ERROR_ID_23") . " (400023)";
        $errors['error_id_24'] = _("ERROR_ID_24") . " (400024)";
        $errors['error_id_25'] = _("ERROR_ID_25") . " (400025)";
        $errors['error_id_26'] = _("ERROR_ID_26") . " (400026)";
        $errors['error_id_27'] = _("ERROR_ID_27") . " (400027)";
        $errors['error_id_28'] = _("ERROR_ID_28") . " (400028)";
        $errors['error_id_29'] = _("ERROR_ID_29") . " (400029)";
        $errors['error_id_30'] = _("ERROR_ID_30") . " (400030)";
        $errors['error_id_31'] = _("ERROR_ID_31") . " (400031)";
        $errors['error_id_32'] = _("ERROR_ID_32") . " (400032)";
        $errors['error_id_33'] = _("ERROR_ID_33") . " (400033)";
        $errors['error_id_34'] = _("ERROR_ID_34") . " (400034)";
        $errors['error_id_35'] = _("ERROR_ID_35") . " (400035)";
        $errors['error_id_36'] = _("ERROR_ID_36") . " (400036)";
        $errors['error_id_37'] = _("ERROR_ID_37") . " (400037)";
        $errors['error_id_38'] = _("ERROR_ID_38") . " (400038)";
        $errors['error_id_39'] = _("ERROR_ID_39") . " (400039)";
        $errors['error_id_40'] = _("ERROR_ID_40") . " (400040)";
        $errors['error_id_41'] = _("ERROR_ID_41") . " (400041)";
        $errors['error_id_42'] = _("ERROR_ID_42") . " (400042)";
        $errors['error_id_43'] = _("ERROR_ID_43") . " (400043)";
        $errors['error_id_44'] = _("ERROR_ID_44") . " (400044)";
        $errors['error_id_45'] = _("ERROR_ID_45") . " (400045)";
        $errors['error_id_46'] = _("ERROR_ID_46") . " (400046)";
        $errors['error_id_47'] = _("ERROR_ID_47") . " (400047)";
        $errors['error_id_48'] = _("ERROR_ID_48") . " (400048)";
        $errors['error_id_49'] = _("ERROR_ID_49") . " (400049)";
        $errors['error_id_50'] = _("ERROR_ID_50") . " (400050)";
        $errors['error_id_51'] = _("ERROR_ID_51") . " (400051)";
        $errors['error_id_52'] = _("ERROR_ID_52") . " (400052)";
        $errors['error_id_53'] = _("ERROR_ID_53") . " (400053)";
        $errors['error_id_54'] = _("ERROR_ID_54") . " (400054)";
        $errors['error_id_55'] = _("ERROR_ID_55") . " (400055)";
        $errors['error_id_56'] = _("ERROR_ID_56") . " (400056)";
        $errors['error_id_57'] = _("ERROR_ID_57") . " (400057)";
        $errors['error_id_58'] = _("ERROR_ID_58") . " (400058)";
        $errors['error_id_59'] = _("ERROR_ID_59") . " (400059)";
        $errors['error_id_60'] = _("ERROR_ID_60") . " (400060)";
        $errors['error_id_61'] = _("ERROR_ID_61") . " (400061)";
        $errors['error_id_62'] = _("ERROR_ID_62") . " (400062)";
        $errors['error_id_63'] = _("ERROR_ID_63") . " (400063)";
        $errors['error_id_64'] = _("ERROR_ID_64") . " (400064)";
        $errors['error_id_65'] = _("ERROR_ID_65") . " (400065)";
        $errors['error_id_66'] = _("ERROR_ID_66") . " (400066)";
        $errors['error_id_67'] = _("ERROR_ID_67") . " (400067)";
        $errors['error_id_68'] = _("ERROR_ID_68") . " (400068)";
        $errors['error_id_69'] = _("ERROR_ID_69") . " (400069)";
        $errors['error_id_70'] = _("ERROR_ID_70") . " (400070)";
        $errors['error_id_71'] = _("ERROR_ID_71") . " (400071)";
        $errors['error_id_72'] = _("ERROR_ID_72") . " (400072)";
        $errors['error_id_73'] = _("ERROR_ID_73") . " (400073)";
        $errors['error_id_74'] = _("ERROR_ID_74") . " (400074)";
        $errors['error_id_75'] = _("ERROR_ID_75") . " (400075)";
        $errors['error_id_76'] = _("ERROR_ID_76") . " (400076)";
        $errors['error_id_77'] = _("ERROR_ID_77") . " (400077)";
        $errors['error_id_78'] = _("ERROR_ID_78") . " (400078)";
        $errors['error_id_79'] = _("ERROR_ID_79") . " (400079)";
        $errors['error_id_80'] = _("ERROR_ID_80") . " (400080)";
        $errors['error_id_81'] = _("ERROR_ID_81") . " (400081)";
        $errors['error_id_82'] = _("ERROR_ID_82") . " (400082)";
        $errors['error_id_83'] = _("ERROR_ID_83") . " (400083)";
        $errors['error_id_84'] = _("ERROR_ID_84") . " (400084)";
        $errors['error_id_85'] = _("ERROR_ID_85") . " (400085)";
        $errors['error_id_86'] = _("ERROR_ID_86") . " (400086)";
        $errors['error_id_87'] = _("ERROR_ID_87") . " (400087)";
        $errors['error_id_88'] = _("ERROR_ID_88") . " (400088)";
        $errors['error_id_89'] = _("ERROR_ID_89") . " (400089)";
        $errors['error_id_90'] = _("ERROR_ID_90") . " (400090)";
        $errors['error_id_91'] = _("ERROR_ID_91") . " (400091)";
        $errors['error_id_92'] = _("ERROR_ID_92") . " (400092)";
        $errors['error_id_93'] = _("ERROR_ID_93") . " (400093)";
        $errors['error_id_94'] = _("ERROR_ID_94") . " (400094)";
        $errors['error_id_95'] = _("ERROR_ID_95") . " (400095)";
        $errors['error_id_96'] = _("ERROR_ID_96") . " (400096)";
        $errors['error_id_97'] = _("ERROR_ID_97") . " (400097)";
        $errors['error_id_98'] = _("ERROR_ID_98") . " (400098)";
        $errors['error_id_99'] = _("ERROR_ID_99") . " (400099)";
        $errors['error_id_100'] = _("ERROR_ID_100") . " (400100)";
        $errors['error_id_101'] = _("ERROR_ID_101") . " (400101)";
        $errors['error_id_102'] = _("ERROR_ID_102") . " (400102)";
        $errors['error_id_103'] = _("ERROR_ID_103") . " (400103)";
        $errors['error_id_104'] = _("ERROR_ID_104") . " (400104)";
        $errors['error_id_105'] = _("ERROR_ID_105") . " (400105)";
        $errors['error_id_106'] = _("ERROR_ID_106") . " (400106)";
        $errors['error_id_107'] = _("ERROR_ID_107") . " (400107)";
        $errors['error_id_108'] = _("ERROR_ID_108") . " (400108)";
        $errors['error_id_109'] = _("ERROR_ID_109") . " (400109)";
        $errors['error_id_110'] = _("ERROR_ID_110") . " (400110)";
        $errors['error_id_111'] = _("ERROR_ID_111") . " (400111)";
        $errors['error_id_112'] = _("ERROR_ID_112") . " (400112)";
        $errors['error_id_113'] = _("ERROR_ID_113") . " (400113)";
        $errors['error_id_114'] = _("ERROR_ID_114") . " (400114)";
        $errors['error_id_115'] = _("ERROR_ID_115") . " (400115)";
        $errors['error_id_116'] = _("ERROR_ID_116") . " (400116)";
        $errors['error_id_117'] = _("ERROR_ID_117") . " (400117)";
        $errors['error_id_118'] = _("ERROR_ID_118") . " (400118)";
        $errors['error_id_119'] = _("ERROR_ID_119") . " (400119)";
        $errors['error_id_120'] = _("ERROR_ID_120") . " (400120)";
        $errors['error_id_121'] = _("ERROR_ID_121") . " (400121)";
        $errors['error_id_122'] = _("ERROR_ID_122") . " (400122)";
        $errors['error_id_123'] = _("ERROR_ID_123") . " (400123)";
        $errors['error_id_124'] = _("ERROR_ID_124") . " (400124)";
        $errors['error_id_125'] = _("ERROR_ID_125") . " (400125)";
        $errors['error_id_126'] = _("ERROR_ID_126") . " (400126)";
        $errors['error_id_127'] = _("ERROR_ID_127") . " (400127)";
        $errors['error_id_128'] = _("ERROR_ID_128") . " (400128)";
        $errors['error_id_129'] = _("ERROR_ID_129") . " (400129)";
        $errors['error_id_130'] = _("ERROR_ID_130") . " (400130)";
        $errors['error_id_131'] = _("ERROR_ID_131") . " (400131)";
        $errors['error_id_132'] = _("ERROR_ID_132") . " (400132)";
        $errors['error_id_133'] = _("ERROR_ID_133") . " (400133)";
        $errors['error_id_134'] = _("ERROR_ID_134") . " (400134)";
        $errors['error_id_135'] = _("ERROR_ID_135") . " (400135)";
        $errors['error_id_136'] = _("ERROR_ID_136") . " (400136)";
        $errors['error_id_137'] = _("ERROR_ID_137") . " (400137)";
        $errors['error_id_138'] = _("ERROR_ID_138") . " (400138)";
        $errors['error_id_139'] = _("ERROR_ID_139") . " (400139)";
        $errors['error_id_140'] = _("ERROR_ID_140") . " (400140)";
        $errors['error_id_141'] = _("ERROR_ID_141") . " (400141)";
        $errors['error_id_142'] = _("ERROR_ID_142") . " (400142)";
        $errors['error_id_143'] = _("ERROR_ID_143") . " (400143)";
        $errors['error_id_144'] = _("ERROR_ID_144") . " (400144)";
        $errors['error_id_145'] = _("ERROR_ID_145") . " (400145)";
        $errors['error_id_146'] = _("ERROR_ID_146") . " (400146)";
        $errors['error_id_147'] = _("ERROR_ID_147") . " (400147)";
        $errors['error_id_148'] = _("ERROR_ID_148") . " (400148)";
        $errors['error_id_149'] = _("ERROR_ID_149") . " (400149)";
        $errors['error_id_150'] = _("ERROR_ID_150") . " (400150)";
        $errors['error_id_151'] = _("ERROR_ID_151") . " (400151)";
        $errors['error_id_152'] = _("ERROR_ID_152") . " (400152)";
        $errors['error_id_153'] = _("ERROR_ID_153") . " (400153)";
        $errors['error_id_154'] = _("ERROR_ID_154") . " (400154)";
        $errors['error_id_155'] = _("ERROR_ID_155") . " (400155)";
        $errors['error_id_156'] = _("ERROR_ID_156") . " (400156)";
        $errors['error_id_157'] = _("ERROR_ID_157") . " (400157)";
        $errors['error_id_158'] = _("ERROR_ID_158") . " (400158)";
        $errors['error_id_159'] = _("ERROR_ID_159") . " (400159)";
        $errors['error_id_160'] = _("ERROR_ID_160") . " (400160)";
        $errors['error_id_161'] = _("ERROR_ID_161") . " (400161)";
        $errors['error_id_162'] = _("ERROR_ID_162") . " (400162)";
        $errors['error_id_163'] = _("ERROR_ID_163") . " (400163)";
        $errors['error_id_164'] = _("ERROR_ID_164") . " (400164)";
        $errors['error_id_165'] = _("ERROR_ID_165") . " (400165)";
        $errors['error_id_166'] = _("ERROR_ID_166") . " (400166)";
        $errors['error_id_167'] = _("ERROR_ID_167") . " (400167)";
        $errors['error_id_168'] = _("ERROR_ID_168") . " (400168)";
        $errors['error_id_169'] = _("ERROR_ID_169") . " (400169)";
        $errors['error_id_170'] = _("ERROR_ID_170") . " (400170)";
        $errors['error_id_171'] = _("ERROR_ID_171") . " (400171)";
        $errors['error_id_172'] = _("ERROR_ID_172") . " (400172)";
        $errors['error_id_173'] = _("ERROR_ID_173") . " (400173)";
        $errors['error_id_174'] = _("ERROR_ID_174") . " (400174)";
        $errors['error_id_175'] = _("ERROR_ID_175") . " (400175)";
        $errors['error_id_176'] = _("ERROR_ID_176") . " (400176)";
        $errors['error_id_177'] = _("ERROR_ID_177") . " (400177)";
        $errors['error_id_178'] = _("ERROR_ID_178") . " (400178)";
        $errors['error_id_179'] = _("ERROR_ID_179") . " (400179)";
        $errors['error_id_180'] = _("ERROR_ID_180") . " (400180)";
        $errors['error_id_181'] = _("ERROR_ID_181") . " (400181)";
        $errors['error_id_182'] = _("ERROR_ID_182") . " (400182)";
        $errors['error_id_183'] = _("ERROR_ID_183") . " (400183)";
        $errors['error_id_184'] = _("ERROR_ID_184") . " (400184)";
        $errors['error_id_185'] = _("ERROR_ID_185") . " (400185)";
        $errors['error_id_186'] = _("ERROR_ID_186") . " (400186)";
        $errors['error_id_187'] = _("ERROR_ID_187") . " (400187)";
        $errors['error_id_188'] = _("ERROR_ID_188") . " (400188)";
        $errors['error_id_189'] = _("ERROR_ID_189") . " (400189)";
        $errors['error_id_190'] = _("ERROR_ID_190") . " (400190)";
        $errors['error_id_191'] = _("ERROR_ID_191") . " (400191)";
        $errors['error_id_192'] = _("ERROR_ID_192") . " (400192)";
        $errors['error_id_193'] = _("ERROR_ID_193") . " (400193)";
        $errors['error_id_194'] = _("ERROR_ID_194") . " (400194)";
        $errors['error_id_195'] = _("ERROR_ID_195") . " (400195)";
        $errors['error_id_196'] = _("ERROR_ID_196") . " (400196)";
        $errors['error_id_197'] = _("ERROR_ID_197") . " (400197)";
        $errors['error_id_198'] = _("ERROR_ID_198") . " (400198)";
        $errors['error_id_199'] = _("ERROR_ID_199") . " (400199)";
        $errors['error_id_200'] = _("ERROR_ID_200") . " (400200)";
        $errors['error_id_201'] = _("ERROR_ID_201") . " (400201)";
        $errors['error_id_202'] = _("ERROR_ID_202") . " (400202)";
        $errors['error_id_203'] = _("ERROR_ID_203") . " (400203)";
        $errors['error_id_204'] = _("ERROR_ID_204") . " (400204)";
        $errors['error_id_205'] = _("ERROR_ID_205") . " (400205)";
        $errors['error_id_206'] = _("ERROR_ID_206") . " (400206)";
        $errors['error_id_207'] = _("ERROR_ID_207") . " (400207)";
        $errors['error_id_208'] = _("ERROR_ID_208") . " (400208)";
        $errors['error_id_209'] = _("ERROR_ID_209") . " (400209)";
        $errors['error_id_210'] = _("ERROR_ID_210") . " (400210)";
        $errors['error_id_211'] = _("ERROR_ID_211") . " (400211)";
        $errors['error_id_212'] = _("ERROR_ID_212") . " (400212)";
        $errors['error_id_213'] = _("ERROR_ID_213") . " (400213)";
        $errors['error_id_214'] = _("ERROR_ID_214") . " (400214)";
        $errors['error_id_215'] = _("ERROR_ID_215") . " (400215)";
        $errors['error_id_216'] = _("ERROR_ID_216") . " (400216)";
        $errors['error_id_217'] = _("ERROR_ID_217") . " (400217)";
        $errors['error_id_218'] = _("ERROR_ID_218") . " (400218)";
        $errors['error_id_219'] = _("ERROR_ID_219") . " (400219)";
        $errors['error_id_220'] = _("ERROR_ID_220") . " (400220)";
        $errors['error_id_221'] = _("ERROR_ID_221") . " (400221)";
        $errors['error_id_222'] = _("ERROR_ID_222") . " (400222)";
        $errors['error_id_223'] = _("ERROR_ID_223") . " (400223)";
        $errors['error_id_224'] = _("ERROR_ID_224") . " (400224)";
        $errors['error_id_225'] = _("ERROR_ID_225") . " (400225)";
        $errors['error_id_226'] = _("ERROR_ID_226") . " (400226)";
        $errors['error_id_227'] = _("ERROR_ID_227") . " (400227)";
        $errors['error_id_228'] = _("ERROR_ID_228") . " (400228)";
        $errors['error_id_229'] = _("ERROR_ID_229") . " (400229)";
        $errors['error_id_230'] = _("ERROR_ID_230") . " (400230)";
        $errors['error_id_231'] = _("ERROR_ID_231") . " (400231)";
        $errors['error_id_232'] = _("ERROR_ID_232") . " (400232)";
        $errors['error_id_233'] = _("ERROR_ID_233") . " (400233)";
        $errors['error_id_234'] = _("ERROR_ID_234") . " (400234)";
        $errors['error_id_235'] = _("ERROR_ID_235") . " (400235)";
        $errors['error_id_236'] = _("ERROR_ID_236") . " (400236)";
        $errors['error_id_237'] = _("ERROR_ID_237") . " (400237)";
        $errors['error_id_238'] = _("ERROR_ID_238") . " (400238)";
        $errors['error_id_239'] = _("ERROR_ID_239") . " (400239)";
        $errors['error_id_240'] = _("ERROR_ID_240") . " (400240)";
        $errors['error_id_241'] = _("ERROR_ID_241") . " (400241)";
        $errors['error_id_242'] = _("ERROR_ID_242") . " (400242)";
        $errors['error_id_243'] = _("ERROR_ID_243") . " (400243)";
        $errors['error_id_244'] = _("ERROR_ID_244") . " (400244)";
        $errors['error_id_245'] = _("ERROR_ID_245") . " (400245)";
        $errors['error_id_246'] = _("ERROR_ID_246") . " (400246)";
        $errors['error_id_247'] = _("ERROR_ID_247") . " (400247)";
        $errors['error_id_248'] = _("ERROR_ID_248") . " (400248)";
        $errors['error_id_249'] = _("ERROR_ID_249") . " (400249)";
        $errors['error_id_250'] = _("ERROR_ID_250") . " (400250)";
        $errors['error_id_251'] = _("ERROR_ID_251") . " (400251)";
        $errors['error_id_252'] = _("ERROR_ID_252") . " (400252)";
        $errors['error_id_253'] = _("ERROR_ID_253") . " (400253)";
        $errors['error_id_254'] = _("ERROR_ID_254") . " (400254)";
        $errors['error_id_255'] = _("ERROR_ID_255") . " (400255)";
        $errors['error_id_256'] = _("ERROR_ID_256") . " (400256)";
        $errors['error_id_257'] = _("ERROR_ID_257") . " (400257)";
        $errors['error_id_258'] = _("ERROR_ID_258") . " (400258)";
        $errors['error_id_259'] = _("ERROR_ID_259") . " (400259)";
        $errors['error_id_260'] = _("ERROR_ID_260") . " (400260)";
        $errors['error_id_261'] = _("ERROR_ID_261") . " (400261)";
        $errors['error_id_262'] = _("ERROR_ID_262") . " (400262)";
        $errors['error_id_263'] = _("ERROR_ID_263") . " (400263)";
        $errors['error_id_264'] = _("ERROR_ID_264") . " (400264)";
        $errors['error_id_265'] = _("ERROR_ID_265") . " (400265)";
        $errors['error_id_266'] = _("ERROR_ID_266") . " (400266)";
        $errors['error_id_267'] = _("ERROR_ID_267") . " (400267)";
        $errors['error_id_268'] = _("ERROR_ID_268") . " (400268)";
        $errors['error_id_269'] = _("ERROR_ID_269") . " (400269)";
        $errors['error_id_270'] = _("ERROR_ID_270") . " (400270)";
        $errors['error_id_271'] = _("ERROR_ID_271") . " (400271)";
        $errors['error_id_272'] = _("ERROR_ID_272") . " (400272)";
        $errors['error_id_273'] = _("ERROR_ID_273") . " (400273)";
        $errors['error_id_274'] = _("ERROR_ID_274") . " (400274)";
        $errors['error_id_275'] = _("ERROR_ID_275") . " (400275)";
        $errors['error_id_276'] = _("ERROR_ID_276") . " (400276)";
        $errors['error_id_277'] = _("ERROR_ID_277") . " (400277)";
        $errors['error_id_278'] = _("ERROR_ID_278") . " (400278)";
        $errors['error_id_279'] = _("ERROR_ID_279") . " (400279)";
        $errors['error_id_280'] = _("ERROR_ID_280") . " (400280)";
        $errors['error_id_281'] = _("ERROR_ID_281") . " (400281)";

        $errors['error_id_282'] = _("ERROR_ID_282") . " (400282)";
        $errors['error_id_283'] = _("ERROR_ID_283") . " (400283)";
        $errors['error_id_284'] = _("ERROR_ID_284") . " (400284)";
        $errors['error_id_285'] = _("ERROR_ID_285") . " (400285)";
        $errors['error_id_286'] = _("ERROR_ID_286") . " (400286)";
        $errors['error_id_287'] = _("ERROR_ID_287") . " (400287)";
        $errors['error_id_288'] = _("ERROR_ID_288") . " (400288)";
        $errors['error_id_289'] = _("ERROR_ID_289") . " (400289)";
        $errors['error_id_290'] = _("ERROR_ID_290") . " (400290)";
        $errors['error_id_291'] = _("ERROR_ID_291") . " (400291)";

        $errors['error_id_292'] = _("ERROR_ID_292") . " (400292)";
        $errors['error_id_293'] = _("ERROR_ID_293") . " (400293)";
        $errors['error_id_294'] = _("ERROR_ID_294") . " (400294)";
        $errors['error_id_295'] = _("ERROR_ID_295") . " (400295)";
        $errors['error_id_296'] = _("ERROR_ID_296") . " (400296)";
        $errors['error_id_297'] = _("ERROR_ID_297") . " (400297)";
        $errors['error_id_298'] = _("ERROR_ID_298") . " (400298)";
        $errors['error_id_299'] = _("ERROR_ID_299") . " (400299)";
        $errors['error_id_300'] = _("ERROR_ID_300") . " (400300)";

        $errors['error_id_301'] = _("ERROR_ID_301") . " (400301)";
        $errors['error_id_302'] = _("ERROR_ID_302") . " (400302)";
        $errors['error_id_303'] = _("ERROR_ID_303") . " (400303)";
        $errors['error_id_304'] = _("ERROR_ID_304") . " (400304)";
        $errors['error_id_305'] = _("ERROR_ID_305") . " (400305)";

        $errors['error_id_306'] = _("ERROR_ID_306") . " (400306)";
        $errors['error_id_307'] = _("ERROR_ID_307") . " (400307)";
        $errors['error_id_308'] = _("ERROR_ID_308") . " (400308)";
        $errors['error_id_309'] = _("ERROR_ID_309") . " (400309)";
        $errors['error_id_310'] = _("ERROR_ID_310") . " (400310)";
        $errors['error_id_311'] = _("ERROR_ID_311") . " (400311)";
        $errors['error_id_312'] = _("ERROR_ID_312") . " (400312)";
        $errors['error_id_313'] = _("ERROR_ID_313") . " (400313)";
        $errors['error_id_314'] = _("ERROR_ID_314") . " (400314)";

        $errors['error_id_315'] = _("ERROR_ID_315") . " (400315)";
        $errors['error_id_316'] = _("ERROR_ID_316") . " (400316)";
        $errors['error_id_317'] = _("ERROR_ID_317") . " (400317)";
        $errors['error_id_318'] = _("ERROR_ID_318") . " (400318)";
        $errors['error_id_319'] = _("ERROR_ID_319") . " (400319)";
        $errors['error_id_320'] = _("ERROR_ID_320") . " (400320)";
        $errors['error_id_321'] = _("ERROR_ID_321") . " (400321)";
        $errors['error_id_322'] = _("ERROR_ID_322") . " (400322)";
        $errors['error_id_323'] = _("ERROR_ID_323") . " (400323)";
        $errors['error_id_324'] = _("ERROR_ID_324") . " (400324)";
        $errors['error_id_325'] = _("ERROR_ID_325") . " (400325)";
        $errors['error_id_326'] = _("ERROR_ID_326") . " (400326)";
        $errors['error_id_327'] = _("ERROR_ID_327") . " (400327)";
        $errors['error_id_328'] = _("ERROR_ID_328") . " (400328)";
        $errors['error_id_329'] = _("ERROR_ID_329") . " (400329)";
        $errors['error_id_330'] = _("ERROR_ID_330") . " (400330)";
        $errors['error_id_331'] = _("ERROR_ID_331") . " (400331)";
        $errors['error_id_332'] = _("ERROR_ID_332") . " (400332)";
        $errors['error_id_333'] = _("ERROR_ID_333") . " (400333)";

        $errors['error_id_340'] = _("ERROR_ID_340") . " (400340)";
        $errors['error_id_341'] = _("ERROR_ID_341") . " (400341)";

        $errors['error_id_350'] = _("ERROR_ID_350") . " (400350)";
        $errors['error_id_351'] = _("ERROR_ID_351") . " (400351)";
        $errors['error_id_352'] = _("ERROR_ID_352") . " (400352)";
        $errors['error_id_353'] = _("ERROR_ID_353") . " (400353)";

        $errors['error_id_354'] = _("ERROR_ID_354") . " (400354)";
        $errors['error_id_355'] = _("ERROR_ID_355") . " (400355)";
        $errors['error_id_356'] = _("ERROR_ID_356") . " (400356)";

        $errors['error_id_357'] = _("ERROR_ID_357") . " (400357)";
        $errors['error_id_358'] = _("ERROR_ID_358") . " (400358)";
        $errors['error_id_359'] = _("ERROR_ID_359") . " (400359)";
        $errors['error_id_360'] = _("ERROR_ID_360") . " (400360)";
        $errors['error_id_361'] = _("ERROR_ID_361") . " (400361)";
        $errors['error_id_362'] = _("ERROR_ID_362") . " (400362)";
        $errors['error_id_363'] = _("ERROR_ID_363") . " (400363)";
        $errors['error_id_364'] = _("ERROR_ID_364") . " (400364)";

        $errors['error_id_365'] = _("ERROR_ID_365") . " (400365)";
        $errors['error_id_366'] = _("ERROR_ID_366") . " (400366)";
        $errors['error_id_367'] = _("ERROR_ID_367") . " (400367)";
        $errors['error_id_368'] = _("ERROR_ID_368") . " (400368)";
        $errors['error_id_369'] = _("ERROR_ID_369") . " (400369)";
        $errors['error_id_370'] = _("ERROR_ID_370") . " (400370)";

        $errors['error_id_400'] = _("ERROR_ID_400") . " (400400)";
        $errors['error_id_401'] = _("ERROR_ID_401") . " (400401)";
        $errors['error_id_402'] = _("ERROR_NO_SD_CARD") . " (400402)";

        $errors['error_id_500'] = _("ERROR_ID_500") . " (400500)";
        $errors['error_id_501'] = _("ERROR_ID_501") . " (400501)";

        /* Legacy Sequoia
        # Safepoint specific codes and messages
        $errors['error_id_2000'] = _("SAFEPOINT_OK") . " (402000)";
        $errors['error_id_2001'] = _("SAFEPOINT_INPROGRESS") . " (402001)";
        $errors['error_id_2002'] = _("SAFEPOINT_FAILED") . " (402002)";
        $errors['error_id_2003'] = _("SAFEPOINT_NOTFOUND") . " (402003)";
        $errors['error_id_2004'] = _("SAFEPOINT_UNAUTHORIZED") . " (402004)";
        $errors['error_id_2005'] = _("SAFEPOINT_BUSY") . " (402005)";
        $errors['error_id_2006'] = _("SAFEPOINT_NOSPACE") . " (402006)";
        $errors['error_id_2007'] = _("SAFEPOINT_INVALID") . " (402007)";
        $errors['error_id_2008'] = _("SAFEPOINT_INCOMPATIBLE") . " (402008)";
        $errors['error_id_2009'] = _("SAFEPOINT_UNREACHABLE") . " (402009)";
        $errors['error_id_2010'] = _("SAFEPOINT_NOTSUPPORTED") . " (402010)";
        $errors['error_id_2011'] = _("SAFEPOINT_DUPLICATE") . " (402011)";
        $errors['error_id_2012'] = _("SAFEPOINT_NOTSTARTED") . " (402012)";
        $errors['error_id_2013'] = _("SAFEPOINT_NOTCREATED") . " (402013)";
        $errors['error_id_2014'] = _("SAFEPOINT_UNAVAILABLE") . " (402014)";
        $errors['error_id_2015'] = _("SAFEPOINT_CORRUPTED") . " (402015)";
        $errors['error_id_2016'] = _("SAFEPOINT_ABORTED") . " (402016)";
        $errors['error_id_2017'] = _("SAFEPOINT_IGNORE") . " (402017)";
        $errors['error_id_2018'] = _("SAFEPOINT_NOTALLOWED") . " (402018)";
        $errors['error_id_2141'] = _("SAFEPOINT_TIMEOUT") . " (402141)";
        */

        // Auth/RequestAuth errors
        $errors['error_id_2200'] = _("ERROR_ID_2200") . " (402200)";
        $errors['error_id_2201'] = _("ERROR_ID_2201") . " (402201)";
        $errors['error_id_2202'] = _("ERROR_ID_2202") . " (402202)";

        $errors['error_id_2300'] = _("ERROR_ID_2300") . " (402300)";
        $errors['error_id_2301'] = _("ERROR_ID_2301") . " (402301)";
        $errors['error_id_2302'] = _("ERROR_ID_2302") . " (402302)";
        $errors['error_id_2303'] = _("ERROR_ID_2303") . " (402303)";
        $errors['error_id_2304'] = _("ERROR_ID_2304") . " (402304)";
        $errors['error_id_2305'] = _("ERROR_ID_2305") . " (402305)";

        $errors['error_id_2400'] = _("ERROR_ID_2400") . " (402400)";
        $errors['error_id_2401'] = _("ERROR_ID_2401") . " (402401)";

?>

var errorsList = new Array();
<?php
    foreach ($errors as $key => $message) {
        echo "errorsList[\"".$key."\"] = \"".$message."\";\n";
    }
?>

