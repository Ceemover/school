FROM alpine:3.7

RUN apk update && apk upgrade
# php7 php7-fpm php7-opcache php7-json php7-iconv php7-mbstring php7-gettext \
# 		php7-gd php7-mysqli php7-zlib php7-curl php7-session php7-phar\
RUN apk add nginx supervisor wget \
	php7 php7-fpm php7-opcache php7-json php7-iconv php7-mbstring php7-gettext \
	php7-gd php7-mysqli php7-zlib php7-curl php7-session php7-phar

RUN mkdir -p /run/nginx /run/php

COPY ./src/default.conf /etc/nginx/conf.d/default.conf
COPY ./src/supervisor.conf /etc/supervisord.conf
COPY ./src/setup.sh ./

RUN	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.gz && \
	tar -xf phpMyAdmin-4.9.5-english.tar.gz && mv phpMyAdmin-4.9.5-english /var/www/phpmyadmin/ && \
	rm -f phpMyAdmin-4.9.5-english.tar.gz &&  mkdir /var/www/phpmyadmin/tempdir

COPY ./src/config.inc.php /var/www/phpmyadmin/config.inc.php

RUN chmod 755 -R /var/www/*
EXPOSE 5050
RUN chmod +x /setup.sh
CMD ./setup.sh