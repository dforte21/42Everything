/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:45:39 by dforte            #+#    #+#             */
/*   Updated: 2022/06/24 18:40:58 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_free_struct(t_cub3D *data)
{
	free(data->NO);
	free(data->SO);
	free(data->WE);
	free(data->EA);
	free(data->F);
	free(data->C);
	ft_free_matrix((void **)data->map);
}
