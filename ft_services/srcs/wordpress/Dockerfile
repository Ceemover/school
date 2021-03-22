FROM alpine:3.7

RUN apk update && apk upgrade
RUN apk add nginx supervisor wget \
		php7 php7-fpm php7-opcache php7-json \
		php7-gd php7-mysqli php7-zlib php7-curl

RUN mkdir -p /run/nginx /run/php

COPY ./src/default.conf /etc/nginx/conf.d/default.conf
COPY ./src/supervisor.conf /etc/supervisord.conf
COPY ./src/setup.sh ./

RUN wget https://wordpress.org/latest.tar.gz \
	&& tar -xf latest.tar.gz && \
	mv wordpress /var/www/wordpress && \
	rm -f latest.tar.gz

COPY ./src/wp-config.php /var/www/wordpress/

RUN chmod 755 -R /var/www/*
EXPOSE 5050
RUN chmod +x /setup.sh
CMD ./setup.sh