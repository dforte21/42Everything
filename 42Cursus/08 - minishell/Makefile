NAME = minishell
SRC = *.c
FLG = -Wall -Wextra -Werror

$(NAME):
		make -C libft
		gcc $(FLG) $(SRC) -o $(NAME) libft/libft.a -lreadline -L/usr/include -lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include/readline

clean:
		make clean -C libft

fclean:	clean
		rm -rf $(NAME)
		make fclean -C libft

all:	$(NAME)

re:		fclean all