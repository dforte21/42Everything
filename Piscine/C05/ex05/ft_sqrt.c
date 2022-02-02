/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:25:22 by dforte            #+#    #+#             */
/*   Updated: 2021/12/09 10:00:24 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);
int	ft_power(int n, int pwr);

int	ft_sqrt(int nb)
{
	int	i;
	int	tot;

	i = 1;
	tot = 1;
	if (nb > 2147395600)
		return (0);
	if (nb == 1)
		return (1);
	while (tot < nb)
	{
		tot = ft_power(i, 2);
		if (tot == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_power(int n, int pwr)
{
	int	tot;

	tot = 1;
	if (pwr < 0)
		return (0);
	if (pwr == 0)
		return (1);
	while (pwr > 0)
	{
		tot *= n;
		pwr--;
	}
	return (tot);
}
