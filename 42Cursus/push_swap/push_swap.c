/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:56:03 by dforte            #+#    #+#             */
/*   Updated: 2022/02/11 13:55:54 by dforte           ###   ########.fr       */
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
	{
		error_message(&stacks, tmp);
		return (0);
	}
	process_start(&stacks, ac - 1);
	free_all(&stacks, tmp);
}

void	process_start(t_stacks *stack, int ac)
{
	int	i;

	i = 0;
	fsort(stack, ac);
	if (order_check(stack, ac) && sb_check(stack, ac))
		return ;
	asort(stack, ac);
	while (i < ac / 2)
	{
		ft_pa(stack, ac, 0);
		i++;
	}
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
