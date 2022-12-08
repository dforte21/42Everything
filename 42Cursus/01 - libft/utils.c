/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:13:04 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:03:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkch(char c)
{
	if (c == 99)
		return (1);
	if (c == 115)
		return (2);
	if (c == 112)
		return (3);
	if (c == 100)
		return (4);
	if (c == 105)
		return (5);
	if (c == 117)
		return (6);
	if (c == 120)
		return (7);
	if (c == 88)
		return (8);
	if (c == 37)
		return (9);
	return (0);
}

void	putnstr(char *s, int len, int *count)
{
	int	i;

	i = 0;
	while (i < len && s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
		*count += 1;
	}
}

void	print_widht(t_flags flag, int *count, char ch)
{
	while (flag.width > 0)
	{
		write(1, &ch, 1);
		flag.width--;
		*count += 1;
	}
}

void	init_struct(t_flags	*strct)
{
	strct->hashtag = 0;
	strct->len = 0;
	strct->minus = 0;
	strct->plus = 0;
	strct->space = 0;
	strct->width = 0;
	strct->zero = 0;
	strct->precision = 0;
	strct->nsign = 0;
	strct->sep = ' ';
}

int	nlen(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (10);
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
