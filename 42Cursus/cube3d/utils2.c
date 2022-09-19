/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:36:43 by dforte            #+#    #+#             */
/*   Updated: 2022/09/19 18:37:14 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	checkCoords(int *x, int *y, t_cub3D *data)
{
	if (*x < 0)
		*x = 0;
	if (*y < 0)
		*y = 0;
	if (*x > data->width - 9)
		*x = data->width - 9;
	if (*y >  data->height - 9)
		*y = data->height - 9;
}
