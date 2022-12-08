/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:54:42 by dforte            #+#    #+#             */
/*   Updated: 2022/01/22 19:03:05 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnnbr(char *nbr, t_flags flag, int *count, int nb)
{
	t_uint	i;

	i = 1;
	*count += 1;
	if (flag.minus == 1 && flag.nsign == -1)
		write (1, "-", 1);
	print_zero(flag, nb, count);
	putnstr(&nbr[i], (int)ft_strlen(nbr) - 1, count);
}
