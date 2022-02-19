/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/19 13:37:37 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *stack)
{
	int	i;

	while (order_check(stack->position, stack->alen) != -1)
	{
		i = order_check(stack->position, stack->alen);
		pushtotop(stack, stack->alen, i, 0);
		ft_sa(stack);
	}
	i = findmin(stack->position, stack->alen);
	pushtotop(stack, stack->alen, i, 0);
}

void	big_sort(t_stacks *stack, int chunks)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	while (k <= chunks)
	{
		while (hold_first(stack, stack->alen, k) != -1 || hold_second(stack, stack->alen, k) != -1)
		{
			i = hold_first(stack, stack->alen, k);
			j = hold_second(stack, stack->alen, k);
			if ((i < stack->alen - j && i != -1) || j == -1)
			{
				pushtotop(stack, stack->alen, i, 0);
				orderb(stack);
			}
			else
			{
				pushtotop(stack, stack->alen, j, 0);
				orderb(stack);
			}
			ft_pb(stack, stack->blen);
		}
		k++;
	}
}

void	backtob(t_stacks *stack)
{
	int	num;
	int	i;

	num = 99;
	while (num > 0)
	{
		i = find_num(stack->sb,stack->blen, num);
		pushtotop(stack, stack->blen, i, 1);
		ft_pa(stack, stack->alen);
		num--;
	}
}
