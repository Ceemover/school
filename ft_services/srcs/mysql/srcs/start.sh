#!/bin/sh
openrc default
/etc/init.d/mariadb setup
rc-service mariadb start

echo "CREATE USER 'root'@'%';" | mysql
mysql -u root -e "CREATE USER 'dbolg'@'%' IDENTIFIED BY '12345';"
mysql -u root -e "CREATE DATABASE wordpress;"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'dbolg'@'%' IDENTIFIED BY '12345' WITH GRANT OPTION;"
mysql -u root -e "FLUSH PRIVILEGES;"

mysql wordpress -u root < /wordpress.sql

rc-service mariadb stop
/usr/bin/mysqld_safe --datadir='/var/lib/mysql'