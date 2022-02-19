/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/19 13:53:36 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_minmax(int *stack, int len, int position)
{
	int	i;
	int	j;

	i = findmin(stack, len);
	j = findmax(stack, len);
	if (position == len)
	{
		if (j == position && i == 0)
			return (0);
	}
	if (j == position && i == j + 1)
		return (0);
	return (1);
}

void	pushtotop(t_stacks *stack, int len, int i, int check)
{
	if (i > len / 2)
	{
		while (i <= len)
		{
			if (check == 0)
				ft_rra(stack, len);
			else
				ft_rrb(stack, len);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			if (check == 0)
				ft_ra(stack, len);
			else
				ft_rb(stack, len);
			i--;
		}
	}
}

void	orderb(t_stacks *stack)
{
	int	i;
	int	num;

	num = stack->position[0] - 1;
	i = -1;
	while (i == -1 && num > 0)
	{
		i = find_num(stack->sb, stack->blen, num);
		num--;
	}
	if (i == -1)
		i = findmax(stack->sb, stack->blen);
	pushtotop(stack, stack->blen, i, 1);
}
