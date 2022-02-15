/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/15 14:43:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	backtob(t_stacks *stack, int ac, int i)
{
	int num;

	num = ac;
	while (num > 0)
	{
		i = 0;
		while (stack->sb[i] != num && i < ac)
			i++;
		if (i == ac)
		{
			ft_rra(stack, ac, 1);
			num--;
			continue ;
		}
		while (stack->sb[0] != num)
		{
			if (i > num / 2)
				ft_rrb(stack, ac, 1);
			else
				ft_rb(stack, ac, 0);
		}
		ft_pa(stack, ac, 0);
		num--;
	}
}
