#include "minishell.h"

int	ftExecve (t_comms *comms, char **envp)
{
	int		r;
	char	*path;

	path = ft_strdup(comms->cargs[0]);
	r = access(path, R_OK);
	if (r == -1)
	{
		free(path);
		path = buildPath(comms);
	}
	if (!path)
		return (ftError(comms->cargs, 3, 0));
	r = exeFork(comms, envp, path);
	free(path);
	return (r);
}

int	exeFork(t_comms *comms, char **envp, char *path)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if(execve(path, comms->cargs, envp) == -1)
			exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			errno = WEXITSTATUS(status);
			return (1);
	}
	return (0);
}

char	*buildPath(t_comms *comms)
{
	char	*path;
	int		r;
	int		i;

	i = 0;
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
