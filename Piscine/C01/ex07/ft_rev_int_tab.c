/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:29:24 by dforte            #+#    #+#             */
/*   Updated: 2021/11/27 18:42:41 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	sw;

	i = 0;
	j = size - 1;
	while (i <= j)
	{
		sw = tab[i];
		tab[i] = tab[j];
		tab[j] = sw;
		i++;
		j--;
	}
}
