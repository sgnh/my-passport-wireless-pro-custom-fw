<?php
   header('X-UA-Compatible: IE=edge,chrome=1');
    //build cached file if it doesn't exist
    $cacheFile = 'cache/fullpage.html';
    define ('DEBUG_MODE', false);
    define ('SITE_BASE_URL', 'UI');
    
   include_once('UI/lib/language.php');
             $language = new Language();
           $languageStr = $language->getLanguage();
           
          define('LANGUAGE_STR', $languageStr);
            ob_start();
            setlocale(LC_ALL, $languageStr.".UTF-8");
            bindtextdomain("default", "UI/locale");
            textdomain("default");
            
            include_once('UI/views/common/languages.php');
            if(isset($langMap[$languageStr])){
                $Language3Letter = $langMap[$languageStr];
            }
            else{
                $Language3Letter = 'eng';
            }
            define('LANGUAGE_3CHAR', $Language3Letter);

            include_once('UI/lib/pageLoader.php');/**/
?>




<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta name="apple-itunes-app" content="app-id=450655672">
	<title>MyPassport</title>
	<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
<meta name="apple-itunes-app" content="app-id=450655672">

    <script type="text/javascript">
      
		window.onload = function(){
		   window.location = "/UI";
		}
 	</script>
</head>
<body>
	<!--<div id="containner">
	    <p id="check" style="display:block;"></p>
    	<div id="logo" ><img src="/detect-source/images/loading_logo.png"/>
        <div id="wording"><?php echo _('NEWKORRA_CAPTIVE_LOADING'); ?>...</div>
        <div id="wording2" style="display:none;"><a id=""></a><div>
      </div>
        <!--<div id="bottom_area"></div>change22--
	</div><!--containner-->

</body>
</html>