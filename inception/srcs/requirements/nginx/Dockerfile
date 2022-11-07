FROM debian:buster

MAINTAINER doyun@student.42seoul.fr

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install nginx openssl vim

RUN rm /etc/nginx/sites-available/default
RUN rm /etc/nginx/sites-enabled/default

COPY conf/default.conf /etc/nginx/sites-available/default  
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



# FROM debian:buster

# RUN apt-get update -y 
# RUN	apt-get upgrade -y 
# RUN	apt-get install -y nginx
# RUN	apt-get install -y openssl

# #nginx config
# COPY    conf/default.conf ./
# RUN     mv default.conf /etc/nginx/sites-available/default
# RUN		chown -R www-data:www-data /var/www

# RUN     openssl genrsa -out server.key 4096 
# RUN     openssl req -new -key server.key -subj "/C=KR/ST=Seoul/O=42Seoul/OU=Shin" -out server.csr
# RUN     openssl req -x509 -in server.csr -key server.key -out server.crt
# RUN     mv server.crt /etc/ssl/certs/
# RUN     mv server.csr server.key /etc/ssl/private
# RUN     chmod 600 etc/ssl/certs/server.crt etc/ssl/private/server.key

# CMD     nginx -g 'daemon off;'

# EXPOSE 443 80