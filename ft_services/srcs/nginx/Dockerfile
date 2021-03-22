FROM	alpine:3.7

RUN		apk update && apk upgrade ; \
		apk add nginx openssl openssh supervisor

COPY	./src/start_nginx.sh /tmp/
COPY	./src/nginx.conf /etc/nginx/conf.d/default.conf
COPY	./src/supervisord.conf /etc/supervisord.conf

RUN		openssl req -x509 -nodes -days 90 -newkey rsa:2048 \
		-out /etc/ssl/certs/dbolg.crt \
		-keyout /etc/ssl/certs/dbolg.key \
		-subj '/C=RU/ST=Kazan/L=Kazan/O=Ecole42/OU=School21/CN=localhost' && \
		chmod -R 755 /etc/ssl/certs/dbolg*

RUN		adduser -D  "dbolg" ; \
		echo "dbolg:12345" | chpasswd

RUN		sed -i 's/#Port 22/Port 22/g' /etc/ssh/sshd_config && \
		sed -i 's/#HostKey \/etc\/ssh\/ssh_host_rsa_key/HostKey \/etc\/ssh\/ssh_host_rsa_key/g' /etc/ssh/sshd_config && \
		sed -i 's/#HostKey \/etc\/ssh\/ssh_host_ecdsa_key/HostKey \/etc\/ssh\/ssh_host_ecdsa_key/g' /etc/ssh/sshd_config && \
		sed -i 's/#HostKey \/etc\/ssh\/ssh_host_ed25519_key/HostKey \/etc\/ssh\/ssh_host_ed25519_key/g' /etc/ssh/sshd_config

RUN		usr/bin/ssh-keygen -A ; \
		ssh-keygen -t rsa -b 4096 -f /etc/ssh/ssh_host_key

EXPOSE	22 80 443

RUN		chmod +x /tmp/start_nginx.sh
RUN		mkdir -p /run/nginx
CMD		/tmp/start_nginx.sh