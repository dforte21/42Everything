NAME = philo

SRC = ./*.c

FLAGS = -Wall -Wextra -Werror

$(NAME):
			gcc $(FLAGS) $(SRC) -o $(NAME)

all:		$(NAME)

clean:
			rm -f ./*.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re