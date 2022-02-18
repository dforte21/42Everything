/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:17 by dforte            #+#    #+#             */
/*   Updated: 2022/02/18 14:19:28 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hold_first(t_stacks *stack, int a_end, int k)
{
	int	i;

	i = 0;
	while (i < a_end)
	{
		if (stack->position[i] > 0  && stack->position[i] <= 20 * k)
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
		if (stack->position[i] > 0  && stack->position[i] <= 20 * k)
			return (i);
		i--;
	}
	return (-1);
}
