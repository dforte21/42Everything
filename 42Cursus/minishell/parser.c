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

	comms->pipes[i] = ft_strtrim(comms->pipes[i], " ");
	comms->cargs = ft_split(comms->pipes[i], ' ');
	if (ft_strncmp(comms->cargs[0], "cd", 3) == 0 && !comms->pipes[1])
		g_exit_status = ftCd(comms);
	else if (ft_strncmp(comms->cargs[0], "export", 7) == 0 && comms->cargs[1] && !comms->pipes[1])
		g_exit_status = ftExport(comms, envp, 0, 0);
	else if (ft_strncmp(comms->cargs[0], "unset", 6) == 0 && !comms->pipes[1])
		g_exit_status = ftUnset(comms, envp);
	else
	{
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i, j);
		waitpid(pid, &status, 0);
		check_status(status, comms);
	}
	ftFree(comms->cargs);
}

void	childExecute(t_comms *comms, char **envp, int i, int j)
{
	if (comms->pipes[i + 1])
		dup2(comms->pipefd[i][1], 1);
	if (i > 0)
		dup2(comms->pipefd[i - 1][0], 0);
	exeCommand(comms, envp, i);
	free(comms->line);
	ftFree(comms->cargs);
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
