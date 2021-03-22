FROM alpine:3.7

RUN apk update && apk upgrade
RUN apk add supervisor wget

RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub ; \
    wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk ; \
    apk add glibc-2.28-r0.apk ; \
    wget https://dl.influxdata.com/influxdb/releases/influxdb-1.8.2-static_linux_amd64.tar.gz ; \
	mkdir -r /var/lib/influxdb/data ; \
	tar xfz influxdb-1.8.2-static_linux_amd64.tar.gz ; \
	mv /influxdb-1.8.2-1 /etc/influxdb ; \
	rm -f influxdb-1.8.2-static_linux_amd64.tar.gz

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_linux_amd64.tar.gz ; \
    tar -zxf telegraf-1.15.3_linux_amd64.tar.gz ; \
    cp -r /telegraf-1.15.3/* / ; \
    rm -rf /telegraf-1.15.3/ telegraf-1.15.3_linux_amd64.tar.gz

COPY ./src/setup.sh /setup.sh
COPY ./src/supervizord.conf /etc/supervisord.conf

RUN chmod +x /setup.sh

VOLUME /var/lib/influxdb/data

RUN ./usr/bin/telegraf -sample-config --input-filter docker --output-filter influxdb > etc/telegraf/telegraf.conf

CMD /setup.sh