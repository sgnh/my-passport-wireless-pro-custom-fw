<?php

require_once('acllist.php');
require_once('user.php');

$aclObj = new Acllist();
$userObj = new User();

$userObj->configUserXdb();
$aclObj->setSharesConfigXdb();

/*
 * Local variables:
 *  indent-tabs-mode: nil
 *  c-basic-offset: 4
 *  c-indent-level: 4
 *  tab-width: 4
 * End:
 */

?>