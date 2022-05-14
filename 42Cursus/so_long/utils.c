/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:07:00 by dforte            #+#    #+#             */
/*   Updated: 2022/04/29 19:03:04 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_tiles(t_tiles *tiles, t_map maps)
{
	int	x;
	int	y;

	tiles->collect1 = mlx_xpm_file_to_image(maps.mlx_ptr, "./Sprites/collectible.xpm", &x, &y);
	tiles->player1 = mlx_xpm_file_to_image(maps.mlx_ptr, "./Sprites/player.xpm", &x, &y);
	tiles->wall1 = mlx_xpm_file_to_image(maps.mlx_ptr, "./Sprites/Wall.xpm", &x, &y);
	tiles->floor1 = mlx_xpm_file_to_image(maps.mlx_ptr, "./Sprites/floor.xpm", &x, &y);
	tiles->exit1 = mlx_xpm_file_to_image(maps.mlx_ptr, "./Sprites/exit.xpm", &x, &y);
}

void	find_player(t_map *maps, int *x, int *y)
{
	*x = 0;
	while (*x < maps->row)
	{
		*y = 0;
		while (*y < maps->col)
		{
			if (maps->map[*x][*y] == 'P')
				return ;
			*y += 1;
		}
		*x += 1;
	}
}
