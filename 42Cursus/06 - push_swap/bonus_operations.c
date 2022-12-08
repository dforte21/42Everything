/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:03:49 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:48:45 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bpa(t_stacks *stack, int len)
{
	if (stack->blen == -1)
		return ;
	if (stack->alen >= 0)
	{
		len++;
		while (len > 0)
		{
			stack->sa[len] = stack->sa[len - 1];
			len--;
		}
	}
	stack->alen++;
	stack->sa[0] = stack->sb[0];
	len = 0;
	while (len < stack->blen)
	{
		stack->sb[len] = stack->sb[len + 1];
		len++;
	}
	stack->sb[stack->blen] = 0;
	stack->blen--;
}

void	ft_bpb(t_stacks *stack, int len)
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
	stack->sb[0] = stack->sa[0];
	len = 0;
	while (len < stack->alen)
	{
		stack->sa[len] = stack->sa[len + 1];
		len++;
	}
	stack->sa[stack->alen] = 0;
	stack->alen--;
}

void	ft_bsa(t_stacks *stack)
{
	int	tmp;

	if (stack->alen < 1)
		return ;
	tmp = stack->sa[0];
	stack->sa[0] = stack->sa[1];
	stack->sa[1] = tmp;
}

void	ft_bsb(t_stacks *stack)
{
	int	tmp;

	if (stack->blen < 1)
		return ;
	tmp = stack->sb[0];
	stack->sb[0] = stack->sb[1];
	stack->sb[1] = tmp;
}
