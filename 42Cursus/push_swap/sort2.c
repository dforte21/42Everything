/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/14 19:10:43 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushtodown(t_stacks *stack, int ac, int j, int i)
{
	if (j < i / 2)
	{
		j += i;
		while (j >= i)
		{
			ft_rb(stack, ac, 0);
			j--;
		}
	}
	else
	{
		while (j < i)
		{
			ft_rrb(stack, ac, 0);
			j++;
		}
	}
}

void	reset_bstack(t_stacks *stack, int ac, int n)
{
	int	i;
	int	j;
	int num;

	i = 0;
	num = -2147483648;
	while (i < ac && stack->bsb[i] != false)
	{
		if (stack->sb[i] > num && stack->sb[i] > (20 * (n - 1)))
		{
			num = stack->sb[i];
			j = i;
		}
		i++;
	}
	i--;
	if (j != i)
		pushtodown(stack, ac, j, i);
}

void	backtob(t_stacks *stack, int ac, int i)
{
	while (i > 0)
	{
		ft_rrb(stack, ac, 1);
		ft_pa(stack, ac, 0);
		i--;
	}
}

int	find_maxn(t_stacks *stack, int ac)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = -2147483648;
	while (stack->bsb[i] != false && i < ac)
	{
		if (stack->sb[i] > num)
		{
			num = stack->sb[i];
			j = i;
		}
		i++;
	}
	return (j);
}
