#!/bin/sh


# apt package install
echo -e "\e[47;35m--install git--\e[0m\n"
sudo apt-get update
echo -e "\e[47;35m--repository init--\e[0m\n"
sudo apt-get install \

echo -e "\e[47;35m--Remove images and containers--\e[0m\n"

docker-compose down 
docker system prune -a

echo -e "\e[44;33m@@@It's all been erased@@@\e[0m\n\n"
