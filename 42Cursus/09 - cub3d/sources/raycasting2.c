/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:26:28 by dforte            #+#    #+#             */
/*   Updated: 2022/12/09 19:31:20 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	printwallpixel(t_ray *ray, t_img *text, int x)
{
	int	textx;

	textx = (((ray->rayx[x] + ray->rayy[x]) * 128.0) - ((int)(ray->rayx[x] + ray->rayy[x]) * 128));
	return (gettextcolor(textx, ray->itexture, text));
}

void	gettextstart(t_ray *ray, int x, double *yincrementer)
{
	int wheigt;

	wheigt = screen_height / 2 / ray->distance[x];
	*yincrementer = (wheigt * 2) / 128.0;
	if (ray->distance[x] >= 1)
	{
		ray->itexture = 0;
		return ;
	}
	ray->itexture = (wheigt - screen_height / 2) / *yincrementer;
	*yincrementer = (ray->wallheight * 2) / (128.0 - ray->itexture * 2);
}

void	ftminimap(t_cub3d *data)
{
	int	x;
	int	y;
	int	tiles;

	x = data->p.x - 4;
	y = data->p.y - 4;
	checkcoords(&x, &y, data);
	tiles = 0;
	while (tiles < 81)
	{
		if (data->map[y][x] == '1')
			ftputtiles(data, tiles, &data->imgs.mmapw);
		else if (data->map[y][x] == 'D')
			ftputtiles(data, tiles, &data->imgs.mmapdoorc);
		else if (data->map[y][x] == 'd')
			ftputtiles(data, tiles, &data->imgs.mmapdooro);
		else
			ftputtiles(data, tiles, &data->imgs.mmapf);
		if (x == (int)data->p.x && y == (int)data->p.y)
			ftplayer(data, tiles);
		x++;
		tiles++;
		if (tiles % 9 == 0)
		{
			y++;
			x = data->p.x - 4;
			if (x < 0)
				x = 0;
			if (x > data->width - 9)
				x = data->width - 9;
		}
	}
}

void	ftputtiles(t_cub3d *data, int tiles, t_img *img)
{
	int	mmx;
	int	mmy;
	int	tx;
	int	ty;

	mmy = 20 * (tiles / 9);
	ty = 0;
	while (mmy < (((tiles / 9) + 1) * 20))
	{
		mmx = 20 * (tiles % 9);
		tx = 0;
		while (mmx < (((tiles % 9) + 1) * 20))
		{
			my_mlx_pixel_put(&data->imgs.mmap, mmx, mmy, gettextcolor(tx, ty, img));
			mmx++;
			tx++;
		}
		mmy++;
		ty++;
	}
}

void	ftplayer(t_cub3d *data, int tiles)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = (data->p.x - (int)(data->p.x)) * 20;
	y = (data->p.y - (int)(data->p.y)) * 20;
	py = 20 * (tiles / 9) + y;
	px = 20 * (tiles % 9) + x;
	my_mlx_pixel_put(&data->imgs.mmap, px, py, 16711680);
}
