/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:42:48 by dforte            #+#    #+#             */
/*   Updated: 2021/12/15 23:42:52 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	int	i;
	int	flag;

	i = 2;
	if (ac == 1 || ac == 2)
		stdin_f(av);
	if (ac == 3)
		process_start(av[0], av[1], av[2]);
	while (i < ac && ac > 3)
	{
		flag = 0;
		if (!(checkf(av[0], av[i])))
			flag = 1;
		if (flag == 0)
		{
			if (i != 2)
				ft_putchar('\n');
			printfh(av[i]);
			ft_putchar('\n');
			process_start(av[0], av[1], av[i]);
		}
		i++;
	}
}

int	get_flen(char *file, int *size)
{
	int		fp;
	int		byte;
	char	c[2];

	fp = open(file, O_RDONLY);
	if (fp == -1)
		return (0);
	byte = read(fp, &c[0], 1);
	while (byte != 0)
	{
		*size += 1;
		byte = read(fp, &c[0], 1);
	}
	close(fp);
	return (1);
}

int	print_f(int to_read, char *file, int size)
{
	int		i;
	int		fp;
	int		byte;
	char	c[2];

	i = 0;
	fp = open(file, O_RDONLY);
	if (fp == -1)
		return (0);
	while (i <= (size - to_read))
	{
		byte = read(fp, &c[0], 1);
		i++;
	}
	while (byte != 0)
	{
		ft_putchar(c[0]);
		byte = read(fp, &c[0], 1);
	}
	close(fp);
	return (1);
}

int	process_start(char *filename, char *fread, char *file)
{
	int	size;
	int	read;

	size = 0;
	if (!(get_flen(file, &size)))
	{
		print_error(basename(filename), file);
		return (0);
	}
	read = ft_atoi(fread);
	if (read == 0)
		return (0);
	if (!(print_f(read, file, size)))
	{
		print_error(basename(filename), file);
		return (0);
	}
	return (1);
}

int	checkf(char *file, char *filename)
{
	int	fp;

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		print_error(basename(file), filename);
		return (0);
	}
	close(fp);
	return (1);
}
