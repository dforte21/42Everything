/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:03:49 by dforte            #+#    #+#             */
/*   Updated: 2022/02/11 12:49:57 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bpa(t_stacks *stack, int args, int i)
{
	if (stack->bsb[0] == false)
		return ;
	if (stack->bsa[0] == true)
	{
		while (stack->bsa[i] != false && i < args)
			i++;
		stack->bsa[i] = true;
		while (i > 0)
		{
			stack->sa[i] = stack->sa[i - 1];
			i--;
		}
	}
	stack->bsa[i] = true;
	stack->sa[0] = stack->sb[0];
	i = 0;
	while (stack->bsb[i + 1] != false && i < args - 1)
	{
		stack->sb[i] = stack->sb[i + 1];
		i++;
	}
	stack->bsb[i] = false;
	stack->sb[i] = 0;
}

void	ft_bpb(t_stacks *stack, int args, int i)
{
	if (stack->bsa[0] == false)
		return ;
	if (stack->bsb[0] == true)
	{
		while (stack->bsb[i] != false && i < args)
			i++;
		stack->bsb[i] = true;
		while (i > 0)
		{
			stack->sb[i] = stack->sb[i - 1];
			i--;
		}
	}
	stack->bsb[i] = true;
	stack->sb[0] = stack->sa[0];
	i = 0;
	while (stack->bsa[i + 1] != false && i < args - 1)
	{
		stack->sa[i] = stack->sa[i + 1];
		i++;
	}
	stack->bsa[i] = false;
	stack->sa[i] = 0;
}

void	ft_bsa(t_stacks *stack)
{
	int	tmp;

	if (stack->bsa[0] == false || stack->bsa[1] == false)
		return ;
	tmp = stack->sa[0];
	stack->sa[0] = stack->sa[1];
	stack->sa[1] = tmp;
}

void	ft_bsb(t_stacks *stack)
{
	int	tmp;

	if (stack->bsb[0] == false || stack->bsb[1] == false)
		return ;
	tmp = stack->sb[0];
	stack->sb[0] = stack->sb[1];
	stack->sb[1] = tmp;
}
