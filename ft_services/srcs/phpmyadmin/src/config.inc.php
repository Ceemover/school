<?php
	$cfg['blowfish_secret'] = 'MhWZi000R5ZoMgSZb]Ax1dcjja=OS80b';

	$i=0;
	$i++;
	$cfg['Servers'][$i]['auth_type'] = 'cookie';

	$cfg['Servers'][$i]['host'] = 'mysql-service:3306';
	$cfg['Servers'][$i]['compress'] = false;
	$cfg['Servers'][$i]['AllowNoPassword'] = true;

	$cfg['UploadDir'] = '';
	$cfg['SaveDir'] = '';

	$cfg ['TempDir'] = '/var/www/phpmyadmin/tempdir';
?>