/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:36:43 by dforte            #+#    #+#             */
/*   Updated: 2022/11/30 17:50:04 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	checkcoords(int *x, int *y, t_cub3d *data)
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
