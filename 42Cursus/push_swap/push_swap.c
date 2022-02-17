/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:56:03 by dforte            #+#    #+#             */
/*   Updated: 2022/02/17 16:04:03 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			*tmp;
	int			i;

	i = 0;
	if (!init_stacks(&stacks, ac, av) || !check_stack(stacks, ac - 1))
	{
		error_message(&stacks, NULL);
		return (0);
	}
	tmp = malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		tmp[i] = stacks.sa[i];
		i++;
	}
	get_position(stacks.sa, stacks.position, ac - 1, tmp);
	if (stackcmp(stacks, ac - 1))
		return (0);
	process_start(&stacks, ac - 1);
	//ft_printf("\n\n");
	//for(int j = 0; j < ac - 1; j++)
	//	ft_printf("%d ", stacks.position[j]);
	free_all(&stacks, tmp);
}

void	process_start(t_stacks *stack, int ac)
{
	int	i;
	int	chunks;
	
	i = 0;
	chunks = ac / 20;
	if (ac % 20 != 0)
		chunks++;
	if (ac <= 5 || crescent_check(stack, ac) || decresc_check(stack, ac))
	{
		quick_sort(stack, ac);
		return ;
	}
	big_sort(stack, ac, &i, chunks);
	quick_sort(stack, ac);
	backtob(stack, ac);
	quick_sort(stack, ac);
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

int	sb_check(t_stacks *stack, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (stack->bsb[i] == true)
			return (0);
		i++;
	}
	return (1);
}
