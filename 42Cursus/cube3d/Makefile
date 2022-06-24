NAME = cub3D
SRC = *.c
FLG = -Wall -Wextra -Werror
MLX_FLG = -l mlx -framework openGL -framework AppKit

$(NAME):
		make -C libft
		gcc $(MLX_FLG) $(SRC) -o $(NAME) libft/libft.a

clean:
		make clean -C libft

fclean:	clean
		rm -rf $(NAME)
		make fclean -C libft

all:	$(NAME)

re:		fclean all