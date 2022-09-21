/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:05:21 by dforte            #+#    #+#             */
/*   Updated: 2022/09/21 17:46:34 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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
	mlx_mouse_hook(data.win, ftMouse, &data);
	mlx_loop_hook(data.mlx, ftDisplay, &data);
	mlx_hook(data.win, 17, 0, ftExit, &data);
	mlx_loop(data.mlx);
}

void	loadImages(t_cub3D *data)
{
	int	wdth;
	int	hght;

	wdth = 128;
	hght = 128;
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
	data->imgs.door.img = mlx_xpm_file_to_image(data->mlx, "./sprites/door.xpm", &wdth, &hght);
	data->imgs.door.addr = mlx_get_data_addr(data->imgs.door.img, &data->imgs.door.bpp, &data->imgs.door.ll, &data->imgs.door.e);
	wdth = 1920;
	hght = 1080;
	data->imgs.background.img = mlx_xpm_file_to_image(data->mlx, data->bGround, &wdth, &hght);
	data->imgs.background.addr = mlx_get_data_addr(data->imgs.background.img, &data->imgs.background.bpp, &data->imgs.background.ll, &data->imgs.background.e);
	data->imgs.mMap.img = mlx_new_image(data->mlx, 180, 180);
	data->imgs.mMap.addr = mlx_get_data_addr(data->imgs.mMap.img, &data->imgs.mMap.bpp, &data->imgs.mMap.ll, &data->imgs.mMap.e);
	load_mMapTiles(data);
}

void	load_mMapTiles(t_cub3D *data)
{
	int	wdth;
	int	hght;

	wdth = 20;
	hght = 20;
	data->imgs.mMapFloor.img = mlx_xpm_file_to_image(data->mlx, "./sprites/mMapFloor.xpm", &wdth, &hght);
	data->imgs.mMapFloor.addr = mlx_get_data_addr(data->imgs.mMapFloor.img, &data->imgs.mMapFloor.bpp, &data->imgs.mMapFloor.ll, &data->imgs.mMapFloor.e);
	data->imgs.mMapWall.img = mlx_xpm_file_to_image(data->mlx, "./sprites/mMapWall.xpm", &wdth, &hght);
	data->imgs.mMapWall.addr = mlx_get_data_addr(data->imgs.mMapWall.img, &data->imgs.mMapWall.bpp, &data->imgs.mMapWall.ll, &data->imgs.mMapWall.e);
	data->imgs.mMapDoorClosed.img = mlx_xpm_file_to_image(data->mlx, "./sprites/mMapDoorClosed.xpm", &wdth, &hght);
	data->imgs.mMapDoorClosed.addr = mlx_get_data_addr(data->imgs.mMapDoorClosed.img, &data->imgs.mMapDoorClosed.bpp, &data->imgs.mMapDoorClosed.ll, &data->imgs.mMapDoorClosed.e);
	data->imgs.mMapDoorOpen.img = mlx_xpm_file_to_image(data->mlx, "./sprites/mMapDoorOpen.xpm", &wdth, &hght);
	data->imgs.mMapDoorOpen.addr = mlx_get_data_addr(data->imgs.mMapDoorOpen.img, &data->imgs.mMapDoorOpen.bpp, &data->imgs.mMapDoorOpen.ll, &data->imgs.mMapDoorOpen.e);
	wdth = 256;
	hght = 256;
	data->imgs.hand1.img = mlx_xpm_file_to_image(data->mlx, "./sprites/hand1.xpm", &wdth, &hght);
	data->imgs.hand1.addr = mlx_get_data_addr(data->imgs.hand1.img, &data->imgs.hand1.bpp, &data->imgs.hand1.ll, &data->imgs.hand1.e);
	data->imgs.hand2.img = mlx_xpm_file_to_image(data->mlx, "./sprites/hand2.xpm", &wdth, &hght);
	data->imgs.hand2.addr = mlx_get_data_addr(data->imgs.hand2.img, &data->imgs.hand2.bpp, &data->imgs.hand2.ll, &data->imgs.hand2.e);
}

void	freeAll(t_cub3D *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->win);
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
