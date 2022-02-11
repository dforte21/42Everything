/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:04:49 by dforte            #+#    #+#             */
/*   Updated: 2022/02/11 13:57:11 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (!init_stacks(&stacks, ac, av) || !check_stack(stacks, ac - 1))
	{
		error_message(&stacks, NULL);
		return (0);
	}
	if (border_check(&stacks, ac - 1))
	{
		error_message(&stacks, NULL);
		return (0);
	}
	if (!ft_read(ac, &stacks))
	{
		error_message(&stacks, NULL);
		return (0);
	}
	if (border_check(&stacks, ac -1) && bsb_check(&stacks, ac - 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stacks, NULL);
}

int	ft_read(int ac, t_stacks *stacks)
{
	char	*buffer;

	buffer = ft_calloc(5, 1);
	while (read(0, buffer, 4))
	{
		if (check_buffer(buffer))
		{
			free(buffer);
			return (0);
		}
		exec_action(stacks, ac - 1, buffer);
		free(buffer);
		buffer = ft_calloc(5, 1);
	}
	free(buffer);
	return (1);
}

int	check_buffer(char *buffer)
{
	if (ft_strncmp("sa\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("sb\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("ss\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("pa\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("pb\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("ra\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("rb\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("rr\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("rra\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("rrb\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	if (ft_strncmp("rrr\n", buffer, ft_strlen(buffer)) == 0)
		return (0);
	return (1);
}

void	exec_action(t_stacks *stack, int ac, char *buffer)
{
	if (ft_strncmp("sa\n", buffer, ft_strlen(buffer)) == 0)
		ft_bsa(stack);
	if (ft_strncmp("sb\n", buffer, ft_strlen(buffer)) == 0)
		ft_bsb(stack);
	if (ft_strncmp("ss\n", buffer, ft_strlen(buffer)) == 0)
		ft_bss(stack);
	if (ft_strncmp("pa\n", buffer, ft_strlen(buffer)) == 0)
		ft_bpa(stack, ac, 0);
	if (ft_strncmp("pb\n", buffer, ft_strlen(buffer)) == 0)
		ft_bpb(stack, ac, 0);
	if (ft_strncmp("ra\n", buffer, ft_strlen(buffer)) == 0)
		ft_bra(stack, ac, 0);
	if (ft_strncmp("rb\n", buffer, ft_strlen(buffer)) == 0)
		ft_brb(stack, ac, 0);
	if (ft_strncmp("rr\n", buffer, ft_strlen(buffer)) == 0)
		ft_brr(stack, ac, 0);
	if (ft_strncmp("rra\n", buffer, ft_strlen(buffer)) == 0)
		ft_brra(stack, ac, 1);
	if (ft_strncmp("rrb\n", buffer, ft_strlen(buffer)) == 0)
		ft_brrb(stack, ac, 1);
	if (ft_strncmp("rrr\n", buffer, ft_strlen(buffer)) == 0)
		ft_brrr(stack, ac, 1);
}

int	bsb_check(t_stacks *stack, int ac)
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
