/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:50:51 by dforte            #+#    #+#             */
/*   Updated: 2022/09/18 17:29:37 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ftDisplay(t_cub3D *data)
{
	t_ray	ray;

	ray.rayAngle = data->p.pAngle - 30;
	ftMovements(data);
	rayCasting(data, &ray);
	ftDraw(data, &ray);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.background.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.win.img, 640, 300);
	return (0);
}

void	rayCasting(t_cub3D *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray->rayX[i] = data->p.x;
		ray->rayY[i] = data->p.y;
		ray->rayCos[i] = cos(degreeToRadians(ray->rayAngle)) / 64;
		ray->raySin[i] = sin(degreeToRadians(ray->rayAngle)) / 64;
		while (data->map[(int)ray->rayY[i]][(int)ray->rayX[i]] != '1')
		{
			ray->rayX[i] += ray->rayCos[i];
			ray->rayY[i] += ray->raySin[i];
		}
		ray->distance[i] = (sqrt(pow(data->p.x - ray->rayX[i], 2) + pow(data->p.y - ray->rayY[i], 2)));
		ray->distance[i] *= cos(degreeToRadians(ray->rayAngle) - degreeToRadians(data->p.pAngle));
		ray->rayAngle += 0.09375;
		i++;
	}
}

void	ftDraw(t_cub3D *data, t_ray  *ray)
{
	int		i;
	float	dist;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		dist = ray->distance[i];
		if (dist < 1)
			dist = 1;
		ray->wallHeight = 320 / dist;
		drawLine(i, ray, data);
		i++;
	}
}

void	drawLine(int x, t_ray *ray, t_cub3D *data)
{
	int			y;
	float		d;
	float		yIncrementer;

	y = 0;
	ray->iTexture = getTextStart(ray, x);
	yIncrementer = (ray->wallHeight * 2) / 64.0;
	while (y < SCREEN_HEIGHT / 2 - ray->wallHeight)
	{
		my_mlx_pixel_put(data, x, y, data->C);
		y++;
	}
	d = y;
	while (ray->iTexture < 64)
	{	
		d += yIncrementer;
		while (y < d)
		{
			getWallOrient(data, ray, x, y);
			y++;
		}
		ray->iTexture++;
	}
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, data->F);
		y++;
	}
}

void	getWallOrient(t_cub3D *data, t_ray *ray, int x, int y)
{
	int wallX;
	int wallY;
	int	floorX;
	int floorY;

	wallX = (int)ray->rayX[x];
	wallY = (int)ray->rayY[x];
	floorX = (int)(ray->rayX[x] - ray->rayCos[x]);
	floorY = (int)(ray->rayY[x] - ray->raySin[x]);
	if (floorY > wallY && floorX == wallX)
		my_mlx_pixel_put(data, x, y, printWallPixel(ray, &data->imgs.sWall, x));
	else if (floorY < wallY && floorX == wallX)
		my_mlx_pixel_put(data, x, y, printWallPixel(ray, &data->imgs.nWall, x));
	else if (floorX > wallX && floorY == wallY)
		my_mlx_pixel_put(data, x, y, printWallPixel(ray, &data->imgs.eWall, x));
	else if (floorX < wallX && floorY == wallY)
		my_mlx_pixel_put(data, x, y, printWallPixel(ray, &data->imgs.wWall, x));
	else
		my_mlx_pixel_put(data, x, y, 0);
}
