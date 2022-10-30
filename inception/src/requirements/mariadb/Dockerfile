# mariadb 셋팅
RUN sudo apt-get install software-properties-common
RUN sudo apt-key adv --fetch-keys 'https://mariadb.org/mariadb_release_signing_key.asc'
RUN sudo add-apt-repository 'deb [arch=amd64,arm64,ppc64el] https://mirror.yongbok.net/mariadb/repo/10.5/ubuntu focal main'

# MariaDB server 설치 
RUN sudo apt update;
RUN sudo apt install mariadb-server
