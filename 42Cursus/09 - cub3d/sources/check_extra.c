/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:28:51 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:56:12 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_spaces(char **map, int row, int col, t_cub3d *data)
{
	if (row == data->height - 1 || row == 0
		|| col == data->width - 1 || col == 0)
		ft_error("Map", data);
	if (map[row - 1][col] == ' ' || map[row - 1][col] == '\0')
		ft_error("Map", data);
	if (map[row + 1][col] == ' ' || map[row + 1][col] == '\0')
		ft_error("Map", data);
	if (map[row][col - 1] == ' ' || map[row][col - 1] == '\0')
		ft_error("Map", data);
	if (map[row][col - 1] == ' ' || map[row][col + 1] == '\0')
		ft_error("Map", data);
	if (map[row - 1][col - 1] == ' ' || map[row - 1][col - 1] == '\0')
		ft_error("Map", data);
	if (map[row + 1][col + 1] == ' ' || map[row + 1][col + 1] == '\0')
		ft_error("Map", data);
	if (map[row - 1][col + 1] == ' ' || map[row - 1][col + 1] == '\0')
		ft_error("Map", data);
	if (map[row + 1][col - 1] == ' ' || map[row + 1][col - 1] == '\0')
		ft_error("Map", data);
}

void	ft_check_map(char **map, t_cub3d *data, int row, int col)
{
	int		count;
	char	c;

	count = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			c = map[row][col];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				count++;
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				ft_check_spaces(map, row, col, data);
			else if ((c != '1' && c != ' ' && c != 'D')
				|| (int)ft_strlen(map[row]) != data->width)
				ft_error("Map", data);
			col++;
		}
		row++;
	}
	if (count != 1)
		ft_error("Map", data);
}

void	ft_check_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}
