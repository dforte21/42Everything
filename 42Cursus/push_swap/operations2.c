/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:49:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/09 11:33:24 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack, int args, int i)
{
	int	tmp;
	int	tmp2;
	
	while (stack->bsa[i] != false && i < args)
		i++;
	i--;
	tmp = stack->position[i];
	stack->position[i] = stack->position[0];
	i--;
	while (i >= 0)
	{
		tmp2 = stack->position[i];
		stack->position[i] = tmp;
		tmp = tmp2;
		i--;
	}
	ft_printf("ra\n");
}

void	ft_rb(t_stacks *stack, int args, int i)
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
	ft_printf("rb\n");
}

void	ft_rra(t_stacks *stack, int args, int i)
{
	int	tmp;
	int	tmp2;
	
	tmp = stack->position[0];
	while (i < args && stack->bsa[i] != false)
	{
		tmp2 = stack->position[i];
		stack->position[i] = tmp;
		i++;
		tmp = tmp2;
	}
	stack->position[0] = tmp;
	ft_printf("rra\n");
}

void	ft_rrb(t_stacks *stack, int args, int i)
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
	ft_printf("rrb\n");
}
