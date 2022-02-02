/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:19:15 by dforte            #+#    #+#             */
/*   Updated: 2021/12/15 17:19:42 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	int	i;
	int	fp;
	int	flag;

	i = 1;
	if (ac == 1)
		read_stdin(av);
	while (i < ac)
	{
		flag = 0;
		if (av[i][0] == '-' && av[i][1] == 0)
			flag = read_stdin(av);
		fp = open(av[i], O_RDONLY);
		if (fp == -1 && flag == 0)
		{
			print_error(basename(av[0]), av[i]);
			flag = 1;
		}
		if (flag == 0)
			print_f(fp);
		i++;
	}
}

int	read_stdin(char **av)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
	{
		if (errno == 0)
			ft_putchar(buf);
		else
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

void	print_f(int file)
{
	char	c[2];
	int		byte;

	byte = read(file, c, 1);
	while (byte != 0)
	{
		write(1, &c[0], 1);
		byte = read(file, c, 1);
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
	write(1, "\n", 1);
}
