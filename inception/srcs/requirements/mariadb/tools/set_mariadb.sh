#!/bin/bash

if [ ! -d "/var/lib/mysql/wordpress" ]; then 

    # MySQL 데이터 디렉토리를 초기화 시스템 테이블을 작성합니다
	mysql_install_db
    service mysql start
    
    mysql -e "CREATE USER '${MARIA_ID}'@'localhost' identified by '${MARIA_PW}';"
	mysql -e "CREATE DATABASE IF NOT EXISTS wordpress;"
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIA_ID}'@localhost IDENTIFIED BY '${MARIA_PW}';"
	mysql -e "GRANT ALL PRIVILEGES ON *.* TO '${MARIA_ID}'@'%' IDENTIFIED BY '${MARIA_PW}';"
	mysql -e "UPDATE mysql.user SET Password = PASSWORD('${MARIA_PW}') WHERE User = 'root';"
	mysql -e "FLUSH PRIVILEGES;"

    mysqladmin -uroot -p${MARIA_PW} shutdown
fi

exec mysqld_safe
