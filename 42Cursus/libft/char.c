/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:27:34 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:01:43 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_char(int c, int *count, char *spc)
{
	t_uint	i;
	char	ch;
	t_flags	flags;

	i = 1;
	init_struct(&flags);
	ch = (char)c;
	flags.minus = c_minus(&i, spc);
	flags.width = ft_atoi(&spc[i]) - 1;
	if (flags.minus == 0)
	{
		print_widht(flags, count, ' ');
		write(1, &ch, 1);
		*count += 1;
	}
	else
	{
		write(1, &ch, 1);
		print_widht(flags, count, ' ');
		*count += 1;
	}
}
