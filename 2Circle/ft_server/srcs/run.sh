#!/bin/bash

openssl req -x509 -nodes -days 365 -newkey rsa:4096 -subj "/C=KR/ST=Gyeonggi/L=Bucheon/O=42seoul/OU=Gun/CN=doyun" -keyout /etc/ssl/private/localhost.dev.key -out /etc/ssl/certs/localhost.dev.crt

service mysql start
service php7.3-fpm start
service php7.3-fpm status


mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'doyun'@'localhost' IDENTIFIED BY '123456' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

service nginx start

bash
