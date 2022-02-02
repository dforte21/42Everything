/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:09:08 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 16:09:21 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	get_solutions(struct s_map *map, int i, int j, int *maxsize)
{
	int	size;
	int	o_cordinate[2];
	int	v_cordinate[2];

	size = 1;
	o_cordinate[0] = i;
	o_cordinate[1] = j;
	v_cordinate[0] = i + 1;
	v_cordinate[1] = j + 1;
	start_calc(*map, &size, o_cordinate, v_cordinate);
	if (size > *maxsize)
	{
		*maxsize = size;
		if (j < map->solutions[1] || map->solutions[1] == 0)
		{
		map->solutions[0] = i;
		map->solutions[1] = j;
		}
	}
}

void	start_calc(struct s_map map, int *size, int o_cord[], int *v_cord)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = v_cord[0];
	j = v_cord[1];
	if (i == map.row || j == map.col - 1)
		return ;
	flag = check_row(map, i, j, o_cord);
	if (flag == 0)
		flag = check_col(map, i, j, o_cord);
	if (flag == 1)
		return ;
	else
	{
		*size += 1;
		v_cord[0]++;
		v_cord[1]++;
		start_calc(map, size, o_cord, v_cord);
	}
}

int	check_row(struct s_map map, int i, int j, int o_cord[])
{
	while (i >= o_cord[0])
	{
		if (map.mat[i][j] == map.signs[1])
			return (1);
		i--;
	}
	return (0);
}

int	check_col(struct s_map map, int i, int j, int o_cord[])
{
	while (j >= o_cord[1])
	{
		if (map.mat[i][j] == map.signs[1])
			return (1);
		j--;
	}
	return (0);
}
