<div class="content_row">				
	<form id="ssh_form" method="PUT" action="ssh_configuration">
		<label><?php echo _('CONTENT_SETTINGS_NETWORK_LABEL_SSH')?><div class="tooltip_container"><span class="tooltip_icon"></span><div class="tooltip_inner_container"><div class="tooltip"><?php echo _('SETTINGS_NETWORK_SERVICES_TOOLTIP_SSH')?></div></div></div></label>
		<input type="hidden" id="SettingDiagnosticsSSHValue" name="enablessh" value="true"/>
		<input type="hidden" id="SettingSSHPassword" name="pwdssh"/>
		<input type="checkbox" id="SettingDiagnosticsSSHToggle" class="onoffswitch"/>
		<span id="ssh_password_configer">Configure>></span>
	</form>
	
</div> 								

