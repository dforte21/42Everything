/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:57:49 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:03:40 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_string(char *s, int *count, char *spc)
{
	t_uint	i;
	t_flags	flag;

	i = 1;
	init_struct(&flag);
	flag.minus = c_minus(&i, spc);
	flag.len = (int)ft_strlen(s);
	flag.width = ft_atoi(&spc[i]);
	while (spc[i] >= 48 && spc[i] <= 57)
		i++;
	if (spc[i] == 46)
		flag.len = ft_atoi(&spc[i + 1]);
	flag.width -= flag.len;
	if (!s)
		return (putnstr("(null)", flag.len, count));
	if (flag.minus == 0)
	{
		print_widht(flag, count, ' ');
		putnstr(s, flag.len, count);
	}
	else
	{
		putnstr(s, flag.len, count);
		print_widht(flag, count, ' ');
	}
}

int	c_minus(t_uint *i, char *spc)
{
	if (spc[*i] == 45)
	{
		*i += 1;
		return (1);
	}
	return (0);
}
