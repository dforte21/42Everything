/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:35:20 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 17:54:37 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ftfreepipe(t_comms *comms, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(comms->pipefd[i]);
		free(comms->redfd[i]);
		i++;
	}
	free(comms->pipefd);
	free(comms->redfd);
}

char	*ftremovechar(char *str, char c)
{
	char	**arg;
	char	*tmp;
	int		i;

	i = 1;
	arg = ft_split(str, c);
	tmp = ft_strdup(arg[0]);
	while (arg[i])
	{
		tmp = ft_strjoin(tmp, arg[i]);
		i++;
	}
	free(str);
	ftfree(arg);
	return (tmp);
}

int	**allocpipe(t_comms *comms)
{
	int	**fd;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (comms->pipes[j])
		j++;
	fd = malloc(sizeof(int *) * j);
	while (comms->pipes[i])
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	return (fd);
}

void	set_fd(t_comms *comms, int flag)
{
	if (flag == 0)
	{
		comms->stdincpy = dup(0);
		comms->stdoutcpy = dup(1);
	}
	else if (flag == 1)
	{
		dup2(comms->stdincpy, 0);
		dup2(comms->stdoutcpy, 1);
	}
	else if (flag == 2)
	{
		close(comms->stdincpy);
		close(comms->stdoutcpy);
	}
}

char	**getpath(char **envp)
{
	char	**path;
	char	*env;
	int		i;

	i = 0;
	env = fdgetenv("PATH", envp);
	if (!env)
		return (NULL);
	path = ft_split(env, ':');
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	free(env);
	return (path);
}
