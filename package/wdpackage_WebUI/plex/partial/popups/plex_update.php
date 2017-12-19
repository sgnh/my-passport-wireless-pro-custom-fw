<div id="plex_download_dialog" title="<?php echo _('CONTENT_SETTINGS_LABEL_DOWNLOAD_LOGS')?>">
	<div class="mochi_dialog_content_container">
		<form method="POST" id="start_plex_download_form" onsubmit="return false">
			<span id="start_plex_download" sytle="display:none"></span>
		</form>
		<form method="POST" id="get_plex_download_status_form" onsubmit="return false">
			<!--div id="get_plex_download_status" sytle="display:none"><span ><?php echo exec(''); ?></span></div-->
			<div class="mochi_dialog_content" id="download_process">
            	<p><?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE_PROCESS')?></p>
           		<div id="plex_download_progressbar" style="display: inline-block;" class="plex_progressbar"></div>
           		<span class="extra_space_left" id="plex_download_progressbar_percentage"></span>
        	</div>
		</form>
	</div>
</div>

<div id="plex_update_comfirmation_dialog" title="<?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE_TITLE')?>">
	<div class="mochi_dialog_content_container">
		<div class="mochi_dialog_content" id="update_comfirmation">
            <p><?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE2')?></p>
           	<div id="current_version" class="plex_update"><?php echo _('CONTENT_SETTINGS_STRING_PLEX_CURRENT_VERSION')?><span id="plex_current_version"><?php echo exec('/usr/local/sbin/getPackagesVersion.sh plexmediaserver'); ?></span></div>
           	<div id="new_version" class="plex_update"><?php echo _('CONTENT_SETTINGS_STRING_PLEX_NEW_VERSION')?><span id="plex_new_version"><?php echo ('')?></span></div>
        </div>
	</div>
	<div class="dialog_form_controls">
		<button type="button" id="plex_update_dialog_cancel_button" class="mochi_dialog_cancel_button"><?php echo _('BUTTON_CANCEL')?></button>
		<button type="button" id="plex_update_dialog_ok_button" class="mochi_dialog_save_button"><?php echo _('BUTTON_OK')?></button>
	</div>
</div>

<div id="plex_update_process_dialog" title="<?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE_TITLE')?>">
	<div class="mochi_dialog_content_container">
		<form method="POST" id="start_plex_update_form" onsubmit="return false">
			<span id="start_plex_update" sytle="display:none"></span>
		</form>
		<form id="get_plex_update_status_form" onsubmit="return false">
			<!--div id="plex_update_status" sytle="display:none"><span><?php echo exec(''); ?></span></div-->
			<div class="mochi_dialog_content" id="update_process">
	            <p><?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE_PROCESS')?></p>
	           	<div id="plex_update_progressbar" style="display: inline-block;" class="plex_progressbar"></div>
	           	<span class="extra_space_left" id="plex_update_progressbar_percentage"></span>
	        </div>
    	</form>
	</div>
</div>

<div id="plex_update_failed_dialog" title="<?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE_FAILED_TITLE')?>">
	<div class="mochi_dialog_content_container">
		<div class="mochi_dialog_content" id="update_failed">
            <p><?php echo _('CONTENT_SETTINGS_STRING_PLEX_UPDATE_FAILED')?></p>
        </div>
	</div>
	<div class="dialog_form_controls">
		<button type="button" id="plex_update_failed_ok_button" class="mochi_dialog_save_button"><?php echo _('BUTTON_OK')?></button>
	</div>
</div>

<div id="plex_update_complete_dialog" title="<?php echo _('CONTENT_NOTE')?>">
	<div class="mochi_dialog_content_container">
		<div class="mochi_dialog_content" id="update_complete">
            <p><?php echo _('CONTENT_SETTINGS_STRING_PLEX_INSTALL')?></p>
        </div>
	</div>
	<div class="dialog_form_controls">
		<button type="button" id="plex_update_complete_cancel_button" class="mochi_dialog_cancel_button"><?php echo _('BUTTON_CANCEL')?></button>
        <button type="button" id="plex_update_complete_ok_button" class="mochi_dialog_save_button"><?php echo _('CONTENT_SETTINGS_LABEL_PLEX_INSTALL')?></button>
	</div>
</div>
