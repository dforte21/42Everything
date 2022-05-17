/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:15:31 by dforte            #+#    #+#             */
/*   Updated: 2022/05/17 20:05:58 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	char	c;

	c = '0';
	if (!check_args(ac, av, &map, c))
		return (1);
	map.mlx_ptr = mlx_init();
	map.mlx_winptr = mlx_new_window(map.mlx_ptr, map.col * 64, \
		map.row * 64, "so_long");
	init_tiles(&map);
	map.tiles.collect = map.tiles.collect1;
	map.tiles.enemy = map.tiles.enemy1;
	map.tiles.exit = map.tiles.exit1;
	map.tiles.player = map.tiles.player1;
	mlx_key_hook(map.mlx_winptr, movements, &map);
	mlx_loop_hook(map.mlx_ptr, load_tiles, &map);
	mlx_hook(map.mlx_winptr, 17, 0, ft_destroy, &map);
	mlx_loop(map.mlx_ptr);
	free_all(&map);
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
		maps->tiles.exit = maps->tiles.exit2;
	}
	if (map == '1')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, \
			maps->tiles.wall, x * 64, y * 64);
	if (map == 'E' || map == 'e')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, \
			maps->tiles.exit, x * 64, y * 64);
	if (map == 'P')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, \
		maps->tiles.player, x * 64, y * 64);
	if (map == '0')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, \
		maps->tiles.floor, x * 64, y * 64);
	if (map == 'C')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, \
		maps->tiles.collect, x * 64, y * 64);
	if (map == 'X')
		mlx_put_image_to_window(maps->mlx_ptr, maps->mlx_winptr, \
		maps->tiles.enemy, x * 64, y * 64);
}

void	ft_lose(t_map *maps)
{
	ft_printf("GIT GUD :)\n");
	ft_destroy(maps);
}

int	ft_error(char *str)
{
	ft_printf("%s\n", str);
	return (0);
}
