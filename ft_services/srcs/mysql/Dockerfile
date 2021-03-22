FROM alpine:3.7

RUN apk update && apk upgrade
RUN apk add mysql mysql-client 
RUN apk add openrc

VOLUME [ "/var/lib/mysql" ]
VOLUME [ "/sys/fs/cgroup" ]

COPY ./srcs/my.cnf /etc/mysql/my.cnf
COPY ./srcs/start.sh /start.sh
COPY ./srcs/wordpress.sql /

RUN chmod +x /start.sh
RUN chmod 744 /etc/mysql/my.cnf

EXPOSE 3306

CMD /start.sh