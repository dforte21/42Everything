/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/17 15:21:51 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	crescent_check(t_stacks *stack, int ac)
{
	int	i;
	int	j;
	int	num;

	i = -1;
	num = 1;
	j = 0;
	while (i == -1)
	{
		i = find_num(stack->position, ac, num);
		num++;
	}
	while (j < i - 1)
	{
		if (stack->position[j] > stack->position[j + 1])
			return (0);
		j++;
	}
	while (i < ac - 1 && stack->bsa[i + 1] == true)
	{
		if (stack->position[i] > stack->position[i + 1])
			return (0);
		i++;
	}
	if (stack->position[i] > stack->position[0])
		return (0);
	return (1);
}

int	decresc_check(t_stacks *stack, int ac)
{
	int	i;
	int	j;
	int	num;

	i = -1;
	num = 100;
	j = 0;
	while (i == -1)
	{
		i = find_num(stack->position, ac, num);
		num--;
	}
	while (j < i - 1)
	{
		if (stack->position[j] < stack->position[j + 1])
			return (0);
		j++;
	}
	while (i < ac - 1 && stack->bsa[i + 1] == true)
	{
		if (stack->position[i] < stack->position[i + 1])
			return (0);
		i++;
	}
	if (stack->position[i] < stack->position[0])
		return (0);
	return (1);
}

int	find_aend(t_stacks *stack, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (stack->bsa[i + 1] == false)
			break ;
		i++;
	}
	if (i == ac)
		i--;
	return (i);
}

int	checkminmax(t_stacks *stack, int ac, int checker)
{
	int	min;
	int	max;
	int	i;

	i = -1;
	min = 1;
	max = 100;
	while (i == -1)
	{
		i = find_num(stack->position, ac, min);
		if (i != -1)
			break;
		min++;
	}
	i = -1;
	while (i == -1)
	{
		i = find_num(stack->position, ac, max);
		if (i != -1)
			break;
		max--;
	}
	if (stack->position[0] == max && stack->position[1] == min)
		return (0);
	if (stack->position[1] == max && stack->position[2] == min && checker == 1)
		return (0);
	return (1);
}

void	pushtotopb(t_stacks *stack, int ac, int k)
{
	int b_end;

	b_end = find_bend(stack, ac);
	if (k >= b_end / 2)
	{
		while (k <= b_end)
		{
			ft_rrb(stack, ac, 1);
			k++;
		}
	}
	else
	{
		while (k > 0)
		{
			ft_rb(stack, ac, 0);
			k--;
		}
	}
}
