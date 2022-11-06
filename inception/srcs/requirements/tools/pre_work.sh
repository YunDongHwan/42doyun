#!/bin/sh

echo -e "\e[47;35m--Remove images and containers--\e[0m\n"

docker-compose down 
docker system prune -a

echo -e "\e[44;33m@@@It's all been erased@@@\e[0m\n\n"