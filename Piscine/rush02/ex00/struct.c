/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:40:42 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 18:40:48 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	initialize_struct(struct s_dict_str *dict_struct, int maxlen, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dict_struct[i].size = 0;
		dict_struct[i].nb = malloc(sizeof(char) * maxlen);
		dict_struct[i].wnb = malloc(sizeof(char) * maxlen);
		i++;
	}
}

void	load_dict(struct s_dict_str *dict_struct, int fp)
{
	int		i;
	int		j;
	int		flag;
	int		byte;
	char	c[1];

	flag = 0;
	j = 0;
	i = 0;
	byte = read(fp, c, 1);
	while (byte != 0)
	{
		newline(c[0], &flag, &j, &i);
		double_point(c[0], &flag, &j);
		if (flag == 0 && (c[0] != 10 && c[0] != 58 && c[0] != 32))
		{
			dict_struct[i].size++;
			j = str_cpy(dict_struct[i].nb, c, j);
		}
		if (flag == 1 && (c[0] != 10 && c[0] != 58))
			j = str_cpy(dict_struct[i].wnb, c, j);
		byte = read(fp, c, 1);
	}
}

void	newline(char c, int *flag, int *j, int *i)
{
	if (c == 10)
	{
		*flag = 0;
		*j = 0;
		*i += 1;
	}
}

void	double_point(char c, int *flag, int *j)
{
	if (c == 58)
	{
		*flag = 1;
		*j = 0;
	}
}

int	str_cpy(char *c1, char *c2, int j)
{
	c1[j] = c2[0];
	j++;
	return (j);
}
