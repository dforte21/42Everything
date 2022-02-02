NAME = do-op
SRC = atoi.c main.c putnbr.c
OBJS = ${SRCS:.c=.o}

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) $(SRC)

all: ${NAME}
clean: 
	rm -f $(OBJS)
fclean:
		rm -f $(NAME)