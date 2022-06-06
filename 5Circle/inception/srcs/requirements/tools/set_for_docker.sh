echo "\033[47;35m--Setting for docker--\033[0m\n"


apt-get remove docker docker-engine docker.io containerd runc

apt-get update
apt-get install \
	apt-transport-https \ #APT용 https 다운로드 전송
	ca-certificates \
	curl \
	gnupg-agent \
	software-properties-common

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -apt-key fingerprint 0EBFCD88

add-apt-repository \ # 레포지토리를 추가하며 패키지 다운로드 하려 함
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

apt-get update && sudo apt-get install docker-ce docker-ce-cli containerd.iodocker run hello-world

apt-get install docker-compose

usermod -aG docker ${USER} #도커를 실행하는 유저가 도커 그룹에 포함되어야 하기 때문에 등록해줌

echo  "\033[44;33m@@@It's set up for docker@@@\033[0m\n\n"
