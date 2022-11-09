.PHONY:	all up fclean

all:
		@sudo mkdir -p /home/doyun/data/wordpress
		@sudo mkdir -p /home/doyun/data/database
		@sudo chmod 777 /etc/hosts
		@sudo echo "127.0.0.1 doyun.42.fr" >> /etc/hosts
		@sudo docker-compose -f srcs/docker-compose.yml up --build -d

install:
		@sudo sudo sh ./srcs/requirements/tools/set_docker.sh

up:
		@sudo docker-compose -f srcs/docker-compose.yml up --build -d

fclean:
		@sudo docker-compose -f srcs/docker-compose.yml down --rmi all --volumes
		@sudo docker rmi debian:buster
		@sudo rm -rf /home/doyun/data
