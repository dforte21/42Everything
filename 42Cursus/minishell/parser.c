#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	int		outfd;
	char	*line;
	pid_t	pid;

	i = 0;
	pipe(comms->pipefd);
	while (comms->pipes[i])
	{
		outfd = getFd(comms, i);
		pid = fork();
		if (pid == 0)
		{
			dup2(outfd, 1);
			exeCommand(comms, envp, i);
			close(outfd);
			free(comms->line);
			ftFree(comms->pipes);
			ftExit(comms);
		}
		waitpid(pid, NULL, 0);
		close(outfd);
		i++;
	}
	add_history(comms->line);
}
