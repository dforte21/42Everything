NAME = push_swap
BNAME = checker
SRC = push_swap.c operations.c operations2.c operations3.c sort.c sort2.c struct.c utils.c
BSRC = checker.c struct.c operations.c operations2.c operations3.c utils.c
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

$(NAME):
			make re -C libft
			gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

bonus:		
			make re -C libft
			gcc $(FLAGS) -o $(BNAME) $(BSRC) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft

fclean:
			make fclean -C libft
			rm -f $(NAME)
			rm -f $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re bonus