/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:04:44 by dforte            #+#    #+#             */
/*   Updated: 2022/02/11 12:50:03 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bra(t_stacks *stack, int args, int i)
{
	int	tmp;
	int	tmp2;

	while (stack->bsa[i] != false && i < args)
		i++;
	i--;
	tmp = stack->sa[i];
	stack->sa[i] = stack->sa[0];
	i--;
	while (i >= 0)
	{
		tmp2 = stack->sa[i];
		stack->sa[i] = tmp;
		tmp = tmp2;
		i--;
	}
}

void	ft_brb(t_stacks *stack, int args, int i)
{
	int	tmp;
	int	tmp2;

	while (stack->bsb[i] != false && i < args)
		i++;
	i--;
	tmp = stack->sb[i];
	stack->sb[i] = stack->sb[0];
	i--;
	while (i >= 0)
	{
		tmp2 = stack->sb[i];
		stack->sb[i] = tmp;
		tmp = tmp2;
		i--;
	}
}

void	ft_brra(t_stacks *stack, int args, int i)
{
	int	tmp;
	int	tmp2;

	tmp = stack->sa[0];
	while (i < args && stack->bsa[i] != false)
	{
		tmp2 = stack->sa[i];
		stack->sa[i] = tmp;
		i++;
		tmp = tmp2;
	}
	stack->sa[0] = tmp;
}

void	ft_brrb(t_stacks *stack, int args, int i)
{
	int	tmp;
	int	tmp2;

	tmp = stack->sb[0];
	while (i < args && stack->bsb[i] != false)
	{
		tmp2 = stack->sb[i];
		stack->sb[i] = tmp;
		i++;
		tmp = tmp2;
	}
	stack->sb[0] = tmp;
}
