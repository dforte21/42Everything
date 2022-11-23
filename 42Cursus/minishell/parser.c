/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:26:44 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 18:14:24 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ftparser(t_comms *comms, char **envp)
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
		pid = choosecommand(comms, envp, i, j);
		i++;
	}
	checksons(pid, comms, status, j);
}

void	checksons(pid_t pid, t_comms *comms, int status, int j)
{
	int	i;

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
	ftfreepipe(comms, j);
}

pid_t	choosecommand(t_comms *comms, char **envp, int i, int j)
{
	pid_t	pid;

	pid = 0;
	if (!comms->pipes[1])
		execommand(comms, envp, i);
	else
	{
		pid = fork();
		if (pid == 0)
			childexecute(comms, envp, i);
		if (checkhd(comms->pipes[i + 1]) == 0)
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

void	childexecute(t_comms *comms, char **envp, int i)
{
	if (i > 0)
		g_exit_status = 0;
	close(comms->pipefd[i][0]);
	if (comms->pipes[i + 1] && comms->redfd[i][1] == -1)
		dup2(comms->pipefd[i][1], STDOUT_FILENO);
	else if (comms->redfd[i][1] == -1 && !comms->pipes[i + 1])
		dup2(comms->stdoutcpy, STDOUT_FILENO);
	close(comms->pipefd[i][1]);
	execommand(comms, envp, i);
	free(comms->line);
	ftfree(comms->pipes);
	clear_history();
	exit(g_exit_status);
}

void	check_status(int exit)
{
	if (WIFEXITED(exit))
		g_exit_status = WEXITSTATUS(exit);
}
