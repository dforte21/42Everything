NAME = push_swap
SRC = *.c
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

$(NAME):
			make -C libft
			gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft

fclean:
			make fclean -C libft
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re