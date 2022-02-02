/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:37:55 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 18:38:04 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_delspace(struct s_dict_str *dict_struct, int size)
{
	int	row;
	int	col;
	int	i;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (dict_struct[row].wnb[col] == ' ')
		{
			i = col;
			while (dict_struct[row].wnb[i] != '\0')
			{
				dict_struct[row].wnb[i] = dict_struct[row].wnb[i + 1];
				i++;
			}
		}
		row++;
	}
}

void	rush(struct s_dict_str *dict_struct, char *str, int size, int len)
{
	char	nb[4];
	int		i;

	initialize_nb(nb);
	i = len % 3;
	if (i == 1)
		nb[2] = str[0];
	if (i == 2)
	{
		nb[1] = str[0];
		nb[2] = str[1];
	}
	if (i == 0)
	{
		nb[0] = str[0];
		nb[1] = str[1];
		nb[2] = str[2];
	}
	print_cents(dict_struct, nb[0], size);
	print_dec(dict_struct, nb[1], nb[2], size);
	p_unit(dict_struct, nb, len, size);
}

void	try_split(struct s_dict_str *dict_struct, char *str, int size)
{
	int		len;
	char	*copy;
	char	*copy2;

	len = str_len(str);
	copy = (char *) malloc (sizeof(char) * len);
	copy2 = (char *) malloc (sizeof(char) * len);
	copy2 = ft_strcpy(copy, str);
	ft_delspace(dict_struct, size);
	while (len > 0)
	{
		copy = ft_strcpy(copy, str);
		if (!(try_rush(dict_struct, copy, size, len)))
			if (!(dicterr_msg()))
				return ;
		if (len % 3 == 0)
			change1(&len, str);
		else
			change2(&len, str);
	}
	split(dict_struct, copy2, size);
	free(copy);
}

int	try_rush(struct s_dict_str *dict_struct, char *str, int size, int len)
{
	char	nb[4];
	int		i;

	initialize_nb(nb);
	i = len % 3;
	if (i == 1)
		nb[2] = str[0];
	if (i == 2)
	{
		nb[1] = str[0];
		nb[2] = str[1];
	}
	if (i == 0)
	{
		nb[0] = str[0];
		nb[1] = str[1];
		nb[2] = str[2];
	}
	if (!(check_cents(dict_struct, nb[0], size))
		|| !(check_dec(dict_struct, nb[1], nb[2], size))
		|| !(c_unit(dict_struct, nb, len, size)))
		return (0);
	return (1);
}

void	split(struct s_dict_str *dict_struct, char *str, int size)
{
	int		len;
	char	*copy;

	len = str_len(str);
	copy = (char *) malloc (sizeof(char) * len);
	while (len > 0)
	{
		copy = ft_strcpy(copy, str);
		rush(dict_struct, copy, size, len);
		if (len % 3 == 0)
		{
			len -= 3;
			str += 3;
		}
		else
		{
			str += len % 3;
			len -= len % 3;
		}
	}
	free(copy);
}
