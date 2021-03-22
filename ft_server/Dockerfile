FROM debian:buster

RUN	apt-get update && apt-get -y upgrade;
RUN	apt-get install -y \
	vim\
	wget\
	nginx\
	php7.3\
	php-fpm\
	php-mysql\
	mariadb-server\
	openssl\
#PHP UTILITIES
	php-mbstring\
	php-curl\
	php-xml\
	php-xmlrpc\
	php-simplexml\
	php-intl\
	php-exif\
	php-gd\
	php-iconv\
	php-json\
	php-posix\
	php-zip

#COPY FROM \SRCS TO THE CONTAINER
COPY	/srcs/nginx.conf \
	/srcs/change_autoindex.sh \
	/srcs/wp-config.php \
	/srcs/config.inc.php \
	/srcs/run.sh ./

#ISSUE SSL CERT
RUN	openssl req -x509 -nodes -sha256 -newkey rsa:2048 -days 3650 \
	-subj "/C=RU/ST=Tatarstan/L=Kazan/O=school_21/OU=dbolg/CN=ft_server" \
	-keyout /etc/ssl/private/new_ssl.key \
	-out /etc/ssl/certs/new_ssl.crt 

#INSTALL WORDPRESS
RUN	wget https://wordpress.org/latest.tar.gz && \
	tar -xvzf latest.tar.gz -C /var/www && \
	rm latest.tar.gz

#SET PERMISSION
RUN	chmod +x run.sh change_autoindex.sh
RUN	chown -R www-data:www-data /var/www/* 
RUN	chmod -R 777 /var/*

#INSTALL PHPMYADMIN
RUN	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz && \
	tar -xvzf phpMyAdmin-4.9.5-all-languages.tar.gz -C /var/www/wordpress && \
	mv /var/www/wordpress/phpMyAdmin-4.9.5-all-languages /var/www/wordpress/phpMyAdmin && \
	rm phpMyAdmin-4.9.5-all-languages.tar.gz && \
	mkdir /var/www/wordpress/phpMyAdmin/tmp && \
	chmod 777 /var/www/wordpress/phpMyAdmin
	
#MOVE CONFIGS
RUN mv ./wp-config.php /var/www/wordpress && \
	mv ./nginx.conf /etc/nginx/sites-available/ && \
	mv ./config.inc.php /var/www/wordpress/phpMyAdmin && \
	cd /etc/nginx/sites-enabled && \
	ln -s ../sites-available/nginx.conf .

#REMOVE DEFAULT CONFIG
RUN	rm -f etc/sites-enabled/default

#RUN DOCKER
CMD bash ./run.sh
