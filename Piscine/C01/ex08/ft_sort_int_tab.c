/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:43:37 by dforte            #+#    #+#             */
/*   Updated: 2021/11/28 12:02:06 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

int main(){
	int a[12] = {12, 56, 23, 254, 45, 234, 54, 10, 345, 234, 11, 545};
	ft_sort_int_tab(a, 12);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	a;
	int	sw;

	a = 0;
	while (a <= size)
	{
		i = 0;
		j = 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				sw = tab[i];
				tab[i] = tab[j];
				tab[j] = sw;
			}
			i++;
			j++;
		}
		a++;
	}
}
