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
			return (1);
	}
	exeFork(comms, envp, path);
	free(path);
	return (0);
}

void	exeFork(t_comms *comms, char **envp, char *path)
{
	int		fd[2];
	char	*line;
	char	*output;
	pid_t	pid;


	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		execve(path, comms->cargs, envp);
	}
	waitpid(pid, NULL, 0);
	writePipe("\b", fd[1]);
	line = get_next_line(fd[0]);
	output = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd[0]);
		if (line)
			output = ft_strjoin(output, line);
	}
	ftStrReplace(output, '\n', '\a');
	writePipe(output, comms->pipefd[1]);
	writePipe("\b", comms->pipefd[1]);
	free(output);
	close(fd[0]);
	close(fd[1]);
}
