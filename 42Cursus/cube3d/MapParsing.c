/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapParsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:13:50 by dforte            #+#    #+#             */
/*   Updated: 2022/09/20 17:14:30 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	read_file(char *path, t_cub3D *data)
{
	int		fd;
	char	*row;

	fd = open(path, O_RDONLY);
	row = get_next_line(fd);
	while (row)
	{
		if (row[0] == 'N' || row[0] == 'E' || row[0] == 'W' || row[0] == 'S')
			getPath(row, data);
		if (row[0] == 'F')
			data->F = getColor(&row[2]);
		if (row[0] == 'C')
			data->C = getColor(&row[2]);
		if (row[0] == '1' || row[0] == ' ')
			data->height++;
		free(row);
		row = get_next_line(fd);
	}
	data->bGround = ft_strdup("./sprites/background.xpm");
	close(fd);
}

void	getPath(char *row, t_cub3D *data)
{
	if (row[0] == 'N')
		data->NO = ft_strdup(&row[3]);
	if (row[0] == 'S')
		data->SO = ft_strdup(&row[3]);
	if (row[0] == 'E')
		data->EA = ft_strdup(&row[3]);
	if (row[0] == 'W')
		data->WE = ft_strdup(&row[3]);
}

char	**loadMap(char *path, t_cub3D *data)
{
	int		fd;
	int		i;
	char	*row;
	char	**map2;

	fd = open(path, O_RDONLY);
	map2 = malloc(data->height * sizeof(char *));
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

void	initPlayer(t_cub3D *data)
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
	getAngle(data);
}

void	getAngle(t_cub3D *data)
{
	int	x;
	int	y;

	x = data->p.x;
	y = data->p.y;
	if (data->map[y][x] == 'N')
		data->p.pAngle = 270;
	if (data->map[y][x] == 'E')
		data->p.pAngle = 0;
	if (data->map[y][x] == 'S')
		data->p.pAngle = 90;
	if (data->map[y][x] == 'W')
		data->p.pAngle = 180;
}
