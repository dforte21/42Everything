/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/15 14:54:18 by dforte           ###   ########.fr       */
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
			if (order_check(stack, ac))
				return ;
			ft_pb(stack, ac, 0);
			*count += 1;
		}
		i++;
	}
}

void	pushtotop(t_stacks *stack, int ac, int i, int j)
{
	int max;

    max = 0;
    while (stack->bsa[max + 1] != false && max < ac)
        max++;
	if (((i <= (max - j) && i > -1) || j == -1))
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
		while (j <= max)
		{
			ft_rra(stack, ac, 1);
			if (order_check(stack, ac))
				return ;
			j++;
		}
	}
}

int	find_holdf(t_stacks *stack, int n, int ac)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (stack->bsa[max + 1] != false && max < ac)
		max++;
	while (i < max / 2)
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
	int max;

	max = 0;
	while (stack->bsa[max + 1] != false && max < ac)
		max++;
	i = max;
	while (i >= max / 2)
	{
		if (stack->position[i] <= (20 * n) && stack->position[i] > (20 * (n - 1)))
			return (i);
		i--;
	}
	return (-1);
}

void	sort_a(t_stacks *stack, int ac)
{
	ft_sa(stack);
	ft_rra(stack, ac, 1);
}
