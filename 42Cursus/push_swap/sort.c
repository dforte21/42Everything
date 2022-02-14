/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/14 19:15:21 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_start(t_stacks *stack, int ac, int chunks, int *count)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i <= chunks)
	{
		while (find_holdf(stack, i, ac) != -1 || find_holds(stack, i, ac) != -1)
		{
			j = find_holdf(stack, i, ac);
			k = find_holds(stack, i, ac);
			pushtotop(stack, ac , j, k);
			check_bstack(stack, ac);
			ft_pb(stack, ac, 0);
			reset_bstack(stack, ac, i);
			*count += 1;
		}
		i++;
	}
}

void	check_bstack(t_stacks *stack, int ac)
{
	int	i;
	int	j;
	int	num;

	if (stack->bsb[0] == false)
		return ;
	j = -1;
	i = 0;
	num = -2147483648;
	while (stack->bsb[i] != false && i < ac)
	{
		if (stack->sb[i] > num && stack->sb[i] < stack->position[0])
		{
			num = stack->sb[i];
			j = i;
		}
		i++;
	}
	i--;
	if (i > 1)
		pushtodown(stack, ac, j, i);
}

void	pushtotop(t_stacks *stack, int ac, int i, int j)
{
	j = ac - j;
	if ((i < j && i > -1))
	{
		while (i > 0)
		{
			ft_ra(stack, ac, 0);
			if (order_check(stack, ac))
				return ;
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			ft_rra(stack, ac, 1);
			if (order_check(stack, ac))
				return ;
			j--;
		}
	}
}

int	find_holdf(t_stacks *stack, int n, int ac)
{
	int	i;

	i = 0;
	while (i < ac / 2)
	{
		if (stack->position[i] <= (20 * n) && stack->position[i] > (20 * (n - 1)))
			return (i);
		i++;
	}
	return (-1);
}

int	find_holds(t_stacks *stack, int n, int ac)
{
	int	i;

	i = 0;
	while (stack->position[i + 1] != false && i < ac)
		i++;
	i--;
	while (i >= ac / 2)
	{
		if (stack->position[i] <= (20 * n) && stack->position[i] > (20 * (n - 1)))
			return (i);
		i--;
	}
	return (-1);
}
