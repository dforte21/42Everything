/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:01:08 by dforte            #+#    #+#             */
/*   Updated: 2022/04/29 19:08:17 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "ft_printf/ft_printf.h"

typedef struct s_tiles
{
	void	*wall;
	void	*wall1;
	void	*wall2;
	void	*collect;
	void	*collect1;
	void	*collect2;
	void	*floor;
	void	*floor1;
	void	*floor2;
	void	*exit;
	void	*exit1;
	void	*exit2;
	void	*player;
	void	*player1;
	void	*player2;
}             t_tiles;

typedef	struct s_map
{
	char	**map;
	int		row;
	int		col;
	void	*mlx_ptr;
	void	*mlx_winptr;
	t_tiles	*tiles;
}              t_map;

t_map	loadmap(char *file);
void	get_row_col(char *file, t_map *maps);
void	readmap(char *file, t_map *maps);
void	free_all(t_map *maps);
void	init_tiles(t_tiles *tiles, t_map maps);
void	put_image(char map, t_map *maps, int x, int y);
void	find_player(t_map *maps, int *x, int *y);
void	ft_move_right(t_map *maps);
void	ft_move_left(t_map *maps);
void	ft_move_down(t_map *maps);
void	ft_move_up(t_map *maps);
int		load_tiles(t_map *maps);
int	 movements(int keycode, t_map *maps);

#endif