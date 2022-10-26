#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	int		j;
	int		status;
	pid_t	pid;
	
	i = 0;
	j = 0;
	while (comms->pipes[j])
		j++;
	set_fd(comms, 0);
	while (comms->pipes[i])
	{
		pipe(comms->pipefd[i]);
		chooseCommand(comms, envp, i, j);
		i++;
	}
	i = 0;
	while (comms->pipes[i])
	{
		waitpid(-1, &status, 0);
		i++;
	}
	check_status(status);
	set_fd(comms, 1);
	set_fd(comms, 2);
	ftFreePipe(comms, j);
	add_history(comms->line);
}

void	chooseCommand(t_comms *comms, char **envp, int i, int j)
{
	int		fd[2];
	pid_t	pid;

	ft_redirection(comms->pipes[i], &fd);
	if (!comms->pipes[1])
		exeCommand(comms, envp, i);
	else
	{
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i, j);
		dup2(comms->pipefd[i][0], STDIN_FILENO);
	}
	close(comms->pipefd[i][0]);
	close(comms->pipefd[i][1]);
}

void	childExecute(t_comms *comms, char **envp, int i, int j)
{
	close(comms->pipefd[i][0]);
	if (comms->pipes[i + 1])
		dup2(comms->pipefd[i][1], STDOUT_FILENO);
	else
		dup2(comms->stdoutcpy, STDOUT_FILENO);
	close(comms->pipefd[i][1]);
	exeCommand(comms, envp, i);
	free(comms->line);
	ftFree(comms->pipes);
	clear_history();
	ftFree(comms->path);
	exit(g_exit_status);
}

void	check_status(int exit)
{
	if (WIFEXITED(exit))
		g_exit_status = WEXITSTATUS(exit);
}
