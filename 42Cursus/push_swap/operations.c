/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:05:36 by dforte            #+#    #+#             */
/*   Updated: 2022/02/08 14:58:28 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks *stack, int args, int i)
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
			stack->position[i] = stack->position[i - 1];
			i--;
		}
	}
	stack->bsa[i] = true;
	stack->position[0] = stack->sb[0];
	i = 0;
	while (stack->bsb[i + 1] != false && i < args - 1)
	{
		stack->sb[i] = stack->sb[i + 1];
		i++;
	}
	stack->bsb[i] = false;
	stack->sb[i] = 0;
	
}

void	ft_pb(t_stacks *stack, int args, int i)
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
	stack->sb[0] = stack->position[0];
	i = 0;
	while (stack->bsa[i + 1] != false && i < args - 1)
	{
		stack->position[i] = stack->position[i + 1];
		i++;
	}
	stack->bsa[i] = false;
	stack->position[i] = 0;
}

void	ft_sa(t_stacks *stack)
{
	int	tmp;

	if (stack->bsa[0] == false || stack->bsa[1] == false)
		return ;
	tmp = stack->position[0];
	stack->position[0] = stack->position[1];
	stack->position[1] = tmp;
}

void	ft_sb(t_stacks *stack)
{
	int	tmp;

	if (stack->bsb[0] == false || stack->bsb[1] == false)
		return ;
	tmp = stack->sb[0];
	stack->sb[0] = stack->sb[1];
	stack->sb[1] = tmp;
}
