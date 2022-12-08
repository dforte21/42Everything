/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:46:07 by dforte            #+#    #+#             */
/*   Updated: 2022/05/21 17:47:34 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_args(int ac, char **av, t_map *map, char c)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac > 2)
		return (ft_error("Error\nPlease insert only one argument"));
	if (!av[1] || av[1][0] == 0)
		return (ft_error("Error\nPlease give a map path"));
	if (fd == -1)
		return (ft_error("Error\nPlease give a valid map file"));
	if (read(fd, &c, 1) == 0)
		return (ft_error("Error\nEmpty map"));
	if (!check_rowcol(fd, &c))
		return (ft_error("Error\nMap is not rectangular"));
	loadmap(av[1], map);
	if (!check_mndchar(map))
	{
		free_all(map);
		return (ft_error("Error\nincorrect number of player/collectible/exit"));
	}
	if (!ver_isnotwall(map) || !hor_isnotwall(map))
	{
		free_all(map);
		return (ft_error("Error\nMap is not surrounded by walls"));
	}
	return (1);
}

int	ver_isnotwall(t_map *maps)
{
	int	j;

	j = 0;
	while (maps->map[0][j])
	{
		if (maps->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (maps->map[maps->row - 1][j])
	{
		if (maps->map[maps->row - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_rowcol(int fd, char *c)
{
	int	row;
	int	col;
	int	col2;

	row = 1;
	col = 1;
	col2 = 0;
	while (read(fd, c, 1))
	{
		if (*c != '\n')
			col += 1;
		else
		{
			row += 1;
			if (col2 != col && col2 != 0)
				return (0);
			col2 = col;
			col = 0;
		}
	}
	close(fd);
	return (1);
}

int	check_mndchar(t_map *maps)
{
	int	x;
	int	y;

	if (!check_multipleplayer(maps))
		return (0);
	if (!find_char(maps, &x, &y, 'P'))
		return (0);
	if (!find_char(maps, &x, &y, 'E'))
		return (0);
	if (!find_char(maps, &x, &y, 'C'))
		return (0);
	return (1);
}

int	hor_isnotwall(t_map *maps)
{
	int	i;

	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (maps->map[i])
	{
		if (maps->map[i][maps->col - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
