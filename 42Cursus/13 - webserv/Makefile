NAME = webserv
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FOL = sources/
SRC_FIL = $(SRC_FOL)/main.cpp

$(NAME):
		c++ $(FLAGS) $(SRC_FIL) -o $(NAME)

all:
		$(NAME)

clean:
		rm -rf *.o

fclean:	clean
		rm -rf webserv

re:		fclean all

.PHONY:	all clean fclean re