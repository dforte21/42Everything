/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:15:14 by dforte            #+#    #+#             */
/*   Updated: 2022/04/27 16:31:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	loadmap(char *file)
{
	t_map	maps;
	int		i;
	
	maps.row = 0;
	maps.col = 0;
	i = 0;
	get_row_col(file, &maps);
	maps.map = ft_calloc(maps.row + 1, sizeof(char *));
	while (i < maps.row)
	{
		maps.map[i] = ft_calloc(maps.col + 1, 1);
		i++;
	}
	readmap(file, &maps);
	return (maps);
}

void	get_row_col(char *file, t_map *maps)
{
	int		fd;
	int 	buf;
	char	c;

	fd = open(file, O_RDONLY);
	buf = read(fd, &c, 1);
	while (buf != 0)
	{
		if (c != '\n')
			maps->col += 1;
		else
			maps->row += 1;
		buf = read(fd, &c, 1);
	}
	maps->col /= maps->row;
	close(fd);
}

void	readmap(char *file, t_map *maps)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(file, O_RDONLY);
	while (maps->map[i])
	{
		read(fd, maps->map[i], maps->col);
		read(fd, &c, 1);
		i++;
	}
	close(fd);
}
