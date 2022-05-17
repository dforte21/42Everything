/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:07:00 by dforte            #+#    #+#             */
/*   Updated: 2022/05/17 20:02:57 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_map *maps)
{
	int	i;

	i = 0;
	while (i < maps->row)
	{
		free(maps->map[i]);
		i++;
	}
	free(maps->map);
}

void	init_tiles(t_map *maps)
{
	int	x;
	int	y;

	maps->tiles.collect1 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/collectible1.xpm", &x, &y);
	maps->tiles.collect2 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/collectible2.xpm", &x, &y);
	maps->tiles.player1 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/player1.xpm", &x, &y);
	maps->tiles.player2 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/player2.xpm", &x, &y);
	maps->tiles.wall = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/wall.xpm", &x, &y);
	maps->tiles.floor = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/floor.xpm", &x, &y);
	maps->tiles.exit1 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/exitclosed.xpm", &x, &y);
	maps->tiles.exit2 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/exitopen.xpm", &x, &y);
	maps->tiles.enemy1 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/enemy1.xpm", &x, &y);
	maps->tiles.enemy2 = mlx_xpm_file_to_image(maps->mlx_ptr, \
		"./Sprites/enemy2.xpm", &x, &y);
}

int	find_char(t_map *maps, int *x, int *y, char c)
{
	*x = 0;
	while (*x < maps->row)
	{
		*y = 0;
		while (*y < maps->col)
		{
			if (maps->map[*x][*y] == c)
				return (1);
			*y += 1;
		}
		*x += 1;
	}
	return (0);
}

int	ft_destroy(t_map *maps)
{
	mlx_destroy_window(maps->mlx_ptr, maps->mlx_winptr);
	free_all(maps);
	exit(0);
}

void	put_moves(t_map *maps)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa(maps->moves);
	str2 = ft_strjoin("MOVES: ", str1);
	mlx_string_put(maps->mlx_ptr, maps->mlx_winptr, \
		0 * 64, 0 * 64, 0xff0000, str2);
	free(str1);
	free(str2);
}
