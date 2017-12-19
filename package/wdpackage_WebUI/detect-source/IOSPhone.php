<?php
   header('X-UA-Compatible: IE=edge,chrome=1');
    //build cached file if it doesn't exist
    $cacheFile = 'cache/fullpage.html';
    define ('DEBUG_MODE', false);
    define ('SITE_BASE_URL', 'UI');
    
   include_once('../UI/lib/language.php');
             $language = new Language();
           $languageStr = $language->getLanguage();
          define('LANGUAGE_STR', $languageStr);
            ob_start();
            setlocale(LC_ALL, $languageStr.".UTF-8");
            bindtextdomain("default", "../UI/locale");
            textdomain("default");
            
            include_once('../UI/views/common/languages.php');
            if(isset($langMap[$languageStr])){
                $Language3Letter = $langMap[$languageStr];
            }
            else{
                $Language3Letter = 'eng';
            }
            define('LANGUAGE_3CHAR', $Language3Letter);

            include_once('../UI/lib/pageLoader.php');/**/
?>
<html>
<head>
	<title>Success</title>
	 <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="viewport" content="width=device-width" />
	<script type="text/javascript" src="./js/jquery-1.12.0.min.js"></script>
	<link href="css/detect_device.css" rel="stylesheet" type="text/css">
</head>
<body>
	<div id="phone_containner">
    	<div id="phone_wd_logo">
        	<img src="images/product_images_sprite1.png" width="285" height="25">
        </div>
        <div id="iphone_title"><?php echo _('NEWKORRA_CAPTIVE_IOS_TITLE')?></div>
        <table id="iphone" width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><img src="images/iPhone 6 Copy1.png" width="125" height="125"></td>
            <td><p><?php echo _('NEWKORRA_CAPTIVE_IOS_STEB_ONE')?></p></td>
          </tr>
          <tr>
            <td><img src="images/iPhone 6 Copy2.png" width="125" height="125"></td>
            <td>
           	  <p><?php echo _('NEWKORRA_CAPTIVE_IOS_STEB_TWO')?><br/>
             <img style="margin: 5px;" src="images/AppStoreButton.png" width="100" height="35"></p>
            </td>
          </tr>
          <tr>
            <td><img src="images/iPhone 6 Copy3.png" width="125" height="125"></td>
            <td><p><?php echo _('NEWKORRA_CAPTIVE_IOS_STEB_THREE')?></p></td>
          </tr>
        </table>
     </div>
    
    
     <script type="text/javascript">
    	function checkCNA(){
			$.ajax({
      	"url": "/api/2.6/rest/device_captiveportal",
      	"type": "POST",
        "success": function(data) {
                 
         }
     	});		
			
			
		}
		
		window.onload = function(){
			//checkEula()
			setTimeout("checkCNA();",3000);
			
		}
     </script>
</body>		
</html>