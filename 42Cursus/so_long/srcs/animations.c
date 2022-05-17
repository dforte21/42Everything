/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:43:22 by dforte            #+#    #+#             */
/*   Updated: 2022/05/17 19:43:41 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_tiles(t_map *maps)
{
	if (maps->tiles.collect == maps->tiles.collect1)
		maps->tiles.collect = maps->tiles.collect2;
	else
		maps->tiles.collect = maps->tiles.collect1;
	if (maps->tiles.player == maps->tiles.player1)
		maps->tiles.player = maps->tiles.player2;
	else
		maps->tiles.player = maps->tiles.player1;
	if (maps->tiles.enemy == maps->tiles.enemy1)
		maps->tiles.enemy = maps->tiles.enemy2;
	else
		maps->tiles.enemy = maps->tiles.enemy1;
}
