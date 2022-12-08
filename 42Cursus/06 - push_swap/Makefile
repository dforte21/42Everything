NAME = push_swap
BNAME = checker
SRC = push_swap.c operations.c operations2.c operations3.c sort.c sort2.c sort3.c struct.c struct2.c utils.c
BSRC = bonus_checker.c bonus_operations.c bonus_operations2.c bonus_operations3.c utils.c struct.c struct2.c
FLAGS = -Wall -Wextra -Werror
LIBFT = ft_printf/libftprintf.a

$(NAME):
			make re -C ft_printf
			gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

bonus:		
			make re -C ft_printf
			gcc $(FLAGS) -o $(BNAME) $(BSRC) $(LIBFT)

all:		$(NAME)
			make bonus

clean:
			make clean -C ft_printf

fclean:
			make fclean -C ft_printf
			rm -f $(NAME)
			rm -f $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re bonus