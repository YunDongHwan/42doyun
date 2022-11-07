FROM debian:buster

MAINTAINER doyun@student.42seoul.fr


RUN     apt-get update -y && apt-get upgrade -y
RUN     apt-get install -y tar
RUN 	apt-get install -y php
# php가 mysql에 접근할 수 있게 하는 모듈 
RUN     apt-get install -y php-mysql
RUN 	apt-get install -y php-fpm
RUN		apt-get install -y wget

# Download and Extract
RUN     wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz
RUN		rm latest.tar.gz
RUN		mv -f wordpress /var/www/

RUN 	rm -rf /var/www/wordpress/wp-config-sample.php
COPY	./conf/wp-config.php /var/www/wordpress

# nginx에 /var/www/wordpress 접근 권한 주기
RUN     chown -R www-data:www-data /var/www/wordpress

COPY	./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
RUN 	mkdir -p /run/php/

EXPOSE 9000

# php-fpm을 forground에서 실행
ENTRYPOINT ["php-fpm7.3", "-F"]