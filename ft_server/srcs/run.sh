#!/bin/sh

service mysql start

#CHANGE PERMISSIONS
chown www-data:www-data /var/www/* -R

#CREATE DATABASE
mysql -e "CREATE DATABASE new_database;"
mysql -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -e "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -e "FLUSH PRIVILEGES;"

#START SERVICES
service nginx start
service php7.3-fpm start

bash
