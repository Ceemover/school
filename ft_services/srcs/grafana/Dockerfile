FROM alpine:3.7

RUN apk update && \
    apk add ca-certificates ; \
    wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub ; \
    wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk ; \
    apk add glibc-2.28-r0.apk

RUN wget https://dl.grafana.com/oss/release/grafana-7.1.5.linux-amd64.tar.gz ; \
    tar -zxf grafana-7.1.5.linux-amd64.tar.gz ; \
    rm -f grafana-7.1.5.linux-amd64.tar.gz

COPY ./srcs/grafana.db /grafana-7.1.5/data/grafana.db

EXPOSE 3000

WORKDIR /grafana-7.1.5/bin/

CMD [ "/grafana-7.1.5/bin/grafana-server" ]