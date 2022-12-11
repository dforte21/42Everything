/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:50:51 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:45:53 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.bground.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.mmap.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.win.img,
		(960 - SCREEN_WIDTH / 2), (540 - SCREEN_HEIGHT / 2));
	return (0);
}

void	raycasting(t_cub3d *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray->rayx[i] = data->p.x;
		ray->rayy[i] = data->p.y;
		ray->raycos[i] = cos(degreetoradians(ray->rayangle)) / 256;
		ray->raysin[i] = sin(degreetoradians(ray->rayangle)) / 256;
		launch_ray(data, ray, i);
		ray->distance[i] = (sqrt(pow(data->p.x - ray->rayx[i], 2)
					+ pow(data->p.y - ray->rayy[i], 2)));
		ray->distance[i] *= cos(degreetoradians(ray->rayangle)
				- degreetoradians(data->p.pangle));
		ray->rayangle += 60.0 / SCREEN_WIDTH;
		i++;
	}
}

void	ftdraw(t_cub3d *data, t_ray *ray)
{
	int		i;
	double	dist;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		dist = ray->distance[i];
		if (dist < 1)
			dist = 1;
		ray->wallheight = SCREEN_HEIGHT / 2 / dist;
		drawline(i, ray, data);
		i++;
	}
}

void	drawline(int x, t_ray *ray, t_cub3d *data)
{
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2 - ray->wallheight)
	{
		my_mlx_pixel_put(&data->imgs.win, x, y, data->c);
		y++;
	}
	y = draw_wall(x, y, ray, data);
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(&data->imgs.win, x, y, data->f);
		y++;
	}
}

void	getwallorient(t_cub3d *data, t_ray *ray, int x, int y)
{
	int	wallx;
	int	wally;
	int	floorx;
	int	floory;

	wallx = (int)ray->rayx[x];
	wally = (int)ray->rayy[x];
	floorx = (int)(ray->rayx[x] - ray->raycos[x]);
	floory = (int)(ray->rayy[x] - ray->raysin[x]);
	if (floory > wally && floorx == wallx)
		my_mlx_pixel_put(&data->imgs.win, x, y,
			printwallpixel(ray, &data->imgs.swall, x));
	else if (floory < wally && floorx == wallx)
		my_mlx_pixel_put(&data->imgs.win, x, y,
			printwallpixel(ray, &data->imgs.nwall, x));
	else if (floorx > wallx && floory == wally)
		my_mlx_pixel_put(&data->imgs.win, x, y,
			printwallpixel(ray, &data->imgs.ewall, x));
	else if (floorx < wallx && floory == wally)
		my_mlx_pixel_put(&data->imgs.win, x, y,
			printwallpixel(ray, &data->imgs.wwall, x));
	else
		my_mlx_pixel_put(&data->imgs.win, x, y, 0);
}
