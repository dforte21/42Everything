/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:03:25 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 16:13:24 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_map(char filen[])
{
	int		fp;
	char	sign[4];

	fp = open(filen, O_RDONLY);
	FILE_CHECK(fp);
	if (!(check_fr(fp, sign)))
		MAP_ERROR
	if (!(check_mat(fp, sign)))
		MAP_ERROR
	return (1);
}

int	check_fr(int fp, char *sign)
{
	int		byte;
	int		i;
	char	c[2];
	char	str[100];

	i = 1;
	byte = read(fp, c, 1);
	str[0] = c[0];
	if (byte == 0)
		return (0);
	while (c[0] != 10)
	{
		byte = read(fp, c, 1);
		str[i] = c[0];
		i++;
	}
	if (!(check_printchar(str, &i, sign)))
		return (0);
	if (!(check_num(str, &i)))
		return (0);
	return (1);
}

int	check_printchar(char *str, int *i, char *sign)
{
	int	j;

	j = 2;
	*i -= 2;
	while (j >= 0)
	{
		if (str[*i] < 32 || str[*i] > 126)
			return (0);
		sign[j] = str[*i];
		*i -= 1;
		j--;
	}
	if (sign[0] == sign[1])
		return (0);
	if (sign[0] == sign[2])
		return (0);
	if (sign[1] == sign[2])
		return (0);
	return (1);
}

int	check_num(char *str, int *i)
{
	while (*i >= 0)
	{
		if (str[*i] < 48 || str[*i] > 57)
			return (0);
		*i -= 1;
	}
	return (1);
}

int	check_mat(int file, char *sign)
{
	char	c[2];
	int		byte;
	int		col;
	int		row;

	col = 0;
	row = 0;
	byte = read(file, c, 1);
	if (byte == 0)
		return (0);
	while (byte != 0)
	{
		col++;
		if (c[0] != sign[0] && c[0] != sign[1] && c[0] != 10)
			return (0);
		if (c[0] == 10)
			row++;
		byte = read(file, c, 1);
	}
	if (col % row != 0)
		return (0);
	return (1);
}
