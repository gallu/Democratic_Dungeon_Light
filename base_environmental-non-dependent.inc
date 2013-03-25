<?php

// MWを使えるようにする
require_once('/opt/www/mw.conf');

// PHPのini系設定
require_once('mw_set_ini.inc');

// configファイル名
$config       = $bp . 'conf/config.conf';
$admin_config = $bp . 'conf/admin_config.conf';

//
require_once('controller.inc');

//
$co = new controller;
$co->set_base_path($bp);

