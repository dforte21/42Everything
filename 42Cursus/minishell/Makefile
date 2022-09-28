NAME = minishell
SRC = *.c
FLG = -Wall -Wextra -Werror

$(NAME):
		make -C libft
		gcc $(SRC) -o $(NAME) libft/libft.a -lreadline

clean:
		make clean -C libft

fclean:	clean
		rm -rf $(NAME)
		make fclean -C libft

all:	$(NAME)

temp:	
		rm -rf $(NAME)

re:		temp all