/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:23:31 by dforte            #+#    #+#             */
/*   Updated: 2022/02/10 18:30:56 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks, int *tmp)
{
	free(stacks->sa);
	free(stacks->sb);
	free(stacks->bsa);
	free(stacks->bsb);
	free(stacks->position);
	if (tmp)
		free(tmp);
}

int	check_stack(t_stacks stack, int arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg - 1)
	{
		j = i + 1;
		while (j < arg)
		{
			if (stack.sa[i] == stack.sa[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
