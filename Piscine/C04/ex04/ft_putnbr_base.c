/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:32:08 by dforte            #+#    #+#             */
/*   Updated: 2021/12/02 17:34:18 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	ft_base_conv(int nbr, char *base, int i, int size);
int		check_size(char *base);
int		get_div_number(int nbr, int size);

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	i;

	size = check_size(&base[0]);
	if (size == 0)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	i = get_div_number(nbr, size);
	if (i == 0)
	{
		write (1, "0", 1);
		return ;
	}
	ft_base_conv(nbr, &base[0], i, size);
}

int	check_size(char *base)
{
	int	size;
	int	i;
	int	flag;

	size = 0;
	flag = 0;
	while (base[size] != 0)
	{
		i = size + 1;
		while (base[i] != 0)
		{
			if (base[size] == base[i])
				flag = 1;
			i++;
		}
		if (base[size] == 43 || base[size] == 45)
			flag = 1;
		size++;
	}
	if (size <= 1 || flag == 1)
		return (0);
	return (size);
}

int	get_div_number(int nbr, int size)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

void	ft_base_conv(int nbr, char *base, int i, int size)
{
	int	divv;
	int	mod;
	int	j;

	while (i > 0)
	{
		j = i;
		divv = nbr;
		mod = 0;
		while (j > 0)
		{
			mod = divv % size;
			divv /= size;
			j--;
		}
		if (mod < 0)
			mod *= -1;
		write (1, &base[mod], 1);
		i--;
	}
}
