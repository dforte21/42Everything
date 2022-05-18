/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:04:32 by dforte            #+#    #+#             */
/*   Updated: 2022/05/18 11:08:18 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_multipleplayer(t_map *maps)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == 'P')
				count++;
			j++;
		}
	i++;
	}
	if (count > 1)
		return (0);
	return (1);
}
