/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:57:32 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:04:00 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uputnnbr(char *nbr, t_flags flag, int *count, t_uint nb)
{
	t_uint	i;

	i = 1;
	*count += 1;
	print_uzero(flag, nb, count);
	putnstr(&nbr[i], (int)ft_strlen(nbr) - 1, count);
}
