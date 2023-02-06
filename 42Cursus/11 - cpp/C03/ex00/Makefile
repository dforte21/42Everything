NAME = Claptrap
SRC = *.cpp
FLG = -Wall -Wextra -Werror -std=c++98

$(NAME):
		c++ $(FLG) $(SRC) -o $(NAME)

clean:
		rm *.o

fclean:
		rm -rf $(NAME)

all:	$(NAME)

re:		fclean all