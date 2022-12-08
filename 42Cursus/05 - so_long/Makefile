NAME = so_long
SRCS = srcs/animations.c srcs/map.c srcs/mapcheck.c srcs/mapcheck2.c srcs/movements.c srcs/so_long.c srcs/utils.c
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