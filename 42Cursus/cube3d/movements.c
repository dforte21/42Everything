/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:46:56 by dforte            #+#    #+#             */
/*   Updated: 2022/06/24 17:47:17 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_hooks(int keycode, t_cub3D *data)
{
	int	x;
	int	y;

	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		x = (data->p.x + data->p.dx * 5) / 64;
		y = (data->p.y + data->p.dy * 5) / 64;
		if (data->map[y][x] != '1')
		{
			data->p.x += data->p.dx * 5;
			data->p.y += data->p.dy * 5;
		}
	}
	if (keycode == 1)
	{
		x = (data->p.x - data->p.dx * 5) / 64;
		y = (data->p.y - data->p.dy * 5) / 64;
		if (data->map[y][x] != '1')
		{
			data->p.x -= data->p.dx * 5;
			data->p.y -= data->p.dy * 5;
		}
	}
	if (keycode == 0)
	{
		data->p.a -= 0.1;
		if (data->p.a < 0)
			data->p.a += 2 * PI;
		data->p.dx = cos(data->p.a);
		data->p.dy = sin(data->p.a);
	}
	if (keycode == 2)
	{
		data->p.a += 0.1;
		if (data->p.a > 2 * PI)
			data->p.a -= 2 * PI;
		data->p.dx = cos(data->p.a);
		data->p.dy = sin(data->p.a);
	}
	return (0);
}
