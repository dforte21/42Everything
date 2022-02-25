/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:23:31 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:58:52 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks, int *tmp)
{
	free(stacks->sa);
	free(stacks->sb);
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

int	border_check(t_stacks *stack, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (stack->sa[i] > stack->sa[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	error_message(t_stacks *stack, int *tmp)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_all(stack, tmp);
}

int	find_num(int *stack, int len, int num)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}
