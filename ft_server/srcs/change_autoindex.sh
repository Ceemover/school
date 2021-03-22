#!/bin/sh
if grep -q "autoindex off;" /etc/nginx/sites-available/nginx.conf
then sed -i 's/autoindex off;/autoindex on;/' /etc/nginx/sites-available/nginx.conf
else
sed -i 's/autoindex on;/autoindex off;/' /etc/nginx/sites-available/nginx.conf
fi
service nginx reload
