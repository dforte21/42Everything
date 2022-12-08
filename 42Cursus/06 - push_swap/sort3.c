/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:46:17 by dforte            #+#    #+#             */
/*   Updated: 2022/05/18 15:43:51 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushtotop(t_stacks *stack, int len, int i, int check)
{
	if (i > len / 2)
	{
		while (i <= len)
		{
			if (check == 0)
				ft_rra(stack, len, 0);
			else
				ft_rrb(stack, len, 0);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			if (check == 0)
				ft_ra(stack, len, 0);
			else
				ft_rb(stack, len, 0);
			i--;
		}
	}
}

int	order_check(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = findmin(stack, len);
	while (i < j)
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
