#include "header.h"

int main(int ac, char **av, char **envp)
{
	t_cmd cmd;
	int i;
	int j;

	cmd.incpy = dup(0);
	cmd.outcpy = dup(1);
	ac = 0;
	for (i = 1; av[i]; i = j)
	{
		cmd.flag = 0;
		while (av[i] && strcmp(av[i], ";") == 0)
			i++;
		if (!av[i])
			break ;
		for (j = i; av[j] && strcmp(av[j], ";") != 0; j++)
			if (strcmp(av[j], "|") == 0)
				cmd.flag = 1;
		if (cmd.flag == 0)
			command(&av[i], j - i, envp, &cmd);
		else
			fpipe(&av[i], j - i, envp, &cmd);
	}
	close(cmd.incpy);
	close(cmd.outcpy);
	return (0);
}

void	fpipe(char **av, int j, char **envp, t_cmd *cmd)
{
	int i, k;
	for (i = 0; i < j; i = k)
	{
		while (strcmp(av[i], "|") == 0)
			i++;
		for (k = i; k < j && strcmp(av[k], "|") != 0; k++)
			;
		pipe(cmd->fd);
		if (k < j)
			dup2(cmd->fd[1], 1);
		else
			dup2(cmd->outcpy, 1);
		close(cmd->fd[1]);
		command(&av[i], k - i, envp, cmd);
		dup2(cmd->fd[0], 0);
		close(cmd->fd[0]);
	}
	dup2(cmd->incpy, 0);
}

void	command(char **av, int j, char **envp, t_cmd *cmd)
{
	int pid, i;
	for (i = 0; i < j; i++)
		cmd->cmd[i] = av[i];
	cmd->cmd[i] = NULL;
	if (strcmp(av[0], "cd") == 0)
	{
		ftcd(cmd);
		return ;
	}
	pid = fork();
	if (!pid)
	{
		execve(av[0], cmd->cmd, envp);
		error(1, "error: cannot execute ", cmd->cmd[0]);
		exit (0);
	}
	waitpid(pid, NULL, 0);
}

void	ftcd(t_cmd *cmd)
{
	if (!cmd->cmd[1] || cmd->cmd[2])
	{
		error(0, "error: cd: bad arguments\n", NULL);
		return ;
	}
	if (chdir(cmd->cmd[1]) == -1)
		error(1, "error: cd: cannot change directory to ", cmd->cmd[1]);
}

void	error(int caller, char *str, char *arg)
{
	if (caller == 0)
	{
		write (2, str, ftlen(str));
		return ;
	}
	write (2, str, ftlen(str));
	write (2, arg, ftlen(arg));
	write (2, "\n", 1);
}

int ftlen(char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		;
	return (i);
}