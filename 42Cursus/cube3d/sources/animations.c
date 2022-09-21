/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:23:35 by dforte            #+#    #+#             */
/*   Updated: 2022/09/21 17:43:44 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ftAnimations(t_cub3D *data)
{
	static int	i = 0;

	if (i < 2000)
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.hand1.img, (1920 - SCREEN_WIDTH / 2 - 256), (1080 - SCREEN_HEIGHT / 2 - 76));
	else
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.hand2.img, (1920 - SCREEN_WIDTH / 2 - 256), (1080 - SCREEN_HEIGHT / 2 - 76));
	i++;
	if (i == 2200)
		i = 0;
}