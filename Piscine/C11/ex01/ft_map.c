/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:59:20 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:08:14 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*a;

	i = 0;
	a = malloc(sizeof(int) * length);
	while (i < length)
	{
		a[i] = f(tab[i]);
		i++;
	}
	return (a);
}
