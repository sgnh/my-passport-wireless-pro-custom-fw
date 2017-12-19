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
	<!--<link href="detect_device.css" rel="stylesheet" type="text/css">-->
</head>
<body>
	<div id="containner">
    	<?php echo _('NEWKORRA_CAPTIVE_UNSPPORT_TITLE')?>
	</div><!--containner-->
</body>		
</html>