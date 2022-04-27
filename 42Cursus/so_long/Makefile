NAME = so_long
SRCS = *.c
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGl -framework AppKit
PRINTF = ft_printf/libftprintf.a

$(NAME):
			make re -C ft_printf
			gcc $(FLAGS) -o $(NAME) $(SRCS) $(PRINTF)

all:		$(NAME)

clean:		
			make clean -C ft_printf

fclean:
			make fclean -C ft_printf
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re