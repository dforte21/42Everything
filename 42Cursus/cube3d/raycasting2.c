/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:26:28 by dforte            #+#    #+#             */
/*   Updated: 2022/09/18 18:00:06 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	printWallPixel(t_ray *ray, t_img *text, int x)
{
	int	textX;
	int	textY;

	textX = (((ray->rayX[x] + ray->rayY[x]) * 64) - ((int)(ray->rayX[x] + ray->rayY[x]) * 64));
	return (getTextColor(textX, ray->iTexture, text));
}

int	getTextStart(t_ray *ray, int x)
{
	//int wheigt;
	//int	wdiff;

	//if (ray->distance[x] >= 1)
		return (0);
	//wheigt = 320 / ray->distance[x];
	//wdiff = wheigt / 64 - 240;
	//return (wdiff);
}
