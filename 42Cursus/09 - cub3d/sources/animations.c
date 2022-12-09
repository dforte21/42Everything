/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:23:35 by dforte            #+#    #+#             */
/*   Updated: 2022/12/09 19:28:45 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ftanimations(t_cub3d *data)
{
	hand(data, 384, &data->imgs.hand);
	face(data, 256, &data->imgs.face);
}

void	hand(t_cub3d *data, int size, t_img *text)
{
	static int	i = 0;
	static int	texture = 0;
	int			x;
	int			y;
	int			color;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			color = gettextcolor(x, y + (size * texture), text);
			if (color >= 0)
				my_mlx_pixel_put(&data->imgs.win, (screen_width - size) + x, (screen_height - size) + y, color);
			x++;
		}
		y++;
	}
	i++;
	if (i % 30 == 0)
		texture++;
	if (texture == 2)
		texture = 0;
}

void	face(t_cub3d *data, int size, t_img *text)
{
	static int	i = 0;
	static int	texture = 0;
	int			x;
	int			y;
	int			color;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			color = gettextcolor(x, y + (size * texture), text);
			if (color >= 0)
				my_mlx_pixel_put(&data->imgs.win, x, (screen_height - size) + y, color);
			x++;
		}
		y++;
	}
	i++;
	if (i % 30 == 0)
		texture++;
	if (texture == 7)
		texture = 0;
}
