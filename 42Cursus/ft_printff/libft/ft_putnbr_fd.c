/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:36:37 by dforte            #+#    #+#             */
/*   Updated: 2022/01/15 00:02:28 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_nop(int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
		return (nb);
	}
	return (nb);
}

static int	count_digit(int nb)
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

static void	print_number(int nb, int digitn, int fd)
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
		write(fd, &sb, 1);
		digitn--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	digitn;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	n = print_nop(n, fd);
	digitn = count_digit(n);
	print_number(n, digitn, fd);
}
