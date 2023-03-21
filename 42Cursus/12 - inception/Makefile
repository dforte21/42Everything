all : up

up : 
	@docker-compose -f ./srcs/docker-compose.yml up --d

down : 
	@docker-compose -f ./srcs/docker-compose.yml down

stop : 
	@docker-compose -f ./srcs/docker-compose.yml stop

start : 
	@docker-compose -f ./srcs/docker-compose.yml start

status : 
	@docker ps
	
host:
	@ sudo echo "127.0.0.1 dforte.42.fr" >> /etc/hosts
	@ sudo echo "127.0.0.1 www.dforte.42.fr" >> /etc/hosts