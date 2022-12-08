/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:58:31 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:02:15 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stacks *stack)
{
	ft_sa(stack);
	ft_sb(stack);
	ft_printf("ss\n");
}

void	ft_rr(t_stacks *stack)
{
	ft_ra(stack, stack->alen, 1);
	ft_rb(stack, stack->blen, 1);
	ft_printf("rr\n");
}

void	ft_rrr(t_stacks *stack)
{
	ft_rra(stack, stack->alen, 1);
	ft_rrb(stack, stack->blen, 1);
	ft_printf("rrr\n");
}
