/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:48:26 by dforte            #+#    #+#             */
/*   Updated: 2022/11/30 18:04:13 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ftmouse(int key, int wx, int wy, t_cub3d *data)
{
	int	i;

	i = screen_width / 2 - 1;
	wx = data->ray->wx;
	wy = data->ray->wy;
	if (key == 1)
	{
		if (wx == (int)(data->p.x) && ((wy - (int)(data->p.y)) == 1 || (wy - (int)(data->p.y)) == -1))
		{
			if (data->map[wy][wx] == 'D')
				data->map[wy][wx] = 'd';
			else if (data->map[wy][wx] == 'd')
				data->map[wy][wx] = 'D';
		}
		else if (((wx - (int)(data->p.x)) == 1 || (wx - (int)(data->p.x)) == -1) && wy == (int)(data->p.y))
			{
			if (data->map[wy][wx] == 'D')
				data->map[wy][wx] = 'd';
			else if (data->map[wy][wx] == 'd')
				data->map[wy][wx] = 'D';
			}
	}
	if (key == 5)
		data->p.pangle -= 5;
	if (key == 4)
		data->p.pangle += 5;
	return (0);
}

int	ft_on(int keycode, t_cub3d *data)
{
	if (keycode == ESC)
		ftexit(data);
	if (keycode == W)
		data->p.w = 1;
	if (keycode == A)
		data->p.a = 1;
	if (keycode == S)
		data->p.s = 1;
	if (keycode == D)
		data->p.d = 1;
	if (keycode == LEFT)
		data->p.left = 1;
	if (keycode == RIGHT)
		data->p.right = 1;
	return (0);
}

int	ft_off(int keycode, t_cub3d *data)
{
	if (keycode == ESC)
		ftexit(data);
	if (keycode == W)
		data->p.w = 0;
	 if (keycode == A)
	 	data->p.a = 0;
	if (keycode == S)
	 	data->p.s = 0;
	if (keycode == D)
	 	data->p.d = 0;
	if (keycode == LEFT)
		data->p.left = 0;
	if (keycode == RIGHT)
		data->p.right = 0;
	return (0);
}

void	ftmovements(t_cub3d *data)
{
	if (data->p.left == 1)
		data->p.pangle -= 2;
	if (data->p.right == 1)
		data->p.pangle += 2;
	if (data->p.w == 1)
		ftmove(degreetoradians((double)data->p.pangle), data);
	if (data->p.a == 1)
		ftmove(degreetoradians((double)data->p.pangle - 90), data);
	if (data->p.s == 1)
		ftmove(degreetoradians((double)data->p.pangle - 180), data);
	if (data->p.d == 1)
		ftmove(degreetoradians((double)data->p.pangle + 90), data);
}

void	ftmove(double angle, t_cub3d *data)
{
	double rcos;
	double rsin;

	rcos = cos(angle);
	rsin = sin(angle);
	if (data->map[(int)(data->p.y + rsin * 0.1)][(int)(data->p.x + rcos * 0.1)] == '1' ||
		data->map[(int)(data->p.y + rsin * 0.1)][(int)(data->p.x + rcos * 0.1)] == 'D')
		return ;
	data->p.y += rsin * 0.1;
	data->p.x += rcos * 0.1;
}
