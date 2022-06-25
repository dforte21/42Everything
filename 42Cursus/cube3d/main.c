/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:28 by dforte            #+#    #+#             */
/*   Updated: 2022/06/25 12:00:45 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_cub3D	data;

	ft_read_file(av[1], &data);
	ft_init(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	mlx_do_key_autorepeaton(data.mlx);
	mlx_hook(data.win, 2, (1L << 1), ft_hooks, &data);
	mlx_loop_hook(data.mlx, ft_3d_render, &data);
	mlx_loop(data.mlx);
	ft_free_struct(&data);
}
