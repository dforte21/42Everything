/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:53:31 by dforte            #+#    #+#             */
/*   Updated: 2022/02/09 16:34:25 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stacks *stacks, int ac, char **av)
{
	int	i;
	int	n;

	i = 1;
	stacks->sa = malloc(sizeof(int) * (ac - 1));
	stacks->sb = malloc(sizeof(int) * (ac - 1));
	stacks->bsa = malloc(sizeof(int) * (ac - 1));
	stacks->bsb = malloc(sizeof(int) * (ac - 1));
	stacks->position = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n == 0)
		{
			if (!check_av(av[i]))
				return (0);
		}
		stacks->sa[i - 1] = n;
		stacks->bsa[i - 1] = true;
		stacks->sb[i - 1] = 0;
		stacks->bsb[i - 1] = false;
		i++;
	}
	return (1);
}

int	check_av(char *av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_position(int sa[], int *position, int args, int *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (i < args - 1)
	{
		j = i + 1;
		while (j < args)
		{
			if (tmp[i] > tmp[j])
			{
				tmp[i] += tmp[j];
				tmp[j] = tmp[i] - tmp[j];
				tmp[i] -= tmp[j];
			}
			j++;
		}
		i++;
	}
	init_position(position, tmp, args, sa);
}

void	init_position(int *position, int *tmp, int args, int sa[])
{
	int	i;
	int	j;

	i = 0;
	while (i <  args)
	{
		j = 0;
		while (j < args)
		{
			if (tmp[i] == sa[j])
				position[j] = i + 1;
			j++;
		}
		i++;
	}
}
