/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:56:03 by dforte            #+#    #+#             */
/*   Updated: 2022/05/18 14:48:30 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**mat;
	int			*tmp;
	int			i;

	i = 0;
	mat = loadmat(&ac, av);
	if (!init_stacks(&stacks, ac, mat) || !check_stack(stacks, ac - 1))
		return (error_message(&stacks, NULL, mat));
	tmp = malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		tmp[i] = stacks.sa[i];
		i++;
	}
	get_position(stacks.sa, stacks.position, ac - 1, tmp);
	if (stackcmp(stacks, ac - 1))
		return (free_all(&stacks, tmp, mat));
	process_start(&stacks, ac - 1);
	free_all(&stacks, tmp, mat);
}

void	process_start(t_stacks *stack, int ac)
{
	if (ac <= 10 || order_check(stack->position, stack->alen) == -1)
	{
		quick_sort(stack);
		return ;
	}
	big_sort(stack, ac);
	backtob(stack, ac);
}

int	stackcmp(t_stacks stacks, int arg)
{
	int	i;

	i = 0;
	while (i < arg - 1)
	{
		if (stacks.position[i] != i + 1)
			return (0);
		i++;
	}
	return (1);
}
