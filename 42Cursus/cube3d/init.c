/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:35:08 by dforte            #+#    #+#             */
/*   Updated: 2022/06/24 18:55:23 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init(t_cub3D *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	find_player(data, &x, &y);
	data->p.x = x * 64;
	data->p.y = y * 64;
	data->p.a = 0;
	data->p.dx = cos(data->p.a);
	data->p.dy = sin(data->p.a);
}

void	find_player(t_cub3D *data, int *x, int *y)
{
	while (data->map[*x])
	{
		*y = 0;
		while (data->map[*x][*y])
		{
			if (data->map[*x][*y] == 'N' || data->map[*x][*y] == 'S' ||
				data->map[*x][*y] == 'W' || data->map[*x][*y] == 'E')
				return ;
			*y += 1;
		}
		*x += 1;
	}
}
