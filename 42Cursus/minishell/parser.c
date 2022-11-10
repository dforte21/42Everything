/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:28:41 by dforte            #+#    #+#             */
/*   Updated: 2022/11/10 16:23:58 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		ft_redirection(comms->pipes[j], comms->redfd[j], 0);
		j++;
	}
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
		waitpid(-1, NULL, 0);
		i++;
	}
	check_status(status);
	set_fd(comms, 1);
	set_fd(comms, 2);
	ftFreePipe(comms, j);
}

pid_t	chooseCommand(t_comms *comms, char **envp, int i, int j)
{
	pid_t	pid;

	pid = 0;
	if (!comms->pipes[1])
		exeCommand(comms, envp, i);
	else
	{
		pid = fork();
		if (pid == 0)
			childExecute(comms, envp, i);
		if (checkHD(comms->pipes[i + 1]) == 0)
			dup2(comms->pipefd[i][0], STDIN_FILENO);
	}
	close(comms->pipefd[i][0]);
	close(comms->pipefd[i][1]);
	if (comms->redfd[i][0] != -1)
		close(comms->redfd[i][0]);
	if (comms->redfd[i][1] != -1)
		close(comms->redfd[i][1]);
	return (pid);
}

void	childExecute(t_comms *comms, char **envp, int i)
{
	if (i > 0)
		g_exit_status = 0;
	close(comms->pipefd[i][0]);
	if (comms->pipes[i + 1] && comms->redfd[i][1] == -1)
		dup2(comms->pipefd[i][1], STDOUT_FILENO);
	else if (comms->redfd[i][1] == -1 && !comms->pipes[i + 1])
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
