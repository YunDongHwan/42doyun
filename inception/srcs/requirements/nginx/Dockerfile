FROM debian:buster

MAINTAINER doyun@student.42seoul.fr

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install nginx openssl vim

RUN rm /etc/nginx/sites-available/default
RUN rm /etc/nginx/sites-enabled/default

COPY conf/nginx.conf /etc/nginx/sites-available/default  
RUN ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -days 365 -nodes \
    -out /etc/nginx/ssl/www.doyun.42.fr.crt \   
    -keyout /etc/nginx/ssl/www.doyun.42.fr.key \
    -subj "/C=KR/ST=SEOUL/O=42/OU=GUN/CN=doyun"
RUN chmod 777 /etc/nginx/ssl/*

RUN chmod 777 -R /var/www
RUN chown -R www-data:www-data /var/www/

EXPOSE 433

CMD ["nginx", "-g", "daemon off;"]