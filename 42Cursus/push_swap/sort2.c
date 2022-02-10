/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/10 17:42:10 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_reversesa(t_stacks *stack, int arg)
{
	if (stack->position[0] == arg && stack->position[1] == arg / 2 + 1)
		return (1);
	return (0);
}
