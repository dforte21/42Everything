/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:04:49 by dforte            #+#    #+#             */
/*   Updated: 2022/05/18 14:49:00 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**mat;

	mat = loadmat(&ac, av);
	if (!init_stacks(&stacks, ac, mat) || !check_stack(stacks, ac - 1))
		return (error_message(&stacks, NULL, mat));
	if (stacks.alen == -1)
		return (error_message(&stacks, NULL, mat));
	if (!ft_read(&stacks))
		return (error_message(&stacks, NULL, mat));
	if (border_check(&stacks, ac -1) && stacks.blen == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stacks, NULL, mat);
}

int	ft_read(t_stacks *stacks)
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
		exec_action(stacks, buffer);
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

void	exec_action(t_stacks *stack, char *buffer)
{
	if (ft_strncmp("sa\n", buffer, ft_strlen(buffer)) == 0)
		ft_bsa(stack);
	if (ft_strncmp("sb\n", buffer, ft_strlen(buffer)) == 0)
		ft_bsb(stack);
	if (ft_strncmp("ss\n", buffer, ft_strlen(buffer)) == 0)
		ft_bss(stack);
	if (ft_strncmp("pa\n", buffer, ft_strlen(buffer)) == 0)
		ft_bpa(stack, stack->alen);
	if (ft_strncmp("pb\n", buffer, ft_strlen(buffer)) == 0)
		ft_bpb(stack, stack->blen);
	if (ft_strncmp("ra\n", buffer, ft_strlen(buffer)) == 0)
		ft_bra(stack, stack->alen);
	if (ft_strncmp("rb\n", buffer, ft_strlen(buffer)) == 0)
		ft_brb(stack, stack->blen);
	if (ft_strncmp("rr\n", buffer, ft_strlen(buffer)) == 0)
		ft_brr(stack);
	if (ft_strncmp("rra\n", buffer, ft_strlen(buffer)) == 0)
		ft_brra(stack, stack->alen);
	if (ft_strncmp("rrb\n", buffer, ft_strlen(buffer)) == 0)
		ft_brrb(stack, stack->blen);
	if (ft_strncmp("rrr\n", buffer, ft_strlen(buffer)) == 0)
		ft_brrr(stack);
}
