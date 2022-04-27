/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:01:08 by dforte            #+#    #+#             */
/*   Updated: 2022/04/27 16:52:44 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"

typedef	struct s_map
{
	char	**map;
	int		row;
	int		col;
	void	*mlx_ptr;
	void	*mlx_winptr;
}              t_map;

t_map	loadmap(char *file);
void	get_row_col(char *file, t_map *maps);
void	readmap(char *file, t_map *maps);

#endif