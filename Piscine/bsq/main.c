/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:10:55 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 16:11:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	int		i;
	int		byte;
	char	buffer[100];

	i = 1;
	if (ac == 1)
	{
		byte = read(STDIN_FILENO, buffer, 100);
		buffer[byte - 1] = 0;
		start_program(buffer);
	}
	while (i < ac)
	{
		start_program(av[i]);
		i++;
	}
	return (0);
}

void	process_start(struct s_map map)
{
	int	i;
	int	j;
	int	maxsize;

	i = 0;
	maxsize = 0;
	while (i < map.row - 1)
	{
		j = 0;
		while (j < map.col - 2)
		{
			if (map.mat[i][j] == map.signs[0])
				get_solutions(&map, i, j, &maxsize);
			j++;
		}
		i++;
	}
	print_solution(map, maxsize);
}

void	print_solution(t_map map, int maxsize)
{
	int	i;
	int	j;

	i = map.solutions[0];
	while (i < (map.solutions[0] + maxsize))
	{
		j = map.solutions[1];
		while (j < (map.solutions[1] + maxsize))
		{
			map.mat[i][j] = map.signs[2];
			j++;
		}
		i++;
	}
	print_struct(map);
}

void	start_program(char *filename)
{
	t_map	map;

	if (!(check_map(filename)))
		return ;
	init_struct(&map);
	if (!(load_struct(&map, filename)))
		return ;
	process_start(map);
	free_all(&map);
}
