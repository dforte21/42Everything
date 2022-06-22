NAME = philo_bonus

SRC = ./*.c

FLAGS = -Wall -Wextra -Werror

$(NAME):
			gcc $(FLAGS) $(SRC) -o $(NAME)

all:		$(NAME)

clean:
			rm -f ./*.o

fclean:		clean
			rm -f $(NAME)

re:			make fclean

.PHONY: 	all clean fclean re