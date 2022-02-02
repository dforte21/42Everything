NAME = bsq
SRC = check_map.c errors.c find_solution.c main.c struct.c utility.c

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

all: ${NAME}
clean: fclean
fclean:
		rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re .c.o test norm