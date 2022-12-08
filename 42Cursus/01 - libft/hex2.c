/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:08:02 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:03:53 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_hnumber(int nb, char *base, t_flags flag)
{
	char		*nbr;
	long int	n;

	n = 0x100000000;
	if (flag.nsign == -1)
	{
		n += nb;
		nbr = ft_putnbr_base(n, base, 0);
	}
	else
		nbr = ft_putnbr_base(nb, base, 0);
	return (nbr);
}

void	init_ch(char *ch, char *base)
{
	if (base[15] == 'F')
	{
		ch[0] = '0';
		ch[1] = 'X';
		ch[2] = 0;
	}
	else
	{
		ch[0] = '0';
		ch[1] = 'x';
		ch[2] = 0;
	}
}
