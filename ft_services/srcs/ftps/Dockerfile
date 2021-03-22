FROM		alpine:3.7

RUN			apk update && \
			apk add openssl vsftpd && \
			openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:1024 \
			-subj /C=RU/ST=Kazan/L=Kazan/O=Ecole42/OU=School21/CN=localhost/emailAddress=dbolg@dbolg.ru \
			-keyout /etc/vsftpd/vsftpd.pem -out /etc/vsftpd/vsftpd.pem

RUN			echo "root:12345" | chpasswd

COPY		./srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN			mkdir -p /var/log/ftp && touch /var/log/ftp/xferlog

EXPOSE		21

ENTRYPOINT	vsftpd /etc/vsftpd/vsftpd.conf