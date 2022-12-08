/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:05:13 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:37:59 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bss(t_stacks *stack)
{
	ft_bsa(stack);
	ft_bsb(stack);
}

void	ft_brr(t_stacks *stack)
{
	ft_bra(stack, stack->alen);
	ft_brb(stack, stack->blen);
}

void	ft_brrr(t_stacks *stack)
{
	ft_brra(stack, stack->alen);
	ft_brrb(stack, stack->blen);
}
