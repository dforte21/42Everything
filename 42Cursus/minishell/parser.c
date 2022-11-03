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
		pid = chooseCommand(comms, envp, i, j);
		i++;
	}
	i = 0;
	waitpid(pid, &status, 0);
	while (comms->pipes[i + 1])
	{
		waitpid(-1, &status, 0);
		i++;
	}
	check_status(status);
	set_fd(comms, 1);
	set_fd(comms, 2);
	ftFreePipe(comms, j);
	free(comms->cmd);
}

pid_t	chooseCommand(t_comms *comms, char **envp, int i, int j)
{
	int		fd[3];
	pid_t	pid;

	pid = 0;
	fd[0] = -1;
	fd[1] = -1;
	fd[2] = -1;
	if (ft_redirection(comms->pipes[i], fd, 0) == -1)
	{
		g_exit_status = 1;
		return (pid);
	}
	if (!comms->pipes[1])
		exeCommand(comms, envp, i, fd);
	else
	{
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i, fd);
		if (checkHD(comms->pipes[i + 1]) == 0)
			dup2(comms->pipefd[i][0], STDIN_FILENO);
	}
	close(comms->pipefd[i][0]);
	close(comms->pipefd[i][1]);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	return (pid);
}

void	childExecute(t_comms *comms, char **envp, int i, int *fd)
{
	if (i > 0)
		g_exit_status = 0;
	close(comms->pipefd[i][0]);
	if (comms->pipes[i + 1] && fd[1] == -1)
		dup2(comms->pipefd[i][1], STDOUT_FILENO);
	else if (fd[1] == -1 && !comms->pipes[i + 1])
		dup2(comms->stdoutcpy, STDOUT_FILENO);
	close(comms->pipefd[i][1]);
	exeCommand(comms, envp, i, fd);
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
