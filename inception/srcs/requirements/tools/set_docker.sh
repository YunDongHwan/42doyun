#!/bin/sh

# 혹시나 기존의 오래된 버전이 있는지 확실히 할 수 있으며, 있다면 최신 버전 설치를 위해 삭제 해줍니다.
echo -e "\e[47;35m--1. delete docker old version--\e[0m\n"
sudo apt-get remove docker docker-engine docker.io containerd runc

echo -e "\e[47;35m--2. apt update--\e[0m\n"
sudo apt-get update -y && sudo apt-get upgrade -y

# apt package index를 업데이트 하고 HTTPS를 통해 repository 를 이용하기 위해 pakcage 들을 설치 해줍니다.
echo -e "\e[47;35m--2. repository init--\e[0m\n"
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release

# Docker의 Official GPG Key 를 등록합니다.
echo -e "\e[47;35m--4. register pgp--\e[0m\n"
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg -y
#에러 발생시 crul에 표해고 L옵션으로 리다이렉션 되는경우 위치또한 표시해줌
#gpg키를 받는 이유는 설치 전 gpg키를 확인하여 인증된 패키지만을 설치하여 패키지의 무결성을 검증할 수 있음

# stable repository 를 등록해줍니다.
echo -e "\e[47;35m--5. register stable repository--\e[0m\n"
echo \
"deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
$(lsb_release -cs) stable" 
# 위의 명령어 뒤에  | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null를 붙여주면 모든 출력문을 보지 않을 수 있다.

# Docker Engine 설치하기
echo -e "\e[47;35m--6. install Docker Engine--\e[0m\n"
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io -y

# Docker compose install
echo -e "\e[47;35m--7. install Docker compose--\e[0m\n"
sudo apt-get install docker-compose -y

#docker 권한 설정 및 sudo 명령을 붙이지 않도록 도커를 실행하는 유저가 도커 그룹에 포함되어야 하기 때문에 등록해줌
echo -e "\e[47;35m--8. register user--\e[0m\n"
sudo groupadd docker
sudo usermod -aG docker ${USER} 

#docker compose 권한
echo -e "\e[47;35m--9. init docker compose permission--\e[0m\n"
sudo chmod 666 /var/run/docker.sock

#환경파일 설정
echo -e "\e[47;35m--10. Setting for environment variable load--\e[0m\n"
source ../../.env


# host 도메인 등록
echo -e "\e[47;35m--11. Host conversion operation to replace DNS--\e[0m\n"
echo '127.0.0.1 doyun.42.fr' >> /etc/hosts 
echo '127.0.0.1 www.doyun.42.fr' >> /etc/hosts 

echo -e "\e[44;33m@@@Host is set up@@@\e[0m\n\n"

