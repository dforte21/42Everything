/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:31 by dforte            #+#    #+#             */
/*   Updated: 2022/09/19 17:41:25 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	getColor(char *str)
{
	char	**rgb;
	int		rgbint[3];

	rgb = ft_split(str, ',');
	rgbint[0] = ft_atoi(rgb[0]) * 65536;
	rgbint[1] = ft_atoi(rgb[1]) * 256;
	rgbint[2] = ft_atoi(rgb[2]);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	return (rgbint[0] + rgbint[1] + rgbint[2]);
}

float	degreeToRadians(float degree)
{
	return (degree * PI / 180);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ftExit(t_cub3D *data)
{
	freeAll(data);
	exit(0);
}

int	getTextColor(int x, int y, t_img *text)
{
	int 	color;
	char	*dst;

	dst = text->addr + (y * text->ll + x * (text->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
