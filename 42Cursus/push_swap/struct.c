/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:53:31 by dforte            #+#    #+#             */
/*   Updated: 2022/02/10 17:42:46 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stacks *stacks, int ac, char **av)
{
	int	i;
	int	n;

	i = 0;
	allocate_struct(stacks, ac);
	while (i < ac - 1)
	{
		if (!check_av(av[i + 1]))
			return (0);
		if (ft_strncmp("2147483647", av[i + 1], 10) < 0
			&& ft_strlen(av[i + 1]) >= 10)
			return (0);
		if (av[i + 1][0] == '-')
			if (ft_strncmp("-2147483648", av[i + 1], 11) < 0
				&& ft_strlen(av[i + 1]) >= 11)
				return (0);
		n = ft_atoi(av[i + 1]);
		stacks->sa[i] = n;
		stacks->bsa[i] = true;
		stacks->sb[i] = 0;
		stacks->bsb[i] = false;
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
		if (av[i] == '-' && i != 0)
			return (0);
		if (!ft_isdigit(av[i]) && av[i] != '-')
			return (0);
		i++;
	}
	if (i == 1 && !ft_isdigit(av[0]))
		return (0);
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
	while (i < args)
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

void	allocate_struct(t_stacks *stack, int ac)
{
	stack->sa = malloc(sizeof(int) * (ac - 1));
	stack->sb = malloc(sizeof(int) * (ac - 1));
	stack->bsa = malloc(sizeof(int) * (ac - 1));
	stack->bsb = malloc(sizeof(int) * (ac - 1));
	stack->position = malloc(sizeof(int) * (ac - 1));
}
