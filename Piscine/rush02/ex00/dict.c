/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:18:50 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 18:19:54 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	count(int *size, int *max_len, char *dict)
{
	int		fd;
	char	c[1];
	int		row;
	int		len;
	int		x;

	*size = 0;
	fd = open (dict, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	x = 0;
	while (read(fd, c, 1) > 0)
	{
		if (x > len)
			len = x;
		x++;
		c_newline(c[0], &row, &x);
	}
	*size = row + 1;
	*max_len = len;
	close(fd);
	return (1);
}

int	check_dict(struct s_dict_str *dict_struct, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (dict_struct[row].nb[col] != '\0')
		{
			if (dict_struct[row].nb[col] < '0'
				|| dict_struct[row].nb[col] > '9')
			{
				dicterr_msg();
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

void	c_newline(char c, int *row, int *x)
{
	if (c == '\n')
	{
		*row += 1;
		*x = 0;
	}
}

int	check_zero(char *str, char *str2, int ac)
{
	if ((str[0] == '0') || ((ac == 3) && (str2[0] == '0')))
	{
		if ((str[1] == 0) || ((ac == 3) && (str2[1] == 0)))
		{
			ft_putstr("zero");
			return (1);
		}
		else
		{
			err_msg();
			return (0);
		}
	}
	return (1);
}
