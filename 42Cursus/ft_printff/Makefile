NAME =	libftprintf.a
SRCS =	char.c \
		digit.c \
		digit2.c \
		ft_printf.c \
		ft_putnbr_base.c \
		ft_uitoa.c \
		hex.c \
		hex2.c \
		pointer.c \
		string.c \
		uint.c \
		uint2.c \
		utils.c \
		utils2.c

OBJS =	$(SRCS:.c=.o)
FLAGS =	-Wall -Wextra -Werror
LIBFT =	libft.a

$(NAME):
		make -C libft
		cp libft/libft.a $(NAME)
		gcc -c $(FLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: 	$(NAME)

bonus:	$(NAME)

clean:	
		rm -f $(OBJS)
	
fclean:	clean
		rm -f $(NAME) $(LIBFT)
		make fclean -C libft
	
re:		fclean all

.PHONY: all clean fclean re