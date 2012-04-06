<?php

//
require_once('base.inc');

// コントローラのinclude
require_once('controller.inc');

//
$cobj = new controller;
$cobj->set_base_path($bp);
$cobj->set_config($admin_config);
$cobj->run();

//var_dump( memory_get_peak_usage(true) );

