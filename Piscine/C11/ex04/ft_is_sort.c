/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:04:26 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:09:10 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	a;
	int	flag;

	i = 0;
	flag = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			a = f(tab[i], tab[j]);
			if (a > 0 && flag == 0)
				flag = 1;
			if (a < 0 && flag == 0)
				flag = 2;
			if ((a < 0 && flag == 1) || (a > 0 && flag == 2))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
