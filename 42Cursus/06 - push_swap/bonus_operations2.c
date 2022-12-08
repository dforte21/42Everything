/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:04:44 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:49:06 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bra(t_stacks *stack, int len)
{
	int	tmp;
	int	tmp2;

	tmp = stack->sa[len];
	stack->sa[len] = stack->sa[0];
	len--;
	while (len >= 0)
	{
		tmp2 = stack->sa[len];
		stack->sa[len] = tmp;
		tmp = tmp2;
		len--;
	}
}

void	ft_brb(t_stacks *stack, int len)
{
	int	tmp;
	int	tmp2;

	tmp = stack->sb[len];
	stack->sb[len] = stack->sb[0];
	len--;
	while (len >= 0)
	{
		tmp2 = stack->sb[len];
		stack->sb[len] = tmp;
		tmp = tmp2;
		len--;
	}
}

void	ft_brra(t_stacks *stack, int len)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 1;
	tmp = stack->sa[0];
	while (i <= len)
	{
		tmp2 = stack->sa[i];
		stack->sa[i] = tmp;
		i++;
		tmp = tmp2;
	}
	stack->sa[0] = tmp;
}

void	ft_brrb(t_stacks *stack, int len)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 1;
	tmp = stack->sb[0];
	while (i <= len)
	{
		tmp2 = stack->sb[i];
		stack->sb[i] = tmp;
		i++;
		tmp = tmp2;
	}
	stack->sb[0] = tmp;
}
