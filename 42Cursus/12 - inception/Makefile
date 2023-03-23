all : up start

clean : stop down
		./clean

fclean : stop down
		./clean
		sudo rm -rf /home/dforte/data/wordpress/*
		sudo rm -rf /home/dforte/data/mariadb/*

up : 
	@sudo docker-compose -f ./srcs/docker-compose.yml up --d

down : 
	@sudo docker-compose -f ./srcs/docker-compose.yml down

stop : 
	@sudo docker-compose -f ./srcs/docker-compose.yml stop

start : 
	@sudo docker-compose -f ./srcs/docker-compose.yml start

status : 
	@sudo docker ps
	
host:
	@ sudo echo "127.0.0.1 dforte.42.fr" >> /etc/hosts
	@ sudo echo "127.0.0.1 www.dforte.42.fr" >> /etc/hosts
