/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:03:59 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:08:51 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*));

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	a;
	int	b;

	i = 0;
	b = 0;
	while (i < length)
	{
		a = f(tab[i]);
		if (a != 0)
			b++;
		i++;
	}
	return (b);
}
