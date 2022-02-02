/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:10:44 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 18:10:46 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	initialize_nb(char *str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		str[i] = '0';
		i++;
	}
}

void	print_cents(struct s_dict_str *dict_struct, char n, int max_size)
{
	char	nb[1];

	if (n == '0')
		return ;
	nb[0] = n;
	f_n(dict_struct, nb, 1, max_size);
	ft_putstr(" ");
	f_n(dict_struct, "100", 3, max_size);
	ft_putstr(" ");
}

void	print_dec(struct s_dict_str *dict_struct, char n, char m, int max_size)
{
	char	nb[2];

	nb[0] = n;
	if (n == '1')
	{
		nb[1] = m;
		f_n(dict_struct, nb, 2, max_size);
		ft_putstr(" ");
	}
	else
	{
		if (n != '0')
		{
			nb[1] = '0';
			f_n(dict_struct, nb, 2, max_size);
			ft_putstr(" ");
		}
		if (m != '0')
		{
			nb[0] = m;
			nb[1] = 0;
			f_n(dict_struct, nb, 1, max_size);
			ft_putstr(" ");
		}
	}
}

void	p_unit(struct s_dict_str *dict_struct, char *n, int size, int max_size)
{
	char	*unit;
	int		i;

	i = 1;
	if (size % 3 == 0)
		size -= 2;
	if (size % 3 == 2)
		size -= 1;
	if ((n[0] == '0' && n[1] == '0') && n[2] == '0')
		return ;
	unit = malloc(sizeof(char) * (size));
	unit[0] = '1';
	while (i < size)
	{
		unit[i] = '0';
		i++;
	}
	if (size > 3)
	{
		f_n(dict_struct, unit, size, max_size);
		ft_putstr(" ");
	}
	free(unit);
}
