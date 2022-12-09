/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:31 by dforte            #+#    #+#             */
/*   Updated: 2022/12/09 20:42:17 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	getcolor(char *str, t_cub3d *data)
{
	char	**matrix;
	int		color;
	int		i;

	ft_check_color(str, data);
	matrix = ft_split(str, ',');
	color = 0;
	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_atoi(matrix[i]) < 0 || ft_atoi(matrix[i]) > 255)
			ft_error("Color", data);
		else if (i == 0)
			color += ft_atoi(matrix[i]) * 65536;
		else if (i == 1)
			color += ft_atoi(matrix[i]) * 256;
		else
			color += ft_atoi(matrix[i]);
		i++;
	}
	ft_free_matrix((void **) matrix);
	if (i != 3 || matrix[2][0] == '\n')
		ft_error("Color", data);
	return (color);
}

double	degreetoradians(double degree)
{
	return (degree * pi / 180);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ftexit(t_cub3d *data)
{
	freeall(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	gettextcolor(int x, int y, t_img *text)
{
	int 	color;
	char	*dst;

	dst = text->addr + (y * text->ll + x * (text->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
