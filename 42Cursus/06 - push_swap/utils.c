/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:23:31 by dforte            #+#    #+#             */
/*   Updated: 2022/05/18 13:02:39 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_stacks *stacks, int *tmp, char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	free(stacks->sa);
	free(stacks->sb);
	free(stacks->position);
	if (tmp)
		free(tmp);
	return (1);
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

int	error_message(t_stacks *stack, int *tmp, char **mat)
{
	write(STDERR_FILENO, "Error\n", 6);
	free_all(stack, tmp, mat);
	return (1);
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
