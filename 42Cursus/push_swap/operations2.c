/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:49:41 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:02:01 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack, int len, int check)
{
	int	tmp;
	int	tmp2;

	tmp = stack->position[len];
	stack->position[len] = stack->position[0];
	len--;
	while (len >= 0)
	{
		tmp2 = stack->position[len];
		stack->position[len] = tmp;
		tmp = tmp2;
		len--;
	}
	if (check == 0)
		ft_printf("ra\n");
}

void	ft_rb(t_stacks *stack, int len, int check)
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
	if (check == 0)
		ft_printf("rb\n");
}

void	ft_rra(t_stacks *stack, int len, int check)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 1;
	tmp = stack->position[0];
	while (i <= len)
	{
		tmp2 = stack->position[i];
		stack->position[i] = tmp;
		i++;
		tmp = tmp2;
	}
	stack->position[0] = tmp;
	if (check == 0)
		ft_printf("rra\n");
}

void	ft_rrb(t_stacks *stack, int len, int check)
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
	if (check == 0)
		ft_printf("rrb\n");
}
