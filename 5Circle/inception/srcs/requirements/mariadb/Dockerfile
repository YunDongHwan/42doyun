FROM debian:buster

# install mariadb
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install mariadb-server -y

# config mariadb
COPY ./tools/set_maria.sh ./set_maria.sh
COPY ./conf/my.cnf ./etc/mysql/my.cnf
COPY ./conf/ds_wordpress.sql ./

ENTRYPOINT ["sh", "./set_maria.sh"]

EXPOSE 3306
