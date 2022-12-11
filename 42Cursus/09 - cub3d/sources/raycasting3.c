/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:38:47 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:47:23 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	launch_ray(t_cub3d *data, t_ray *ray, int i)
{
	while (data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] != '1'
		&& data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] != 'D')
	{
		ray->rayx[i] += ray->raycos[i];
		ray->rayy[i] += ray->raysin[i];
		if (i == SCREEN_WIDTH / 2 - 1)
		{
			if ((data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] == 'D'
				|| data->map[(int)ray->rayy[i]][(int)ray->rayx[i]] == 'd'))
			{				
				ray->wy = ray->rayy[i];
				ray->wx = ray->rayx[i];
			}
		}
	}
}

int	draw_wall(int x, int y, t_ray *ray, t_cub3d *data)
{
	double	d;
	double	yincrementer;

	gettextstart(ray, x, &yincrementer);
	d = y;
	while (y < SCREEN_HEIGHT / 2 + ray->wallheight)
	{	
		d += yincrementer;
		while (y < d)
		{
			if (data->map[(int)ray->rayy[x]][(int)ray->rayx[x]] == '1'
				|| data->map[(int)ray->rayy[x]][(int)ray->rayx[x]] == 'd')
				getwallorient(data, ray, x, y);
			else if (data->map[(int)ray->rayy[x]][(int)ray->rayx[x]] == 'D')
				my_mlx_pixel_put(&data->imgs.win, x, y,
					printwallpixel(ray, &data->imgs.door, x));
			y++;
		}
		ray->itexture++;
	}
	return (y);
}

void	draw_minimap(t_cub3d *data, int x, int y, int tiles)
{
	if (data->map[y][x] == '1' || data->map[y][x] == ' ')
		ftputtiles(data, tiles, &data->imgs.mmapw);
	else if (data->map[y][x] == 'D')
		ftputtiles(data, tiles, &data->imgs.mdc);
	else if (data->map[y][x] == 'd')
		ftputtiles(data, tiles, &data->imgs.mdo);
	else
		ftputtiles(data, tiles, &data->imgs.mmapf);
	if (x == (int)data->p.x && y == (int)data->p.y)
		ftplayer(data, tiles);
}
