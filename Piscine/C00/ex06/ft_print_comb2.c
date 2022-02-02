/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:00 by dforte            #+#    #+#             */
/*   Updated: 2021/11/28 11:55:12 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_check(int n[]);
void	ft_write(int n[]);

void	ft_print_comb2(void)
{
	int	n[4];
	int	i;

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	while (n[0] <= 9)
	{
		i = 3;
		while (i > 0)
		{
			if (n[i] == 10)
			{
				n[i] = 0;
				n[i - 1]++;
			}
			i--;
		}
		ft_check(n);
		n[3]++;
	}
}

void	ft_check(int n[])
{
	if (n[0] == n[2] && n[1] == n[3])
	{
		return ;
	}
	if (n[2] < n[0])
	{
		return ;
	}
	if (n[3] < n[1] && n[2] == n[0])
	{
		return ;
	}
	ft_write(n);
}

void	ft_write(int n[])
{
	char	sn[4];
	int		i;

	i = 0;
	while (i < 4)
	{
		sn[i] = n[i] + '0';
		i++;
	}
	if (n[0] == 9 && n[1] == 8 && n[2] == 9 && n[3] == 9)
	{
		write(1, &sn[0], 1);
		write(1, &sn[1], 1);
		write(1, " ", 1);
		write(1, &sn[2], 1);
		write(1, &sn[3], 1);
		return ;
	}
	write(1, &sn[0], 1);
	write(1, &sn[1], 1);
	write(1, " ", 1);
	write(1, &sn[2], 1);
	write(1, &sn[3], 1);
	write(1, ", ", 2);
}
