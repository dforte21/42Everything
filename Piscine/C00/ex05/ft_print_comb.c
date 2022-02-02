/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_comb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:27:01 by dforte            #+#    #+#             */
/*   Updated: 2021/11/28 11:55:08 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	ft_check(int n[]);
void	ft_write(int n[]);

void	ft_print_comb(void)
{
	int		n[3];

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	while (n[0] <= 7)
	{
		if (n[2] == 10)
		{
			n[2] = 0;
			n[1]++;
		}
		if (n[1] == 9)
		{
			n[1] = 0;
			n[0]++;
		}
		ft_check(n);
		n[2]++;
	}
}

void	ft_check(int n[])
{
	if (n[2] <= n[1] || n[1] <= n[0])
	{
		return ;
	}
	ft_write(n);
}

void	ft_write(int n[])
{
	char	sn[3];

	sn[0] = n[0] + '0';
	sn[1] = n[1] + '0';
	sn[2] = n[2] + '0';
	if (n[0] == 7 && n[1] == 8 && n[2] == 9)
	{
		write(1, &sn, 3);
	}
	else
	{
		write(1, &sn, 3);
		write(1, ", ", 2);
	}
}
