/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:58:08 by dforte           ###   ########.fr       */
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

void	big_sort(t_stacks *stack, int ac)
{
	int	i;
	int	maxcomb;
	int	*bestcomb;

	maxcomb = ac - 1;
	bestcomb = getbestcomb(stack, &maxcomb);
	i = 0;
	while (stack->alen != maxcomb - 1)
	{
		if (!checknumb(stack->position[i], bestcomb, maxcomb))
		{
			pushtotop(stack, stack->alen, i, 0);
			ft_pb(stack, stack->blen);
			i = 0;
		}
		else
			i++;
	}
	free(bestcomb);
}

void	backtob(t_stacks *stack, int ac)
{
	int	i;
	int	j;

	while (stack->blen >= 0)
	{
		i = findbestnum(stack, ac, 0);
		j = findnext(stack, stack->sb[i], ac);
		orderstacks(stack, i, j);
		ft_pa(stack, stack->alen);
	}
	i = findmin(stack->position, stack->alen);
	pushtotop(stack, stack->alen, i, 0);
}

int	findbestnum(t_stacks *stack, int ac, int moves)
{
	int	i;
	int	j;
	int	count;

	while (moves < ac)
	{
		i = 0;
		while (i <= stack->blen)
		{
			count = i;
			if (i > stack->blen / 2)
				count = stack->blen - i + 1;
			j = findnext(stack, stack->sb[i], ac);
			if (j > stack->alen / 2)
				j = stack->alen - j + 1;
			count += j;
			if (count == moves)
				break ;
			i++;
		}
		if (count == moves)
			break ;
		moves++;
	}
	return (i);
}

void	orderstacks(t_stacks *stack, int i, int j)
{
	if (i > stack->blen / 2 && j > stack->alen / 2)
	{
		while (i <= stack->blen && j <= stack->alen)
		{
			ft_rrr(stack);
			i++;
			j++;
		}
	}
	if (i <= stack->blen / 2 && j < stack->alen / 2)
	{
		while (i > 0 && j > 0)
		{
			ft_rr(stack);
			i--;
			j--;
		}
	}
	pushtotop(stack, stack->blen, i, 1);
	pushtotop(stack, stack->alen, j, 0);
}
