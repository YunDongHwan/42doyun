FROM debian:buster

MAINTAINER doyun@student.42seoul.fr

# MariaDB server 설치 
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get install mariadb-server vim -y

COPY ./conf/my.cnf /etc/mysql/my.cnf
# my.cnf 파일에 포합된 다른 파일들이 첫 설치시 경로가 맞지않아 에러 발생 가능해서 옮겨줌
# COPY -R /var/lib/mysql/* /data/mysql/mysql-data/

COPY tools/set_mariadb.sh ./
RUN chmod +x set_mariadb.sh 


EXPOSE 3306

# mysqld_safe는 한마디로 말하면 mysqld를 감시하는 데몬
CMD ["sh", "/set_mariadb.sh"]