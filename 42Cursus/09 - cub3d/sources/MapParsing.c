/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:13:50 by dforte            #+#    #+#             */
/*   Updated: 2022/12/09 21:03:35 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_file(char *path, t_cub3d *data)
{
	int		fd;
	char	*row;

	fd = open(path, O_RDONLY);
	row = get_next_line(fd);
	while (row)
	{
		if ((row[0] == 'N' || row[0] == 'E' || row[0] == 'W' || row[0] == 'S') && data->height == 0)
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
	if (data->height == 0)
		ft_error("infos", data);
	data->bground = ft_strdup("./sprites/background.xpm");
	close(fd);
}

void	getpath(char *row, t_cub3d *data)
{
	if (row[0] == 'N')
		data->no = ft_strdup(&row[3]);
	if (row[0] == 'S')
		data->so = ft_strdup(&row[3]);
	if (row[0] == 'E')
		data->ea = ft_strdup(&row[3]);
	if (row[0] == 'W')
		data->we = ft_strdup(&row[3]);
}

char	**loadmap(char *path, t_cub3d *data)
{
	int		fd;
	int		i;
	char	*row;
	char	**map2;

	fd = open(path, O_RDONLY);
	map2 = ft_calloc(data->height + 1, sizeof(char *));
	row = get_next_line(fd);
	i = 0;
	while (row[0] != '1' && row[0] != ' ')
	{
		free(row);
		row = get_next_line(fd);
	}
	while (i < data->height)
	{
		map2[i] = ft_strdup(row);
		free(row);
		row = get_next_line(fd);
		i++;
	}
	if (row)
		free(row);
	data->width = (int)ft_strlen(map2[1]);
	close(fd);
	return (map2);
}

void	initplayer(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			{
				if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
					break ;
				j++;
			}
		if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
					break ;
		i++;
	}
	data->p.x = j + 0.5;
	data->p.y = i + 0.5;
	data->p.w = 0;
	data->p.a = 0;
	data->p.s = 0;
	data->p.d = 0;
	data->p.left = 0;
	data->p.right = 0;
	getangle(data);
}

void	getangle(t_cub3d *data)
{
	int	x;
	int	y;

	x = data->p.x;
	y = data->p.y;
	if (data->map[y][x] == 'N')
		data->p.pangle = 270;
	if (data->map[y][x] == 'E')
		data->p.pangle = 0;
	if (data->map[y][x] == 'S')
		data->p.pangle = 90;
	if (data->map[y][x] == 'W')
		data->p.pangle = 180;
}
