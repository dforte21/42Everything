NAME = rush-02
SRC = calc.c calc2.c dict.c main.c rush.c struct.c ut.c

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC)

all: ${NAME}
clean: fclean
fclean:
	rm -f $(NAME)
norm:
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h
re: fclean all
.PHONY : all clean fclean re .c.o test norm
