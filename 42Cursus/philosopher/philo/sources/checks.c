/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:15:50 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 14:46:08 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_error("Insert 5 or 6 arguments\n"));
	while (av[i])
	{
		if (av[i][0] == '-' || av[i][0] == '0' || av[i][0] == ' ')
			return (ft_error("Argument must be > 0\n"));
		if (ft_strncmp("2147483647", av[i], ft_strlen(av[i])) != 0
			&& ft_strlen(av[i]) >= 10)
			return (ft_error("Argument is greater than MAX INT\n"));
		if (ft_atoi(av[i]) < 1)
			return (ft_error("Argument is not a number\n"));
		i++;
	}
	return (1);
}

int	ft_error(char *err)
{
	printf("Error\n%s", err);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
