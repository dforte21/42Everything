NAME = ft_cat
SRC = ft_cat.c ut.c
OBJS = ${SRCS:.c=.o}

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) $(SRC)

all: ${NAME}
clean: 
	rm -f $(OBJS)
fclean:
		rm -f $(NAME)