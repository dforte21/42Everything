NAME = webserv
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FOL = sources/
SRC_FIL = $(addprefix sources/,main.cpp Server.cpp Config.cpp)
OBJS = $(SRC_FIL:.cpp=.o)

$(NAME): $(SRC_FIL)
		c++ -c $(FLAGS) $(SRC_FIL) && mv *.o sources 
		c++ $(OBJS) -o $(NAME)

all:
		$(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf webserv

re:		fclean all

.PHONY:	all clean fclean re