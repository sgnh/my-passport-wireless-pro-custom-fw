<div id="plex_status" style="display:none"><span ><?php echo exec('sudo /usr/local/sbin/getPackagesStatus.sh plexmediaserver'); ?></span></div>
<div id="plex_container" class="edit_container_box">
	<div class="plex_icon"><h2><?php echo _('CONTENT_SETTINGS_HEAD2_PLEX')?></h2></div>

    <div class="content_row">
        <?php echo _('CONTENT_SETTINGS_STRING_PLEX_DESCR')?>&nbsp;<a id="plex_more_info" href="#"><?php echo _('CONTENT_DIALOG_ALERTS_STRING_MORE_INFO')?><span class="details_link_marker">&nbsp;&raquo;</span></a>   
    </div>
	
	<div class="content_row" id="plex_download_container">
		<span>
			<button id="plex_download_button"><?php echo _('CONTENT_SETTINGS_LABEL_DOWNLOAD_LOGS')?></button>
		</span>
	</div>
	
	<div class="content_row" id="plex_install_container">
		<span>
			<button id="plex_install_button"><?php echo _('CONTENT_SETTINGS_LABEL_PLEX_INSTALL')?></button>
		</span>
	</div>
	
	<div id="plex_setting_container">
		<div class="content_row" >
			<form id="settings_media_toggle_plex_service_form" action="plex_media_server_configuration" method="PUT">
	        	<label><?php echo _("CONTENT_SETTINGS_LABEL_MEDIA_STREAMING");?></label>
	        	<div id="plex_server_enabled" style="display:none"><span><?php echo exec('sudo /usr/local/sbin/getServiceStartup.sh plexmediaserver'); ?></span></div>
	        	<input class="false" name="enable_plex_media_server" value="false" type="hidden"/>
	        	<input type="checkbox" id="plex_enabled" class="onoffswitch" value="true"/>
	    	</form>
		</div>
		
		<div class="content_row" id="plex_configure_button">
	    	<label><?php echo _("NAV_PRIMARY_SETTINGS");?></label>
	    	<button id="plex_setting_button"><?php echo _('CONTENT_SETTINGS_LINK_CONFIGURE')?></button>
		</div>
		
		<div class="content_row" id="plex_version_download_button">
	    	<label><?php echo _("CONTENT_SETTINGS_LABEL_VERSION");?></label>
	    	<span id="plex_version"></span>
	    	<button type="button" id="plex_new_ver_download_button"><?php echo _('LABEL_AVAILABLE_UPDATES')?></button>
		</div>
	</div>
</div>