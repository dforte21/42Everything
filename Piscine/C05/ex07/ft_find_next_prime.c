/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:26:55 by dforte            #+#    #+#             */
/*   Updated: 2021/12/08 14:53:05 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);
int	check_prime(int nb);

int	ft_find_next_prime(int nb)
{
	int	flag;

	flag = 0;
	if (nb <= 2)
		return (2);
	if (nb == 2147483647)
		return (nb);
	if (nb > 2147483629)
		return (2147483647);
	while (flag == 0)
	{
		if (check_prime(nb))
			flag = 1;
		else
			nb++;
	}
	return (nb);
}

int	check_prime(int nb)
{
	int	i;
	int	flag;

	i = nb / 2;
	flag = 0;
	if ((nb % 2) == 0)
		return (0);
	while (i > 0)
	{
		if ((nb % i) == 0)
			flag++;
		i--;
		if (flag == 1 && i > 1)
			return (0);
	}
	if (flag == 1)
		return (1);
	return (0);
}
