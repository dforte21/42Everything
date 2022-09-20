/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:26:28 by dforte            #+#    #+#             */
/*   Updated: 2022/09/20 17:12:43 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	printWallPixel(t_ray *ray, t_img *text, int x)
{
	int	textX;
	int	textY;

	textX = (((ray->rayX[x] + ray->rayY[x]) * 128.0) - ((int)(ray->rayX[x] + ray->rayY[x]) * 128));
	return (getTextColor(textX, ray->iTexture, text));
}

void	getTextStart(t_ray *ray, int x, float *yIncrementer)
{
	int wheigt;

	wheigt = SCREEN_HEIGHT / 2 / ray->distance[x];
	*yIncrementer = (wheigt * 2) / 128.0;
	if (ray->distance[x] >= 1)
	{
		ray->iTexture = 0;
		return ;
	}
	ray->iTexture = (wheigt - SCREEN_HEIGHT / 2) / *yIncrementer;
	*yIncrementer = (ray->wallHeight * 2) / (128.0 - ray->iTexture * 2);
}

void	ftMiniMap(t_cub3D *data)
{
	int	x;
	int	y;
	int	tiles;

	x = data->p.x - 4;
	y = data->p.y - 4;
	checkCoords(&x, &y, data);
	tiles = 0;
	while (tiles < 81)
	{
		if (data->map[y][x] == '1')
			ftPutTiles(data, tiles, &data->imgs.mMapWall);
		else if (data->map[y][x] == 'D')
			ftPutTiles(data, tiles, &data->imgs.mMapDoorClosed);
		else if (data->map[y][x] == 'd')
			ftPutTiles(data, tiles, &data->imgs.mMapDoorOpen);
		else
			ftPutTiles(data, tiles, &data->imgs.mMapFloor);
		if (x == (int)data->p.x && y == (int)data->p.y)
			ftPlayer(data, tiles);
		x++;
		tiles++;
		if (tiles % 9 == 0)
		{
			y++;
			x = data->p.x - 4;
		}
	}
}

void	ftPutTiles(t_cub3D *data, int tiles, t_img *img)
{
	int	mmX;
	int	mmY;
	int	tX;
	int	tY;

	mmY = 20 * (tiles / 9);
	tY = 0;
	while (mmY < (((tiles / 9) + 1) * 20))
	{
		mmX = 20 * (tiles % 9);
		tX = 0;
		while (mmX < (((tiles % 9) + 1) * 20))
		{
			my_mlx_pixel_put(&data->imgs.mMap, mmX, mmY, getTextColor(tX, tY, img));
			mmX++;
			tX++;
		}
		mmY++;
		tY++;
	}
}

void	ftPlayer(t_cub3D *data, int tiles)
{
	int	x;
	int	y;
	int	pX;
	int	pY;

	x = (data->p.x - (int)(data->p.x)) * 20;
	y = (data->p.y - (int)(data->p.y)) * 20;
	pY = 20 * (tiles / 9) + y;
	pX = 20 * (tiles % 9) + x;
	my_mlx_pixel_put(&data->imgs.mMap, pX, pY, 16711680);
}
