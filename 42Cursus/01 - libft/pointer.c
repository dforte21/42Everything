/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:36:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:02:54 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_pointer(long int addr, int *count, char *spc)
{
	char	*paddr;
	t_flags	flag;
	t_uint	i;

	i = 1;
	init_struct(&flag);
	paddr = ft_putnbr_base(addr, "0123456789abcdef", flag.nsign);
	flag.minus = c_minus(&i, spc);
	flag.width = ft_atoi(&spc[i]) - (int)ft_strlen(paddr) - 2;
	if (flag.minus == 0)
	{
		print_widht(flag, count, ' ');
		putnstr("0x", 2, count);
		putnstr(paddr, (int)ft_strlen(paddr), count);
	}
	else
	{
		putnstr("0x", 2, count);
		putnstr(paddr, (int)ft_strlen(paddr), count);
		print_widht(flag, count, ' ');
	}
	free(paddr);
}
