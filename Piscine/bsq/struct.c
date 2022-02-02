/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:15:39 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 16:16:19 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	init_struct(struct s_map *map)
{
	int	i;

	i = 0;
	map->row = 0;
	map->col = 0;
	map->solutions[0] = 0;
	map->solutions[1] = 0;
	while (i < 4)
	{
		map->signs[i] = 0;
		i++;
	}
}

int	load_struct(struct s_map *map, char *filename)
{
	int	fp;
	int	len;

	len = get_frow_len(filename);
	if (len == 0)
		return (0);
	fp = open(filename, O_RDONLY);
	FILE_CHECK(fp);
	if (!(get_frow(fp, map, len)))
		return (0);
	get_rc(map, fp);
	close(fp);
	map->mat = malloc(sizeof(char *) * map->row);
	MALLOC_CHECK(map->mat);
	if (!(get_mat(map, filename, len)))
		return (0);
	return (1);
}

int	get_frow(int file, struct s_map *map, int len)
{
	int		i;
	char	c[2];

	i = 0;
	map->f_row = malloc(sizeof(char) * len);
	MALLOC_CHECK(map->f_row);
	while (i < len - 1)
	{
		read(file, c, 1);
		map->f_row[i] = c[0];
		i++;
	}
	i = 2;
	while (i >= 0)
	{
		map->signs[i] = map->f_row[len - 2];
		i--;
		len--;
	}
	read(file, c, 1);
	return (1);
}

void	get_rc(struct s_map *map, int file)
{
	char	c[2];
	int		byte;
	int		flag;

	byte = read(file, c, 1);
	flag = 0;
	while (byte != 0)
	{
		if (flag == 0)
			map->col++;
		if (c[0] == 10)
		{
			flag = 1;
			map->row++;
		}
		byte = read(file, c, 1);
	}
}

int	get_mat(struct s_map *map, char *filename, int len)
{
	int		fp;
	int		i;
	int		j;
	char	c[2];

	fp = open(filename, O_RDONLY);
	i = 0;
	skip_fr(fp, len, c);
	while (i < map->row)
	{
		map->mat[i] = malloc(sizeof(char) * map->col);
		MALLOC_CHECK(map->mat[i]);
		j = 0;
		while (j < map->col - 1)
		{
			read(fp, c, 1);
			map->mat[i][j] = c[0];
			j++;
		}
		map->mat[i][j] = 0;
		read(fp, c, 1);
		i++;
	}
	close(fp);
	return (1);
}
