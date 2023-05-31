NAME = webserv
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FOL = sources/
SRC_FIL = $(addprefix sources/,main.cpp Cluster.cpp Server.cpp Config.cpp \
			ConfigSetters.cpp ConfigGetters.cpp Pfds.cpp)
#OBJS = $(SRC_FIL:.cpp=.o)
OBJS = *.o
$(NAME): $(SRC_FIL)
		c++ -c $(SRC_FIL)
		c++ $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re