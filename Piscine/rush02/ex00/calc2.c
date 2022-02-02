/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:13:43 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 18:16:44 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	f_n(struct s_dict_str *dict_struct, char *str, int size, int max_size)
{
	int	i;
	int	row;

	row = 0;
	while (dict_struct[row].size != size && row < max_size)
		row++;
	while (dict_struct[row].size == size)
	{
		i = 0;
		if (dict_struct[row].nb[i] == str[i])
		{
			while (str[i] != '\0' && str[i] == dict_struct[row].nb[i])
				i++;
			if (i == size)
			{
				ft_putstr(dict_struct[row].wnb);
				return (1);
			}
		}
		row++;
	}
	return (0);
}

int	c_nu(struct s_dict_str *dict_struct, char *str, int size, int max_size)
{
	int	i;
	int	row;

	row = 0;
	while (dict_struct[row].size != size && row < max_size)
		row++;
	while (dict_struct[row].size == size)
	{
		i = 0;
		if (dict_struct[row].nb[i] == str[i])
		{
			while (str[i] != '\0' && str[i] == dict_struct[row].nb[i])
				i++;
			if (i == size)
			{
				return (1);
			}
		}
		row++;
	}
	return (0);
}

int	check_cents(struct s_dict_str *dict_struct, char n, int max_size)
{
	char	nb[1];

	if (n == '0')
		return (1);
	nb[0] = n;
	if (!(c_nu(dict_struct, nb, 1, max_size)))
		return (0);
	if (!(c_nu(dict_struct, "100", 3, max_size)))
		return (0);
	return (1);
}

int	check_dec(struct s_dict_str *dict_struct, char n, char m, int max_size)
{
	char	nb[2];

	nb[0] = n;
	if (n == '1')
	{
		nb[1] = m;
		if (!(c_nu(dict_struct, nb, 2, max_size)))
			return (0);
	}
	else
	{
		if (n != '0')
		{
			nb[1] = '0';
			if (!(c_nu(dict_struct, nb, 2, max_size)))
				return (0);
		}
		if (m != '0')
		{
			nb[0] = m;
			nb[1] = 0;
			return (c_nu(dict_struct, nb, 1, max_size));
		}
	}
	return (1);
}

int	c_unit(struct s_dict_str *dict_struct, char *n, int size, int max_size)
{
	char	*unit;
	int		i;

	i = 1;
	if (size % 3 == 0)
		size -= 2;
	if (size % 3 == 2)
		size -= 1;
	if ((n[0] == '0' && n[1] == '0') && n[2] == '0')
		return (1);
	unit = malloc(sizeof(char) * (size));
	unit[0] = '1';
	while (i < size)
	{
		unit[i] = '0';
		i++;
	}
	if (size > 3)
	{
		if (!(c_nu(dict_struct, unit, size, max_size)))
			return (0);
	}
	free(unit);
	return (1);
}
