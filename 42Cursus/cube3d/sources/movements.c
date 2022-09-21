/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:48:26 by dforte            #+#    #+#             */
/*   Updated: 2022/09/21 17:43:54 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ftMouse(int key, int wX, int wY, t_cub3D *data)
{
	int	i;

	i = SCREEN_WIDTH / 2 - 1;
	wX = data->ray->wX;
	wY = data->ray->wY;
	if (key == 1)
	{
		if (wX == (int)(data->p.x) && ((wY - (int)(data->p.y)) == 1 || (wY - (int)(data->p.y)) == -1))
		{
			if (data->map[wY][wX] == 'D')
				data->map[wY][wX] = 'd';
			else if (data->map[wY][wX] == 'd')
				data->map[wY][wX] = 'D';
		}
		else if (((wX - (int)(data->p.x)) == 1 || (wX - (int)(data->p.x)) == -1) && wY == (int)(data->p.y))
			{
			if (data->map[wY][wX] == 'D')
				data->map[wY][wX] = 'd';
			else if (data->map[wY][wX] == 'd')
				data->map[wY][wX] = 'D';
			}
	}
	if (key == 5)
		data->p.pAngle -= 5;
	if (key == 4)
		data->p.pAngle += 5;
	return (0);
}

int	ft_on(int keycode, t_cub3D *data)
{
	if (keycode == ESC)
		ftExit(data);
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

int	ft_off(int keycode, t_cub3D *data)
{
	if (keycode == ESC)
		ftExit(data);
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

void	ftMovements(t_cub3D *data)
{
	if (data->p.left == 1)
		data->p.pAngle -= 2;
	if (data->p.right == 1)
		data->p.pAngle += 2;
	if (data->p.w == 1)
		ftMove(degreeToRadians((double)data->p.pAngle), data);
	if (data->p.a == 1)
		ftMove(degreeToRadians((double)data->p.pAngle - 90), data);
	if (data->p.s == 1)
		ftMove(degreeToRadians((double)data->p.pAngle - 180), data);
	if (data->p.d == 1)
		ftMove(degreeToRadians((double)data->p.pAngle + 90), data);
}

void	ftMove(double angle, t_cub3D *data)
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