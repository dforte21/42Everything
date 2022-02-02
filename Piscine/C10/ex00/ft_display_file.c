/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:17:25 by dforte            #+#    #+#             */
/*   Updated: 2021/12/15 17:17:26 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	printf_f(int file);

int	main(int ac, char **av)
{
	int	fp;

	if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	if (ac < 2)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	fp = open(av[1], O_RDONLY);
	if (fp == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	printf_f(fp);
}

void	printf_f(int file)
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
