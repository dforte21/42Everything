/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:05:36 by dforte            #+#    #+#             */
/*   Updated: 2022/02/22 11:32:06 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks *stack, int len)
{
	if (stack->blen == -1)
		return ;
	if (stack->alen >= 0)
	{
		len++;
		while (len > 0)
		{
			stack->position[len] = stack->position[len - 1];
			len--;
		}
	}
	stack->alen++;
	stack->position[0] = stack->sb[0];
	len = 0;
	while (len < stack->blen)
	{
		stack->sb[len] = stack->sb[len + 1];
		len++;
	}
	stack->sb[stack->blen] = 0;
	stack->blen--;
	ft_printf("pa\n");
}

void	ft_pb(t_stacks *stack, int len)
{
	if (stack->alen == -1)
		return ;
	if (stack->blen >= 0)
	{
		len++;
		while (len > 0)
		{
			stack->sb[len] = stack->sb[len - 1];
			len--;
		}
	}
	stack->blen++;
	stack->sb[0] = stack->position[0];
	len = 0;
	while (len < stack->alen)
	{
		stack->position[len] = stack->position[len + 1];
		len++;
	}
	stack->position[stack->alen] = 0;
	stack->alen--;
	ft_printf("pb\n");
}

void	ft_sa(t_stacks *stack)
{
	int	tmp;

	if (stack->alen < 1)
		return ;
	tmp = stack->position[0];
	stack->position[0] = stack->position[1];
	stack->position[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_stacks *stack)
{
	int	tmp;

	if (stack->blen < 1)
		return ;
	tmp = stack->sb[0];
	stack->sb[0] = stack->sb[1];
	stack->sb[1] = tmp;
	ft_printf("sb\n");
}
