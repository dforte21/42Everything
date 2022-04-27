/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:15:31 by dforte            #+#    #+#             */
/*   Updated: 2022/04/27 16:55:35 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_map	maps;

	if (ac != 2)
		return 1;
	maps = loadmap(av[1]);
	maps.mlx_ptr = mlx_init();
	maps.mlx_winptr = mlx_new_window(maps.mlx_ptr, maps.col * 64, maps.row * 64, "so_long");
	mlx_loop_hook(maps.mlx_ptr, load_tiles, &maps);
	mlx_loop(maps.mlx_ptr);
}