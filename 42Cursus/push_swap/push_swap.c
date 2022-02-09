/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:56:03 by dforte            #+#    #+#             */
/*   Updated: 2022/02/09 16:19:50 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stacks stacks, int ac)
{
	ft_printf("\n");
	for(int i = 0; i < ac - 1; i++)
		ft_printf("%d ", stacks.sb[i]);
	ft_printf("\n");
	for(int i = 0; i < ac - 1; i++)
		ft_printf("%d ", stacks.bsb[i]);
	ft_printf("\n");
	for(int i = 0; i < ac - 1; i++)
		ft_printf("%d ", stacks.position[i]);
	ft_printf("\n");
	for(int i = 0; i < ac - 1; i++)
		ft_printf("%d ", stacks.bsa[i]);
	ft_printf("\n\n");
}

int main(int ac, char **av)
{
	t_stacks	stacks;
	int			*tmp;
	int			i;

	i = 0;
	if(!init_stacks(&stacks, ac, av) || !check_stack(stacks, ac - 1))
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_all(&stacks, NULL);
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
		free_all(&stacks, tmp);
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
	asort(stack, ac);
	while (i < ac / 2)
	{
		ft_pa(stack, ac, 0);
		i++;
	}
}

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

int	stackcmp(t_stacks stacks, int arg)
{
	int	i;

	i = 0;
	while (i <  arg)
	{
		if (stacks.position[i] != i + 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_stack(t_stacks stack, int arg)
{
	int	i;
	int	j;

	i = 0;
	while (i <  arg - 1)
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
