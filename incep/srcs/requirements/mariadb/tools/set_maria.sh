#!/bin/sh
service mysql start;

mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
mysql $MYSQL_DATABASE -u root < ./ds_wordpress.sql
mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;"
mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

exec mysqld