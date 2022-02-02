/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:18:48 by dforte            #+#    #+#             */
/*   Updated: 2021/12/08 14:55:36 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	a;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	a = nb - 1;
	while (a > 0)
	{
		nb *= a;
		a--;
	}
	return (nb);
}
