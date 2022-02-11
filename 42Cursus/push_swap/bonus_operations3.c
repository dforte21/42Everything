/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:05:13 by dforte            #+#    #+#             */
/*   Updated: 2022/02/11 12:13:47 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bss(t_stacks *stack)
{
	ft_bsa(stack);
	ft_bsb(stack);
}

void	ft_brr(t_stacks *stack, int args, int i)
{
	ft_bra(stack, args, i);
	ft_brb(stack, args, i);
}

void	ft_brrr(t_stacks *stack, int args, int i)
{
	ft_brra(stack, args, i);
	ft_brrb(stack, args, i);
}
