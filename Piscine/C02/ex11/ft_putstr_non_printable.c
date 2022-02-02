/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:23:56 by dforte            #+#    #+#             */
/*   Updated: 2021/12/02 11:42:48 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	ft_print_np(char str);
void	print_hex(int nb, char *base);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			ft_print_np(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

void	ft_print_np(char str)
{
	int	nb;

	nb = (int) str;
	write(1, "\\", 1);
	print_hex(nb, "0123456789abcdef");
}

void	print_hex(int nb, char *base)
{
	int		a;
	int		b;

	a = nb;
	b = 0;
	while (a >= 16)
	{
		b = a % 16;
		a /= 16;
	}
	write(1, &base[b], 1);
	write(1, &base[a], 1);
}
