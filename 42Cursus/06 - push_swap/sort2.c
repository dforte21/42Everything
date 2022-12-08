/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:14 by dforte            #+#    #+#             */
/*   Updated: 2022/02/25 12:58:44 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*getbestcomb(t_stacks *stack, int *maxcomb)
{
	int	i;
	int	count;
	int	*tmp;

	while (maxcomb > 0)
	{
		i = 0;
		while (i <= stack->alen)
		{
			checkstack(stack, &count, i);
			if (count == *maxcomb)
				break ;
			i++;
		}
		if (count == *maxcomb)
			break ;
		*maxcomb -= 1;
	}
	tmp = malloc(sizeof(int) * *maxcomb);
	stackcopy(stack, i, tmp);
	return (tmp);
}

void	checkstack(t_stacks *stack, int *count, int i)
{
	int	j;
	int	k;

	*count = 1;
	j = i + 1;
	k = i;
	while (j <= stack->alen)
	{
		if (stack->position[j] > stack->position[k])
		{
			k = j;
			*count += 1;
		}
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (stack->position[j] > stack->position[k])
		{
			k = j;
			*count += 1;
		}
		j++;
	}
}

void	stackcopy(t_stacks *stack, int i, int *tmp)
{
	int	j;
	int	k;

	tmp[0] = stack->position[i];
	j = i + 1;
	k = 0;
	while (j <= stack->alen)
	{
		if (stack->position[j] > tmp[k])
		{
			k++;
			tmp[k] = stack->position[j];
		}
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (stack->position[j] > tmp[k])
		{
			k++;
			tmp[k] = stack->position[j];
		}
		j++;
	}
}

int	checknumb(int num, int *bestcomb, int maxcomb)
{
	int	i;

	i = 0;
	while (i < maxcomb)
	{
		if (bestcomb[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	findnext(t_stacks *stack, int num, int ac)
{
	int	i;
	int	find;

	find = num + 1;
	i = -1;
	while (i == -1 && find <= ac)
	{
		i = find_num(stack->position, stack->alen, find);
		find++;
	}
	return (i);
}
