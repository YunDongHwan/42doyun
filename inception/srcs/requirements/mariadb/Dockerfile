# mariadb 셋팅
RUN sudo apt-get install software-properties-common
RUN sudo apt-key adv --fetch-keys 'https://mariadb.org/mariadb_release_signing_key.asc'
RUN sudo add-apt-repository 'deb [arch=amd64,arm64,ppc64el] https://mirror.yongbok.net/mariadb/repo/10.5/ubuntu focal main'

# MariaDB server 설치 
RUN apt-get -y update && apt-get -y upgrade
RUN sudo apt install mariadb-server vim

COPY tools/setup.sh . 
RUN chmod +x setup.sh 

EXPOSE 3306

# mysqld_safe는 한마디로 말하면 mysqld를 감시하는 데몬
ENTRYPOINT [ "mysqld_safe"]