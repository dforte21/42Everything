/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:56:03 by dforte            #+#    #+#             */
/*   Updated: 2022/02/19 13:35:15 by dforte           ###   ########.fr       */
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
	free_all(&stacks, tmp);
}

void	process_start(t_stacks *stack, int ac)
{
	int	chunks;

	chunks = ac / 20;
	if (ac % 20 != 0)
		chunks++;
	if (ac <= 10 || order_check(stack->position, stack->alen) == -1)
	{
		quick_sort(stack);
		return ;
	}
	big_sort(stack, chunks);
	backtob(stack);
	//ft_printf("\n\n");
	//for (int i = 0; i < ac; i++)
	//	ft_printf("%d ", stack->sb[i]);
	//ft_printf("\n\n");
	//for (int i = 0; i < ac; i++)
	//	ft_printf("%d ", stack->position[i]);
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
