/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:06:33 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:10:10 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	if (!(checka(av)))
		return (0);
	if (!(checks(av[2])))
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	do_calc(a, b, av[2][0]);
	write(1, "\n", 1);
}

int	checka(char **av)
{
	int	i;

	i = 1;
	while (i < 3)
	{
		if (!av[i])
			return (0);
		i++;
	}
	return (1);
}

int	checks(char s[])
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	if (i > 1)
		return (0);
	if (s[0] != 37 && s[0] != 43 && s[0] != 45 && s[0] != 47 && s[0] != 42)
		return (0);
	return (1);
}

void	do_calc(int a, int b, char sign)
{
	if (sign == 45)
		putnbr(a - b);
	if (sign == 43)
		putnbr(a + b);
	if (sign == 42)
		putnbr(a * b);
	if (sign == 37)
	{
		if (b == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			putnbr(a % b);
	}
	if (sign == 47)
	{
		if (b == 0)
			write(1, "Stop : division by zero", 23);
		else
			putnbr(a / b);
	}
}
