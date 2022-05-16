/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:15:31 by dforte            #+#    #+#             */
/*   Updated: 2022/05/16 18:55:49 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_map	maps;
	t_tiles	tiles;

	if (ac != 2)
		return 1;
	maps = loadmap(av[1]);
	maps.mlx_ptr = mlx_init();
	maps.mlx_winptr = mlx_new_window(maps.mlx_ptr, maps.col * 64, maps.row * 64, "so_long");
	init_tiles(&tiles, maps);
	maps.tiles = &tiles;
	mlx_key_hook(maps.mlx_winptr, movements, &maps);
	mlx_loop_hook(maps.mlx_ptr, load_tiles, &maps);
	mlx_hook(maps.mlx_winptr, 17, 0, ft_destroy, &maps);
	mlx_loop(maps.mlx_ptr);
	free_all(&maps);
}

int	load_tiles(t_map *maps)
{
	int	i;
	int	j;

	i = 0;
	while (i < maps->row)
	{
		j = 0;
		while (j < maps->col)
		{
			put_image(maps->map[i][j], maps, j, i);
			j++;
		}
		i++;
	}
	maps->frame++;
	if (maps->frame == 20)
	{
		change_tiles(maps);
		maps->frame = 0;
	}
	put_moves(maps);
	return (0);
}

void	put_image(char map, t_map *maps, int x, int y)
{
	if (map == 'E' && maps->collectibles == 0)
	{
		maps->map[y][x] = 'e';
		maps->tiles->exit = maps->tiles->exit2;
	}
	if (map == '1')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, maps->tiles->wall, x * 64, y * 64);
	if (map == 'E' || map == 'e')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, maps->tiles->exit, x * 64, y * 64);
	if (map == 'P')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, maps->tiles->player, x * 64, y * 64);
	if (map == '0')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, maps->tiles->floor, x * 64, y * 64);
	if (map == 'C')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, maps->tiles->collect, x * 64, y * 64);
	if (map == 'X')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, maps->tiles->enemy, x * 64, y * 64);
}

void	ft_lose(t_map *maps)
{
	ft_printf("GIT GUD :)\n");
	ft_destroy(maps);
}
