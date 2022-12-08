NAME = philo

SDIR = sources/

SRC = *.c

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

$(NAME):
			gcc $(FLAGS) $(SDIR)$(SRC) -o $(NAME)

all:		$(NAME)

clean:
			rm -f ./*.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re