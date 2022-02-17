/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:17 by dforte            #+#    #+#             */
/*   Updated: 2022/02/17 15:52:39 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hold_first(t_stacks *stack, int a_end, int k)
{
	int	i;

	i = 0;
	while (i < a_end)
	{
		if (stack->position[i] > 20 * k  && stack->position[i] <= 20 * (k + 1))
			return (i);
		i++;
	}
	return (-1);
}

int	hold_second(t_stacks *stack, int a_end, int k)
{
	int	i;

	i = a_end;
	while (i > 0)
	{
		if (stack->position[i] > 20 * k  && stack->position[i] <= 20 * (k + 1))
			return (i);
		i--;
	}
	return (-1);
}

int	find_bend(t_stacks *stack, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (stack->bsb[i + 1] == false)
			break ;
		i++;
	}
	if (i == ac)
		i--;
	return (i);
}

int	find_next(t_stacks *stack, int ac)
{
	int	i;
	int num;

	num = stack->sb[0] + 1;
	i = -1;
	while (num <= 100)
	{
		i = find_num(stack->position, ac, num);
		if (i != -1)
			break ;
		num ++;
	}
	return (i);
}
