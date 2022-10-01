#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	int		j;
	pid_t	pid;

	j = 0;
	while (comms->pipes[j])
		j++;
	comms->pipefd = malloc(sizeof(int *) * j);
	i = 0;
	while (comms->pipes[i])
	{
		comms->pipefd[i] = malloc(sizeof(int) * 2);
		pipe(comms->pipefd[i]);
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i);
		waitpid(pid, NULL, 0);
		if (comms->pipes[i + 1])
			close(comms->pipefd[i][1]);
		i++;
	}
	ftFreePipe(comms, j);
	add_history(comms->line);
}

void	childExecute(t_comms *comms, char **envp, int i)
{
	if (comms->pipes[i + 1])
		dup2(comms->pipefd[i][1], 1);
	if (i > 0)
		dup2(comms->pipefd[i - 1][0], 0);
	exeCommand(comms, envp, i);
	free(comms->line);
	ftFree(comms->pipes);
	ftExit(comms);
}
