/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:45:15 by dforte            #+#    #+#             */
/*   Updated: 2021/12/15 23:45:16 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	stdin_f(char **av)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno != 0)
		{
			ft_putstr(basename(av[0]));
			ft_putstr(": stdin: ");
			ft_putstr(strerror(errno));
			ft_putchar('\n');
			return (0);
		}
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_error(char *file, char *fname)
{
	char	*error;
	int		i;

	i = 0;
	while (file[i] != 0)
	{
		write(1, &file[i], 1);
		i++;
	}
	write(1, ": ", 2);
	i = 0;
	while (fname[i] != 0)
	{
		write(1, &fname[i], 1);
		i++;
	}
	write(1, ": ", 2);
	error = strerror(errno);
	i = 0;
	while (error[i] != 0)
	{
		write(1, &error[i], 1);
		i++;
	}
}

void	printfh(char *filename)
{
	write(1, "==> ", 4);
	ft_putstr(filename);
	write(1, " <==", 4);
}
