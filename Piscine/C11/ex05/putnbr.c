/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:06:52 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:06:55 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	putnbr(int nb)
{
	int	digitn;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	nb = print_nop(nb);
	digitn = count_digit(nb);
	print_number(nb, digitn);
}

int	print_nop(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		return (nb);
	}
	return (nb);
}

int	count_digit(int nb)
{
	int	digit_count;

	digit_count = 0;
	while (nb != 0)
	{
		nb /= 10;
		digit_count++;
	}
	return (digit_count);
}

void	print_number(int nb, int digitn)
{
	int		i;
	int		a;
	int		b;
	char	sb;

	while (digitn != 0)
	{
		a = nb;
		i = digitn;
		while (i > 0)
		{
			b = a % 10;
			a /= 10;
			i--;
		}
		sb = b + '0';
		write(1, &sb, 1);
		digitn--;
	}
}
