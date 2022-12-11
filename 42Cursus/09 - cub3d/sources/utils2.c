/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:36:43 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:24:30 by dforte           ###   ########.fr       */
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
	if (*y > data->height - 9)
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

void	read_info(char *path, t_cub3d *data)
{
	int		fd;
	char	*row;

	fd = open(path, O_RDONLY);
	row = get_next_line(fd);
	while (row)
	{
		if ((row[0] == 'N' || row[0] == 'E' || row[0] == 'W'
				|| row[0] == 'S') && data->height == 0)
			getpath(row, data);
		else if (row[0] == 'F' && data->height == 0)
			data->f = getcolor(&row[2], data);
		else if (row[0] == 'C' && data->height == 0)
			data->c = getcolor(&row[2], data);
		else if (row[0] == '1' || row[0] == ' ' || row[0] == '0')
			data->height++;
		else if (row[0] != '\n')
		{
			free (row);
			ft_error("infos", data);
		}
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
}

void	check_wall(int wx, int wy, t_cub3d *data)
{
	if (wx == (int)(data->p.x) && ((wy - (int)(data->p.y)) == 1
			|| (wy - (int)(data->p.y)) == -1))
	{
		if (data->map[wy][wx] == 'D')
				data->map[wy][wx] = 'd';
		else if (data->map[wy][wx] == 'd')
				data->map[wy][wx] = 'D';
	}
	else if (((wx - (int)(data->p.x)) == 1 || (wx - (int)(data->p.x)) == -1)
			&& wy == (int)(data->p.y))
	{
		if (data->map[wy][wx] == 'D')
				data->map[wy][wx] = 'd';
		else if (data->map[wy][wx] == 'd')
				data->map[wy][wx] = 'D';
	}
}
