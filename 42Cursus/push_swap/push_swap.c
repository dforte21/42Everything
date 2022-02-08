/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:56:03 by dforte            #+#    #+#             */
/*   Updated: 2022/02/08 15:00:56 by dforte           ###   ########.fr       */
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
	if(!init_stacks(&stacks, ac, av))
	{
		ft_printf("Error\n");
		return (0);
	}
	tmp = malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		tmp[i] = stacks.sa[i];
		i++;
	}
	get_position(stacks.sa, stacks.position, ac - 1, tmp);
	print_stack(stacks, ac);
	free_all(&stacks, tmp);
}

void	free_all(t_stacks *stacks, int *tmp)
{
	free(stacks->sa);
	free(stacks->sb);
	free(stacks->bsa);
	free(stacks->bsb);
	free(stacks->position);
	free(tmp);
}
