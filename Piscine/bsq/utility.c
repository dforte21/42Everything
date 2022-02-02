/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:12:47 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 16:13:12 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	get_frow_len(char *file)
{
	int		fp;
	int		i;
	int		byte;
	char	c[2];

	i = 1;
	fp = open(file, O_RDONLY);
	FILE_CHECK(fp);
	byte = read(fp, c, 1);
	while (c[0] != 10)
	{
		i++;
		byte = read(fp, c, 1);
	}
	close(fp);
	return (i);
}

void	print_struct(struct s_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.row)
	{
		j = 0;
		while (j < map.col)
		{
			write(1, &map.mat[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	skip_fr(int file, int len, char *c)
{
	int	i;

	i = 0;
	while (i < len)
	{
		read(file, c, 1);
		i++;
	}
}

void	put_strend(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 10)
		i++;
	str[i] = 0;
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->mat[i]);
		i++;
	}
	free(map->mat);
	free(map->f_row);
}
