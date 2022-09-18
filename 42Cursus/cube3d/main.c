/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:05:21 by dforte            #+#    #+#             */
/*   Updated: 2022/09/18 16:55:55 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main(int ac, char **av)
{
	t_cub3D data;

	if (ac != 2)
		return (1);
	data.height = 0;
	read_file(av[1], &data);
	data.map = loadMap(av[1], &data);
	initPlayer(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cub3D");
	loadImages(&data);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_hook(data.win, 2, 0, ft_on, &data);
	mlx_hook(data.win, 3, 0, ft_off, &data);
	mlx_loop_hook(data.mlx, ftDisplay, &data);
	mlx_loop(data.mlx);
}

void	loadImages(t_cub3D *data)
{
	int	wdth;
	int	hght;

	wdth = 64;
	hght = 64;
	data->imgs.win.img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->imgs.win.addr = mlx_get_data_addr(data->imgs.win.img, &data->imgs.win.bpp, &data->imgs.win.ll, &data->imgs.win.e);
	data->imgs.nWall.img = mlx_xpm_file_to_image(data->mlx, data->NO, &wdth, &hght);
	data->imgs.nWall.addr = mlx_get_data_addr(data->imgs.nWall.img, &data->imgs.nWall.bpp, &data->imgs.nWall.ll, &data->imgs.nWall.e);
	data->imgs.sWall.img = mlx_xpm_file_to_image(data->mlx, data->SO, &wdth, &hght);
	data->imgs.sWall.addr = mlx_get_data_addr(data->imgs.sWall.img, &data->imgs.sWall.bpp, &data->imgs.sWall.ll, &data->imgs.sWall.e);
	data->imgs.wWall.img = mlx_xpm_file_to_image(data->mlx, data->WE, &wdth, &hght);
	data->imgs.wWall.addr = mlx_get_data_addr(data->imgs.wWall.img, &data->imgs.wWall.bpp, &data->imgs.wWall.ll, &data->imgs.wWall.e);
	data->imgs.eWall.img = mlx_xpm_file_to_image(data->mlx, data->EA, &wdth, &hght);
	data->imgs.eWall.addr = mlx_get_data_addr(data->imgs.eWall.img, &data->imgs.eWall.bpp, &data->imgs.eWall.ll, &data->imgs.eWall.e);
	wdth = 1920;
	hght = 1080;
	data->imgs.background.img = mlx_xpm_file_to_image(data->mlx, data->bGround, &wdth, &hght);
	data->imgs.background.addr = mlx_get_data_addr(data->imgs.background.img, &data->imgs.background.bpp, &data->imgs.background.ll, &data->imgs.background.e);
}

void	freeAll(t_cub3D *data)
{
	int	i;

	i = 0;
	free(data->NO);
	free(data->WE);
	free(data->EA);
	free(data->SO);
	free(data->bGround);
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
