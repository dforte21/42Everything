NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c \
		char.c digit.c digit2.c ft_printf.c ft_putnbr_base.c ft_uitoa.c hex.c hex2.c pointer.c string.c uint.c uint2.c utils.c utils2.c
OBJS = $(SRCS:.c=.o)
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstmap.c
BOBJS = $(BSRCS:.c=.o)
HDRS =  libft.h
FLAGS = -Wall -Wextra -Werror

$(NAME):
		gcc -c $(FLAGS) -I $(HDRS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: 		$(NAME)

clean: 		
			rm -f $(OBJS)
			rm -f $(BOBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

bonus:	
		gcc -c $(FLAGS) -I $(HDRS) $(BSRCS)
		ar rc $(NAME) $(BOBJS)
		ranlib $(NAME)

.PHONY:		all clean fclean re