/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/17 16:05:06 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *stack, int ac)
{
	int a_end;

	a_end = find_aend(stack, ac);
	if (crescent_check(stack, ac))
	{
		crescent_sort(stack, ac, a_end);
		return ;
	}
	else
	{
		while (!crescent_check(stack, ac))
		{
			if (stack->position[0] > stack->position[1] && checkminmax(stack, ac, 0))
				ft_sa(stack);
			else
			{
				if (stack->position[1] > stack->position[2] && checkminmax(stack, ac, 1))
					ft_ra(stack, ac, 0);
				else
					ft_rra(stack, ac, 1);
			}
		}
		crescent_sort(stack, ac, a_end);
	}
}

void	crescent_sort(t_stacks *stack, int ac, int a_end)
{
	int	i;
	int	num;

	i = -1;
	num = 1;
	while (i == -1)
	{
		i = find_num(stack->position, ac, num);
		num++;
	}
	if (i > a_end / 2)
	{
		while (i <= a_end)
		{
			ft_rra(stack, ac, 1);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_ra(stack, ac, 0);
			i--;
		}
	}
}

void	big_sort(t_stacks *stack, int ac, int *count, int chunks)
{
	int	i;
	int	j;
	int	k;
	int a_end;

	k = 0;
	a_end = ac;
	while (k < chunks)
	{
		while ((hold_first(stack, a_end, k) != -1 || hold_second(stack, a_end, k) != -1) && !crescent_check(stack, ac) && !decresc_check(stack, ac))
		{
			a_end = find_aend(stack, ac);
			i = hold_first(stack, a_end, k);
			j = hold_second(stack, a_end, k);
			if (i == -1 && j == -1)
				break ;
			if ((i < (a_end - j) && i != -1) || j == -1)
				pushtotopa(stack, ac, i);
			else
				pushtotopa(stack, ac, j);
			if (crescent_check(stack, ac) || decresc_check(stack, ac))
				return ;
			ft_pb(stack, ac, 0);
			*count += 1;
		}
		k++;
	}
}

void	pushtotopa(t_stacks *stack, int ac, int k)
{
	int a_end;

	a_end = find_aend(stack, ac);
	if (k >= a_end / 2)
	{
		while (k <= a_end)
		{
			ft_rra(stack, ac, 1);
			//if (crescent_check(stack, ac))
			//	return ;
			k++;
		}
	}
	else
	{
		while (k > 0)
		{
			ft_ra(stack, ac, 0);
			//if (crescent_check(stack, ac))
			//	return ;
			k--;
		}
	}
}

void	backtob(t_stacks *stack, int ac)
{
	int	i;
	
	while (stack->bsb[0] != false)
	{
		i = find_next(stack, ac);
		if (i != -1)
			pushtotopa(stack, ac, i);
		else
			quick_sort(stack, ac);
		ft_pa(stack, ac, 0);
	}
}
