/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:48:26 by dforte            #+#    #+#             */
/*   Updated: 2022/09/18 16:33:50 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
		data->p.pAngle -= 3;
	if (data->p.right == 1)
		data->p.pAngle += 3;
	if (data->p.w == 1)
		ftMove(degreeToRadians((float)data->p.pAngle), data);
	if (data->p.a == 1)
		ftMove(degreeToRadians((float)data->p.pAngle - 90), data);
	if (data->p.s == 1)
		ftMove(degreeToRadians((float)data->p.pAngle - 180), data);
	if (data->p.d == 1)
		ftMove(degreeToRadians((float)data->p.pAngle + 90), data);
}

void	ftMove(float angle, t_cub3D *data)
{
	float rcos;
	float rsin;

	rcos = cos(angle);
	rsin = sin(angle);
	if (data->map[(int)(data->p.y + rsin * 0.3)][(int)(data->p.x + rcos * 0.3)] == '1')
		return ;
	data->p.y += rsin * 0.1;
	data->p.x += rcos * 0.1;
}
