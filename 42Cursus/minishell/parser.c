#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	int		j;
	int		exit;
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
		waitpid(pid, &exit, 0);
		check_status(exit, comms);
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
	clear_history();
	ftFree(comms->path);
	if (comms->exit == 1)
		exit(2);
	exit(g_exit_status);
}

void	check_status(int exit, t_comms *comms)
{
	if (WIFEXITED(exit))
	{
		if (WEXITSTATUS(exit) == 2)
		{
			comms->exit = 1;
			g_exit_status = 0;
		}
		else
			g_exit_status = WEXITSTATUS(exit);
	}
}
