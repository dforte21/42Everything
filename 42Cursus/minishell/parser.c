#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	int		j;
	pid_t	pid;

	
	i = 0;
	j = 0;
	while (comms->pipes[j])
		j++;
	while (comms->pipes[i])
	{
		pipe(comms->pipefd[i]);
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i, j);
		waitpid(pid, NULL, 0);
		close(comms->pipefd[i][1]);
		i++;
	}
	ftFreePipe(comms, j);
	add_history(comms->line);
}

void	childExecute(t_comms *comms, char **envp, int i, int j)
{
	if (comms->pipes[i + 1])
		dup2(comms->pipefd[i][1], 1);
	if (i > 0)
		dup2(comms->pipefd[i - 1][0], 0);
	exeCommand(comms, envp, i);
	free(comms->line);
	ftFree(comms->pipes);
	ftFreePipe(comms, j);
	ftExit(comms);
}
