/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:45:56 by dforte            #+#    #+#             */
/*   Updated: 2022/05/16 17:22:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int movements(int keycode, t_map *maps)
{
	if (keycode == 53)
		ft_destroy(maps);
	if (keycode == 13)
		ft_move_up(maps);
	if (keycode == 1)
		ft_move_down(maps);
	if (keycode == 0)
		ft_move_left(maps);
	if (keycode == 2)
		ft_move_right(maps);
	return (0);
}

void	ft_move_up(t_map *maps)
{
	int	x;
	int	y;

	find_player(maps, &x, &y);
	if (maps->map[x - 1][y] == 'X')
		ft_lose(maps);
	if (maps->map[x - 1][y] == 'e')
		ft_destroy(maps);
	if (maps->map[x - 1][y] == '1' || maps->map[x - 1][y] == 'E')
		return ;
	if (maps->map[x - 1][y] == 'C')
		maps->collectibles--;
	maps->map[x - 1][y] = 'P';
	maps->map[x][y] = '0';\
	maps->moves++;
	ft_printf("MOVES: %d\n", maps->moves);
}

void	ft_move_down(t_map *maps)
{
	int	x;
	int	y;

	find_player(maps, &x, &y);
	if (maps->map[x + 1][y] == 'X')
		ft_lose(maps);
	if (maps->map[x + 1][y] == 'e')
		ft_destroy(maps);
	if (maps->map[x + 1][y] == '1' || maps->map[x + 1][y] == 'E')
		return ;
	if (maps->map[x + 1][y] == 'C')
		maps->collectibles--;
	maps->map[x + 1][y] = 'P';
	maps->map[x][y] = '0';
	maps->moves++;
	ft_printf("MOVES: %d\n", maps->moves);
}

void	ft_move_left(t_map *maps)
{
	int	x;
	int	y;

	find_player(maps, &x, &y);
	if (maps->map[x][y - 1] == 'X')
		ft_lose(maps);
	if (maps->map[x][y - 1] == 'e')
		ft_destroy(maps);
	if (maps->map[x][y - 1] == '1' || maps->map[x][y - 1] == 'E')
		return ;
	if (maps->map[x][y - 1] == 'C')
		maps->collectibles--;
	maps->map[x][y - 1] = 'P';
	maps->map[x][y] = '0';
	maps->moves++;
	ft_printf("MOVES: %d\n", maps->moves);
}

void	ft_move_right(t_map *maps)
{
	int	x;
	int	y;

	find_player(maps, &x, &y);
	if (maps->map[x][y + 1] == 'X')
		ft_lose(maps);
	if (maps->map[x][y + 1] == 'e')
		ft_destroy(maps);
	if (maps->map[x][y + 1] == '1' || maps->map[x][y + 1] == 'E')
		return ;
	if (maps->map[x][y + 1] == 'C')
		maps->collectibles--;
	maps->map[x][y + 1] = 'P';
	maps->map[x][y] = '0';
	maps->moves++;
	ft_printf("MOVES: %d\n", maps->moves);
}
