/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:31:16 by dforte            #+#    #+#             */
/*   Updated: 2022/06/25 11:47:39 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_get_row(char *str, int flag)
{
	int	i;
	char *tmp;

	tmp = &str[flag];
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (flag != 0)
	{
		tmp[i] = '\0';
		return (str);
	}
	while (tmp[i] != '1')
		i--;
	tmp[i + 1] = '\0';
	return (tmp);
}

void	ft_get_info(int fd, char *str, t_cub3D *data)
{
	str = get_next_line(fd);
	data->NO = ft_get_row(str, 3);
	str = get_next_line(fd);
	data->SO = ft_get_row(str, 3);
	str = get_next_line(fd);
	data->WE = ft_get_row(str, 3);
	str = get_next_line(fd);
	data->EA = ft_get_row(str, 3);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	data->F = ft_get_row(str, 2);
	str = get_next_line(fd);
	data->C = ft_get_row(str, 2);
	str = get_next_line(fd);
	free(str);
}

int		ft_get_height(char *file_name, char *str)
{
	int		height;
	int		fd;

	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	height = 0;
	while (str != NULL)
	{
		height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (height - 8);
}

void	ft_read_file(char *file_name, t_cub3D *data)
{
	int		fd;
	int		row;
	char	*str;

	fd = open(file_name, O_RDONLY);
	str = NULL;
	ft_get_info(fd, str, data);
	data->height = ft_get_height(file_name, str);
	data->map = (char **) malloc (sizeof(char *) * (data->height + 1));
	data->map[data->height] = NULL;
	row = 0;
	while (row < data->height)
	{
		str = get_next_line(fd);
		data->map[row] = ft_get_row(str, 0);
		row++;
	}
	ft_get_width(data);
	close(fd);
}

void ft_get_width(t_cub3D *data)
{
	data->width = 0;
	while (data->map[0][data->width])
			data->width++;
}
