/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:33:05 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 18:04:19 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ftunset(t_comms *comms, char **envp, int i)
{
	int	j;

	while (comms->cargs[i])
	{
		if (checkinput(comms->cargs[1]))
			return (fterror(comms->cargs, 1, i));
		j = findenv(comms->cargs[i], envp);
		if (j == -1)
		{
			i++;
			continue ;
		}
		if (delenv(comms, envp[j]))
			free(envp[j]);
		envp[j] = NULL;
		while (envp[j + 1])
		{
			envp[j] = envp[j + 1];
			envp[j + 1] = NULL;
			j++;
		}
		i++;
	}
	comms->lenv--;
	return (0);
}

int	checkenv(char *arg, char **envp, t_comms *comms)
{
	int	i;
	int	j;

	i = 0;
	i = findenv(arg, envp);
	if (i == -1)
		return (0);
	j = ftstrchr(arg, '=', 0);
	if (!arg[j])
		return (-1);
	if (delenv(comms, envp[i]))
		free(envp[i]);
	envp[i] = NULL;
	return (1);
}

int	findenv(char *arg, char **envp)
{
	int	i;
	int	j;

	i = ftstrchr(arg, '=', 0);
	j = 0;
	while (envp[j])
	{
		if (ft_strncmp(arg, envp[j], i + 1) == 0)
			return (j);
		if (ft_strncmp(arg, envp[j], i) == 0
			&& (envp[j][i] == '=' || !envp[j][i]))
			return (j);
		j++;
	}
	return (-1);
}

int	checkinput(char *arg)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (arg[0] == '=')
		return (1);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]))
			return (1);
		if (ft_isalpha(arg[i]))
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (1);
	return (0);
}
