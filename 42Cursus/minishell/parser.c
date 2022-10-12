#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (comms->pipes[j])
		j++;
	while (comms->pipes[i])
	{
		pipe(comms->pipefd[i]);
		chooseCommand(comms, envp, i, j);
		close(comms->pipefd[i][1]);
		i++;
	}
	ftFreePipe(comms, j);
	add_history(comms->line);
}

void	chooseCommand(t_comms *comms, char **envp, int i, int j)
{
	int		status;
	pid_t	pid;

	if (!comms->pipes[1])
		exeCommand(comms, envp, i);
	else
	{
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i, j);
		waitpid(pid, &status, 0);
		check_status(status, comms, i);
	}
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
	clear_history();
	ftFree(comms->path);
	exit(g_exit_status);
}

void	check_status(int exit, t_comms *comms, int i)
{
	if (WIFEXITED(exit) && !comms->pipes[i + 1])
		g_exit_status = WEXITSTATUS(exit);
}
