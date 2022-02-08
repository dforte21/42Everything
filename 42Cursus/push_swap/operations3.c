/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:58:31 by dforte            #+#    #+#             */
/*   Updated: 2022/02/08 14:59:56 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stacks *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}

void	ft_rr(t_stacks *stack, int args, int i)
{
	ft_ra(stack, args, i);
	ft_rb(stack, args, i);
}

void	ft_rrr(t_stacks *stack, int args, int i)
{
	ft_rra(stack, args, i);
	ft_rrb(stack, args, i);
}
