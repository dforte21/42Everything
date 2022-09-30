#include "minishell.h"

int	ftExecve (t_comms *comms, char **envp)
{
	int		i;
	int		r;
	char	*path;

	i = 0;
	while (comms->path[i])
	{
		comms->path[i] = ft_strjoin(comms->path[i], comms->cargs[0]);
		r = access(comms->path[i], R_OK);
		path = ft_strdup(comms->path[i]);
		comms->path[i] = ft_strtrim(comms->path[i], comms->cargs[0]);
		if (r == 0)
			break;
		else
			i++;
		free(path);
		if (!comms->path[i])
		{
			printf("\b");
			return (1);
		}
	}
	r = exeFork(comms, envp, path);
	free(path);
	return (r);
}

int	exeFork(t_comms *comms, char **envp, char *path)
{
	char	*line;
	char	*output;
	pid_t	pid;


	pid = fork();
	if (pid == 0)
	{
		if(execve(path, comms->cargs, envp) == -1)
			return (1);
	}
	waitpid(pid, NULL, 0);
	printf("\b");
	return (0);
}
