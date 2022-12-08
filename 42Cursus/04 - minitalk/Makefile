SERVER = server
SERVERSRCS = server.c
CLIENT = client
CLIENTSRCS = client.c
FLAGS =	-Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a

$(SERVER):
			make re -C ft_printf
			gcc $(FLAGS) -o $(SERVER) $(SERVERSRCS) $(PRINTF)

$(CLIENT):
			make re -C ft_printf
			gcc $(FLAGS) -o $(CLIENT) $(CLIENTSRCS) $(PRINTF)

all: 		$(SERVER) $(CLIENT)

clean:	
			make clean -C ft_printf
	
fclean:		
			make fclean -C ft_printf
			rm -f $(SERVER)
			rm -f $(CLIENT)
	
re:			fclean all

.PHONY: 	all clean fclean re