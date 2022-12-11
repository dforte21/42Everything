/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:05:21 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:56:19 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	data;

	if (ac != 2)
		return (1);
	data.height = 0;
	ft_check_file(av[1], &data);
	read_file(av[1], &data);
	ft_check_info(&data);
	data.map = loadmap(av[1], &data, 0);
	ft_check_map(data.map, &data, 0, 0);
	initplayer(&data, 0, 0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cub3d");
	loadimages(&data);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_hook(data.win, 2, 0, ft_on, &data);
	mlx_hook(data.win, 3, 0, ft_off, &data);
	mlx_mouse_hook(data.win, ftmouse, &data);
	mlx_loop_hook(data.mlx, ftdisplay, &data);
	mlx_hook(data.win, 17, 0, ftexit, &data);
	mlx_loop(data.mlx);
}

void	loadimages(t_cub3d *data)
{
	int	wdth;
	int	hght;

	data->imgs.win.img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->imgs.win.addr = mlx_get_data_addr(data->imgs.win.img,
			&data->imgs.win.bpp, &data->imgs.win.ll, &data->imgs.win.e);
	data->imgs.door.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/door.xpm", &wdth, &hght);
	data->imgs.door.addr = mlx_get_data_addr(data->imgs.door.img,
			&data->imgs.door.bpp, &data->imgs.door.ll, &data->imgs.door.e);
	data->imgs.bground.img = mlx_xpm_file_to_image(data->mlx,
			data->bground, &wdth, &hght);
	data->imgs.bground.addr = mlx_get_data_addr(data->imgs.bground.img,
			&data->imgs.bground.bpp,
			&data->imgs.bground.ll, &data->imgs.bground.e);
	data->imgs.mmap.img = mlx_new_image(data->mlx, 180, 180);
	data->imgs.mmap.addr = mlx_get_data_addr(data->imgs.mmap.img,
			&data->imgs.mmap.bpp, &data->imgs.mmap.ll, &data->imgs.mmap.e);
	load_mmaptiles(data, 20, 20);
	load_walltiles(data, 128, 128);
}

void	load_walltiles(t_cub3d *data, int wdth, int hght)
{
	data->imgs.nwall.img = mlx_xpm_file_to_image(data->mlx,
			data->no, &wdth, &hght);
	data->imgs.nwall.addr = mlx_get_data_addr(data->imgs.nwall.img,
			&data->imgs.nwall.bpp, &data->imgs.nwall.ll, &data->imgs.nwall.e);
	data->imgs.swall.img = mlx_xpm_file_to_image(data->mlx,
			data->so, &wdth, &hght);
	data->imgs.swall.addr = mlx_get_data_addr(data->imgs.swall.img,
			&data->imgs.swall.bpp, &data->imgs.swall.ll, &data->imgs.swall.e);
	data->imgs.wwall.img = mlx_xpm_file_to_image(data->mlx,
			data->we, &wdth, &hght);
	data->imgs.wwall.addr = mlx_get_data_addr(data->imgs.wwall.img,
			&data->imgs.wwall.bpp, &data->imgs.wwall.ll, &data->imgs.wwall.e);
	data->imgs.ewall.img = mlx_xpm_file_to_image(data->mlx,
			data->ea, &wdth, &hght);
	data->imgs.ewall.addr = mlx_get_data_addr(data->imgs.ewall.img,
			&data->imgs.ewall.bpp, &data->imgs.ewall.ll, &data->imgs.ewall.e);
}

void	load_mmaptiles(t_cub3d *data, int wdth, int hght)
{
	data->imgs.mmapf.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/mMapF.xpm", &wdth, &hght);
	data->imgs.mmapf.addr = mlx_get_data_addr(data->imgs.mmapf.img,
			&data->imgs.mmapf.bpp, &data->imgs.mmapf.ll, &data->imgs.mmapf.e);
	data->imgs.mmapw.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/mMapW.xpm", &wdth, &hght);
	data->imgs.mmapw.addr = mlx_get_data_addr(data->imgs.mmapw.img,
			&data->imgs.mmapw.bpp, &data->imgs.mmapw.ll, &data->imgs.mmapw.e);
	data->imgs.mdc.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/mMapDoorC.xpm", &wdth, &hght);
	data->imgs.mdc.addr = mlx_get_data_addr(data->imgs.mdc.img,
			&data->imgs.mdc.bpp, &data->imgs.mdc.ll, &data->imgs.mdc.e);
	data->imgs.mdo.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/mMapDoorO.xpm", &wdth, &hght);
	data->imgs.mdo.addr = mlx_get_data_addr(data->imgs.mdo.img,
			&data->imgs.mdo.bpp, &data->imgs.mdo.ll, &data->imgs.mdo.e);
	data->imgs.hand.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/gun.xpm", &wdth, &hght);
	data->imgs.hand.addr = mlx_get_data_addr(data->imgs.hand.img,
			&data->imgs.hand.bpp, &data->imgs.hand.ll, &data->imgs.hand.e);
	data->imgs.face.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/face.xpm", &wdth, &hght);
	data->imgs.face.addr = mlx_get_data_addr(data->imgs.face.img,
			&data->imgs.face.bpp, &data->imgs.face.ll, &data->imgs.face.e);
}

void	freeall(t_cub3d *data)
{
	int	i;

	i = 0;
	if (data->no)
		free(data->no);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->so)
		free(data->so);
	if (data->bground)
		free(data->bground);
	while (i < data->height)
	{
		if (data->map && data->map[i])
			free(data->map[i]);
		i++;
	}
	if (data->map)
		free(data->map);
}
