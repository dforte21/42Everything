/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:44:12 by dforte            #+#    #+#             */
/*   Updated: 2021/11/28 12:03:27 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_check_ten(int *nb, int n);
int		ft_check_print(int nb[], int n);
void	ft_write(int nb[], int n, int *flag2);

void	ft_print_combn(int n)
{
	int	nb[9];
	int	i;
	int	flag;
	int	flag2;

	flag = 0;
	flag2 = 0;
	i = 0;
	while (i < n)
	{
		nb[i] = 0;
		i++;
	}
	while (nb[0] < (11 - n))
	{
		ft_check_ten(nb, n);
		flag = ft_check_print(nb, n);
		if (flag == 0)
		{
			ft_write(nb, n, &flag2);
		}
		nb[n - 1]++;
	}
}

void	ft_check_ten(int *nb, int n)
{
	int	i;

	i = n - 1;
	while (i > 0)
	{
		if (nb[i] == 10)
		{
			nb[i] = 0;
			nb[i - 1]++;
		}
		i--;
	}
}

int	ft_check_print(int nb[], int n)
{
	int	a;
	int	b;

	a = n - 1;
	while (a >= 0)
	{
		b = a - 1;
		while (b >= 0)
		{
			if (nb[a] <= nb[b])
			{
				return (1);
			}
			b--;
		}
		a--;
	}
	return (0);
}

void	ft_write(int nb[], int n, int *flag2)
{
	char	sn;
	int		i;

	i = 0;
	if (*flag2 != 0)
	{
		write(1, ", ", 2);
	}
	while (i < n)
	{
		sn = nb[i] + '0';
		write(1, &sn, 1);
		i++;
		*flag2 = 1;
	}
}
