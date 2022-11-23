/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:19:51 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 18:00:18 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ftexecve(t_comms *comms, char **envp)
{
	int			r;
	int			i;
	char		*path;
	struct stat	filestat;

	r = stat(comms->cargs[0], &filestat);
	comms->path = getpath(envp);
	if (checkdir(comms, filestat, r) == 126)
		return (126);
	i = ftstrchr(comms->cargs[0], '/', 0);
	if (comms->cargs[0][i])
	{
		path = ft_strdup(comms->cargs[0]);
		r = access(path, R_OK);
	}
	else
		path = buildpath(comms);
	ftfree(comms->path);
	if (!path)
		return (fterror(comms->cargs, 3, 0));
	r = exefork(comms, envp, path);
	free(path);
	return (r);
}

int	checkdir(t_comms *comms, struct stat filestat, int r)
{
	if (S_ISDIR(filestat.st_mode) && r == 0)
	{
		errno = EISDIR;
		fterror(comms->cargs, 2, 0);
		return (126);
	}
	return (1);
}

int	exefork(t_comms *comms, char **envp, char *path)
{
	int		status;
	pid_t	pid;

	signal(SIGINT, ft_quit130);
	signal(SIGQUIT, ft_quit131);
	pid = fork();
	if (pid == 0)
	{
		execve(path, comms->cargs, envp);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
		{
			errno = WEXITSTATUS(status);
			return (1);
		}
	}
	if (g_exit_status == 130)
		return (130);
	return (0);
}

char	*buildpath(t_comms *comms)
{
	char	*path;
	int		r;
	int		i;

	i = 0;
	if (!comms->path)
		return (NULL);
	while (comms->path[i])
	{
		comms->path[i] = ft_strjoin(comms->path[i], comms->cargs[0]);
		r = access(comms->path[i], R_OK);
		path = ft_strdup(comms->path[i]);
		comms->path[i] = ft_strtrim(comms->path[i], comms->cargs[0]);
		if (r == 0)
			return (path);
		i++;
		free(path);
		if (!comms->path[i])
			return (NULL);
	}
	return (NULL);
}
