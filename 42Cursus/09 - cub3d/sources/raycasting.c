/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:50:51 by dforte            #+#    #+#             */
/*   Updated: 2022/11/30 17:52:08 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ftdisplay(t_cub3d *data)
{
	t_ray	ray;

	data->ray = &ray;
	ray.rayangle = data->p.pangle - 30;
	ray.wy = 0;
	ray.wx = 0;
	ftmovements(data);
	raycasting(data, &ray);
	ftdraw(data, &ray);
	ftminimap(data);
	ftanimations(data);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.background.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.mmap.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.win.img, (960 - screen_width / 2), (540 - screen_height / 2));
	return (0);
}

void	raycasting(t_cub3d *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < screen_width)
	{
		ray->rayx[i] = data->p.x;
		ray->rayy[i] = data->p.y;
		ray->raycos[i] = cos(degreetoradians(ray->rayangle)) / 256;
		ray->raysin[i] = sin(degreetoradians(ray->rayangle)) / 256;
		while (data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] != '1' && data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] != 'D')
		{
			ray->rayx[i] += ray->raycos[i];
			ray->rayy[i] += ray->raysin[i];
			if (i == screen_width / 2 - 1)
			{
				if ((data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] == 'D' || data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] == 'd'))
				{
					ray->wy = ray->rayy[i];
					ray->wx = ray->rayx[i];
				}
			}
		}
		ray->distance[i] = (sqrt(pow(data->p.x - ray->rayx[i], 2) + pow(data->p.y - ray->rayy[i], 2)));
		ray->distance[i] *= cos(degreetoradians(ray->rayangle) - degreetoradians(data->p.pangle));
		ray->rayangle += 60.0 / screen_width;
		i++;
	}
}

void	ftdraw(t_cub3d *data, t_ray  *ray)
{
	int		i;
	double	dist;

	i = 0;
	while (i < screen_width)
	{
		dist = ray->distance[i];
		if (dist < 1)
			dist = 1;
		ray->wallheight = screen_height / 2 / dist;
		drawline(i, ray, data);
		i++;
	}
}

void	drawline(int x, t_ray *ray, t_cub3d *data)
{
	int			y;
	double		d;
	double		yincrementer;

	y = 0;
	gettextstart(ray, x, &yincrementer);
	while (y < screen_height / 2 - ray->wallheight)
	{
		my_mlx_pixel_put(&data->imgs.win, x, y, data->c);
		y++;
	}
	d = y;
	while (y < screen_height / 2 + ray->wallheight)
	{	
		d += yincrementer;
		while (y < d)
		{
			if (data->map[(int)ray->rayy[x]][(int)ray->rayx[x]] == '1' || data->map[(int)ray->rayy[x]][(int)ray->rayx[x]] == 'd')
				getwallorient(data, ray, x, y);
			else if (data->map[(int)ray->rayy[x]][(int)ray->rayx[x]] == 'D')
				my_mlx_pixel_put(&data->imgs.win, x, y, printwallpixel(ray, &data->imgs.door, x));
			y++;
		}
		ray->itexture++;
	}
	while (y < screen_height)
	{
		my_mlx_pixel_put(&data->imgs.win, x, y, data->f);
		y++;
	}
}

void	getwallorient(t_cub3d *data, t_ray *ray, int x, int y)
{
	int wallx;
	int wally;
	int	floorx;
	int floory;

	wallx = (int)ray->rayx[x];
	wally = (int)ray->rayy[x];
	floorx = (int)(ray->rayx[x] - ray->raycos[x]);
	floory = (int)(ray->rayy[x] - ray->raysin[x]);
	if (floory > wally && floorx == wallx)
		my_mlx_pixel_put(&data->imgs.win, x, y, printwallpixel(ray, &data->imgs.swall, x));
	else if (floory < wally && floorx == wallx)
		my_mlx_pixel_put(&data->imgs.win, x, y, printwallpixel(ray, &data->imgs.nwall, x));
	else if (floorx > wallx && floory == wally)
		my_mlx_pixel_put(&data->imgs.win, x, y, printwallpixel(ray, &data->imgs.ewall, x));
	else if (floorx < wallx && floory == wally)
		my_mlx_pixel_put(&data->imgs.win, x, y, printwallpixel(ray, &data->imgs.wwall, x));
	else
		my_mlx_pixel_put(&data->imgs.win, x, y, 0);
}
