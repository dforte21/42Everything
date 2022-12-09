/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:36:43 by dforte            #+#    #+#             */
/*   Updated: 2022/12/09 19:41:01 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	ft_error(char *str, t_cub3d *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write (2, " error\n", 7);
	freeall(data);
	exit(1);
}
