/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:34:05 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 18:12:49 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_skip_quotes(char *str, int i, char c)
{
	if (i == -1)
		return (i);
	if (str[i] == c)
	{
		i++;
		while (str[i] != c && str[i])
			i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ftstrchr(char *str, char c, int start)
{
	int	i;

	i = start;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

void	ftfree(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	ftexit(t_comms *comms)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (comms->nep[i])
			free(comms->nep[i]);
		i++;
	}
	free(comms->nep);
	clear_history();
	exit (g_exit_status);
}

void	ftstrreplace(char *str, char old, char new)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
}
