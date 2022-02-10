/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/10 17:41:55 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fsort(t_stacks *stack, int arg)
{
	int	num;
	int	i;

	num = 1;
	while (num <= arg / 2)
	{
		while (stack->position[0] != num)
		{
			i = find_loc(stack, num, arg);
			if (i == 1)
				ft_sa(stack);
			if (i == 2)
				ft_ra(stack, arg, 0);
			if (i > 2)
				ft_rra(stack, arg, 1);
		}
		ft_pb(stack, arg, 0);
		num++;
	}
}

void	asort(t_stacks *stack, int arg)
{
	while (!check_sa(stack, arg))
	{
		if (stack->position[0] > stack->position[1]
			&& !c_sa(stack, arg) && !c_reversesa(stack, arg))
			ft_sa(stack);
		else
			ft_ra(stack, arg, 0);
	}
}

int	find_loc(t_stacks *stack, int num, int arg)
{
	int	i;

	i = 0;
	while (i < arg)
	{
		if (stack->position[i] == num)
			return (i);
		i++;
	}
	return (i);
}

int	check_sa(t_stacks *stack, int arg)
{
	int	i;
	int	num;

	i = 0;
	num = (arg / 2) + 1;
	while (num <= arg)
	{
		if (stack->position[i] != num)
			return (0);
		i++;
		num++;
	}
	return (1);
}

int	c_sa(t_stacks *stack, int arg)
{
	int	i;
	int	j;

	i = find_loc(stack, ((arg / 2) + 1), arg);
	j = 0;
	while (j < i - 1)
	{
		if (stack->position[j] > stack->position[j + 1])
			return (0);
		j++;
	}
	while (i < arg / 2)
	{
		if (stack->position[i] > stack->position[i + 1])
			return (0);
		i++;
	}
	if (stack->position[i] > stack->position[0])
		return (0);
	return (1);
}
