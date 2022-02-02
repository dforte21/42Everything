/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:59:40 by dforte            #+#    #+#             */
/*   Updated: 2021/12/02 11:41:14 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int size);
void	ft_get_hex(unsigned long long nb);
void	ft_print_addr(unsigned long long addr);
void	ft_print_data(unsigned char *c, int size);
void	*ft_print_memory(void *addr, unsigned int size);

void	ft_putchar(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_get_hex(unsigned long long nb)
{
	char	base[17];
	int		i;
	char	si;

	i = 0;
	si = 'a';
	while (i < 10)
	{
		base[i] = i + '0';
		i++;
	}
	while (si <= 'f')
	{
		base[i] = si;
		i++;
		si++;
	}
	if (nb >= 16)
	{
		ft_get_hex(nb / 16);
		ft_get_hex(nb % 16);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_print_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			ft_putchar('0', 1);
		tmp /= 16;
	}
	ft_get_hex(addr);
}

void	ft_print_data(unsigned char *c, int size)
{
	int		i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ', 1);
		if (i < size)
		{
			if (((unsigned long long)*(c + i)) < 16)
				write(1, "0", 1);
			ft_get_hex((unsigned long long)*(c + i));
		}
		else if (i != 16)
			ft_putchar(' ', 2);
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 127)
			ft_putchar('.', 1);
		else
			ft_putchar(*(c + i), 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned int	sendsize;

	i = 0;
	c = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			sendsize = 16;
		else
			sendsize = size % 16;
		ft_print_addr((unsigned long long)c + (i * 16));
		ft_putchar(':', 1);
		ft_print_data(c + (i * 16), sendsize);
		ft_putchar('\n', 1);
		i++;
	}
	return (addr);
}
