NAME = ft_tail
SRC = atoi.c ft_tail.c write.c
OBJS = ${SRCS:.c=.o}

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) $(SRC)

all: ${NAME}
clean: 
	rm -f $(OBJS)
fclean:
		rm -f $(NAME)