/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/08 16:47:58 by dforte           ###   ########.fr       */
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
	int	num;
	int	i;
	int	j;

	num = (arg / 2) + 1;
	i = 0;
	while (num <= arg)
	{
		while (stack->position[i] != num)
		{
			j = find_loc(stack, num, arg);
			if (i == 0 && j == 1)
			{
				ft_sa(stack);
				break;
			}
			if (j > i)
				ft_ra(stack, arg, 0);
			if (j < i)
				ft_rra(stack, arg, 1);
		}
		i++;
		num++;
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
