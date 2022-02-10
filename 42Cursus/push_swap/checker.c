/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:04:49 by dforte            #+#    #+#             */
/*   Updated: 2022/02/10 18:59:57 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	
	if (!init_stacks(&stacks, ac, av) || !check_stack(stacks, ac - 1))
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_all(&stacks, NULL);
		return (0);
	}
	if (!ft_read(ac, stacks))
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_all(&stacks, NULL);
		return (0);
	}
}

int	ft_read(int ac, t_stacks stacks)
{
	char	*buffer;

	buffer = ft_calloc(5, 1);
	while (read(0, buffer, 4))
	{
		if(exec_act(ac, stacks, buffer))
			return (0);
		free(buffer);
		buffer = ft_calloc(5, 1);
	}
	free(buffer);
	return (1);
}

int	exec_act(int ac, t_stacks stacks, char *buffer)
{
	if (ft_strncmp("sa\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("sa\n");
	if (ft_strncmp("sb\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("sb\n");
	if (ft_strncmp("ss\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("ss\n");
	if (ft_strncmp("pa\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("pa\n");
	if (ft_strncmp("pb\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("pb\n");
	if (ft_strncmp("ra\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("ra\n");
	if (ft_strncmp("rb\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("rb\n");
	if (ft_strncmp("rr\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("rr\n");
	if (ft_strncmp("rra\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("rra\n");
	if (ft_strncmp("rrb\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("rrb\n");
	if (ft_strncmp("rrr\n", buffer, ft_strlen(buffer)) == 0)
		ft_printf("rrr\n");
	return (0);
}
