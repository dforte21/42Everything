/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:00:06 by dforte            #+#    #+#             */
/*   Updated: 2022/06/24 19:07:19 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_3d_render(t_cub3D *data)
{
	float	ray;

	ray = data->p.a - ((FOV / 2) * PI / 180);
	if (ray < 0)
		ray += 2 * PI;
	get_distance(data, ray);
	return (1);
}

void	get_distance(t_cub3D *data, float ray)
{
	int		i;
	int		x;
	int		y;
	float	dx;
	float	dy;

	i = 0;
	while (i < FOV)
	{
		data->dist[i] = 0;
		while (data->dist[i] < 1000)
		{
			dx = cos(ray);
			dy = sin(ray);
			x = (int) ((data->p.x + dx * data->dist[i]) / 64);
			y = (int) ((data->p.y + dy * data->dist[i]) / 64);
			dx = cos(ray);
			dy = sin(ray);
			if (data->map[x][y] == '1')
				break ;
			data->dist[i] += 0.1;
		}
		i++;
		ray += 0.0174533;
	}
}