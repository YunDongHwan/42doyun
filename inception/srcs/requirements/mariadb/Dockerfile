FROM debian:buster

MAINTAINER doyun@student.42seoul.fr


# RUN sudo curl -sS https://downloads.mariadb.com/MariaDB/mariadb_repo_setup
# # mariadb 셋팅
# RUN sudo apt-get install software-properties-common
# RUN sudo add-apt-repository 'deb [arch=amd64,arm64,ppc64el] \
# http://sfo1.mirrors.digitalocean.com/mariadb/repo/10.3/ubuntu bionic main' 
# RUN sudo deb-src 'http://sfo1.mirrors.digitalocean.com/mariadb/repo/10.3/ubuntu bionic main'

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get install -y apt-transport-https

RUN apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xF1656F24C74CD1D8


# MariaDB server 설치 
RUN apt-get -y update && apt-get -y upgrade
RUN apt install mariadb-server vim

COPY ./conf/my.cnf /etc/mysql/my.cnf
# my.cnf 파일에 포합된 다른 파일들이 첫 설치시 경로가 맞지않아 에러 발생 가능해서 옮겨줌
COPY -R /var/lib/mysql/* /data/mysql/mysql-data/

COPY tools/set_mariadb.sh ./
RUN chmod +x set_mariadb.sh 


EXPOSE 3306

# mysqld_safe는 한마디로 말하면 mysqld를 감시하는 데몬
CMD ["mysqld_safe"]