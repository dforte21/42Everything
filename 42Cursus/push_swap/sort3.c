/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:17 by dforte            #+#    #+#             */
/*   Updated: 2022/02/19 13:37:16 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hold_first(t_stacks *stack, int len, int k)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (stack->position[i] > 0  && stack->position[i] <= 20 * k && stack->position[i] != 100)
			return (i);
		i++;
	}
	return (-1);
}

int	hold_second(t_stacks *stack, int len, int k)
{
	int	i;

	i = len;
	while (i >= 0)
	{
		if (stack->position[i] > 0  && stack->position[i] <= 20 * k && stack->position[i] != 100)
			return (i);
		i--;
	}
	return (-1);
}

int	findmin(int	*stack, int len)
{
	int	i;
	int	num;

	i = -1;
	num = 1;
	while (i == -1 && num <= 100)
	{
		i = find_num(stack, len, num);
		num++;
	}
	return (i);
}

int	findmax(int	*stack, int len)
{
	int	i;
	int	num;

	i = -1;
	num = 100;
	while (i == -1 && num > 0)
	{
		i = find_num(stack, len, num);
		num--;
	}
	return (i);
}

int	order_check(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = findmin(stack, len);
	while (i < j - 1)
	{
		if (stack[i] > stack[i + 1] && check_minmax(stack, len, i))
			return (i);
		i++;
	}
	while (j < len)
	{
		if (stack[j] > stack[j + 1] && check_minmax(stack, len, j))
			return (j);
		j++;
	}
	if (stack[len] > stack[0] && check_minmax(stack, len, len))
		return (len);
	return (-1);
}
