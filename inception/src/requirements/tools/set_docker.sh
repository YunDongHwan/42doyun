#!/bin/sh

# 혹시나 기존의 오래된 버전이 있는지 확실히 할 수 있으며, 있다면 최신 버전 설치를 위해 삭제 해줍니다.
echo -e "\e[47;35m--delete docker old version--\e[0m\n"
sudo apt-get remove docker docker-engine docker.io containerd runc

echo -e "\e[47;35m--install git--\e[0m\n"
sudo apt-get update

echo -e "\e[47;35m--install make--\e[0m\n"
apt-get install make

# apt package index를 업데이트 하고 HTTPS를 통해 repository 를 이용하기 위해 pakcage 들을 설치 해줍니다.
echo -e "\e[47;35m--repository init--\e[0m\n"
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release

# Docker의 Official GPG Key 를 등록합니다.
echo -e "\e[47;35m--register pgp--\e[0m\n"
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg

# stable repository 를 등록해줍니다.
echo \
"deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
$(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

# Docker Engine 설치하기
sudo apt-get install docker-ce docker-ce-cli containerd.io

#sudo 명령을 붙이지 않도록 도커를 실행하는 유저가 도커 그룹에 포함되어야 하기 때문에 등록해줌
usermod -aG docker ${USER} 


echo -e "\e[47;35m--Setting for environment variable load--\e[0m\n"
source ../../.env

echo -e "\e[44;33m@@@It's set up@@@\e[0m\n\n"

echo -e "\e[47;35m--Host conversion operation to replace DNS--\e[0m\n"
echo '127.0.0.1 doyun.42.fr' >> /etc/hosts 
echo '127.0.0.1 www.doyun.42.fr' >> /etc/hosts 

echo -e "\e[44;33m@@@Host is set up@@@\e[0m\n\n"

