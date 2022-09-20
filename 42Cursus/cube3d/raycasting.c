/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:50:51 by dforte            #+#    #+#             */
/*   Updated: 2022/09/20 16:34:24 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ftDisplay(t_cub3D *data)
{
	t_ray	ray;

	data->ray = &ray;
	ray.rayAngle = data->p.pAngle - 30;
	ftMovements(data);
	rayCasting(data, &ray);
	ftDraw(data, &ray);
	ftMiniMap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.background.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.mMap.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.win.img, (960 - SCREEN_WIDTH / 2), (540 - SCREEN_HEIGHT / 2));
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
		ray->rayCos[i] = cos(degreeToRadians(ray->rayAngle)) / 256;
		ray->raySin[i] = sin(degreeToRadians(ray->rayAngle)) / 256;
		while (data->map[(int)ray->rayY[i]][(int)ray->rayX[i]] != '1' && data->map[(int)ray->rayY[i]][(int)ray->rayX[i]] != 'D')
		{
			ray->rayX[i] += ray->rayCos[i];
			ray->rayY[i] += ray->raySin[i];
			if (data->map[(int)ray->rayY[i]][(int)ray->rayX[i]] == 'd' || data->map[(int)ray->rayY[i]][(int)ray->rayX[i]] == 'D')
			{
				ray->wY = ray->rayY[i];
				ray->wX = ray->rayX[i];
			}
		}
		ray->distance[i] = (sqrt(pow(data->p.x - ray->rayX[i], 2) + pow(data->p.y - ray->rayY[i], 2)));
		ray->distance[i] *= cos(degreeToRadians(ray->rayAngle) - degreeToRadians(data->p.pAngle));
		ray->rayAngle += 60.0 / SCREEN_WIDTH;
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
		ray->wallHeight = SCREEN_HEIGHT / 2 / dist;
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
	getTextStart(ray, x, &yIncrementer);
	while (y < SCREEN_HEIGHT / 2 - ray->wallHeight)
	{
		my_mlx_pixel_put(&data->imgs.win, x, y, data->C);
		y++;
	}
	d = y;
	while (y < SCREEN_HEIGHT / 2 + ray->wallHeight)
	{	
		d += yIncrementer;
		while (y < d)
		{
			if (data->map[(int)ray->rayY[x]][(int)ray->rayX[x]] == '1' || data->map[(int)ray->rayY[x]][(int)ray->rayX[x]] == 'd')
				getWallOrient(data, ray, x, y);
			else if (data->map[(int)ray->rayY[x]][(int)ray->rayX[x]] == 'D')
				my_mlx_pixel_put(&data->imgs.win, x, y, printWallPixel(ray, &data->imgs.door, x));
			y++;
		}
		ray->iTexture++;
	}
	while (y < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(&data->imgs.win, x, y, data->F);
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
		my_mlx_pixel_put(&data->imgs.win, x, y, printWallPixel(ray, &data->imgs.sWall, x));
	else if (floorY < wallY && floorX == wallX)
		my_mlx_pixel_put(&data->imgs.win, x, y, printWallPixel(ray, &data->imgs.nWall, x));
	else if (floorX > wallX && floorY == wallY)
		my_mlx_pixel_put(&data->imgs.win, x, y, printWallPixel(ray, &data->imgs.eWall, x));
	else if (floorX < wallX && floorY == wallY)
		my_mlx_pixel_put(&data->imgs.win, x, y, printWallPixel(ray, &data->imgs.wWall, x));
	else
		my_mlx_pixel_put(&data->imgs.win, x, y, 0);
}
