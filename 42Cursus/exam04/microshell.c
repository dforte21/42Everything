#include "header.h"

int main(int ac, char **av, char **envp)
{
	t_cmd cmd;
	int	j;

	cmd.stdoutcpy = dup(1);
	cmd.stdincpy = dup(0);
	ac = 0;
	for (int i = 1; av[i]; i = j)
	{
		while (av[i] && strcmp(av[i], ";") == 0)
			i++;
		if (!av[i])
			break ;
		cmd.flag = 0;
		for (j = i; av[j] && strcmp(av[j], ";") != 0; j++)
		{
			if (strcmp(av[j], "|") == 0)
				cmd.flag = 1;
		}
		if (cmd.flag == 1)
			ftpipe(&av[i], j - i, &cmd, envp);
		else
			ftcommand(&av[i], j - i, &cmd, envp);
	}
	close(cmd.stdoutcpy);
	close(cmd.stdincpy);
	return (0);
}

void	ftpipe(char **av, int j, t_cmd *cmd, char **envp)
{
	int i;
	int f;
	int	k = 0;

	for (i = 0; i < j; i = k)
	{
		while (i != j && strcmp(av[i], "|") == 0)
			i++;
		for (k = i; k < j && strcmp(av[k], "|") != 0; k++)
			;
		pipe(cmd->pipe);
		if (k != j)
			dup2(cmd->pipe[1], 1);
		else
			dup2(cmd->stdoutcpy, 1);
		close(cmd->pipe[1]);
		ftcommand(&av[i], k - i, cmd, envp);
		dup2(cmd->pipe[0], 0);
		close(cmd->pipe[0]);
		f = i;
	}
	dup2(cmd->stdincpy, 0);
}

void	ftcommand(char **av, int j, t_cmd *cmd, char **envp)
{
	int	pid;
	int i;

	for (i = 0; i < j; i++)
		cmd->cmd[i] = av[i];
	cmd->cmd[i] = NULL;
	if (strcmp(cmd->cmd[0], "cd") == 0)
		ftcd(cmd);
	else
	{
		pid = fork();
		if (pid == 0)
			if ((execve(av[0], cmd->cmd, envp)) == -1)
				error("error: cannot execute ", 1, cmd->cmd[0]);
		waitpid(-1, NULL, 0);
	}
}

void	ftcd(t_cmd *cmd)
{
	int r;

	if (!cmd->cmd[1] || cmd->cmd[2])
		error("error: cd: bad arguments\n", 0, NULL);
	if ((r = chdir(cmd->cmd[1])) == -1)
		error("error: cd: cannot change directory to ", 1, cmd->cmd[1]);
}

int ftstrlen(char *str)
{
	int	i = 0;

	while(str[i])
		i++;
	return (i);
}

void	error(char *str, int caller, char *arg)
{
	if (caller == 0)
	{
		write(STDERR_FILENO, str, ftstrlen(str));
		exit (1);
	}
	write(STDERR_FILENO, str, ftstrlen(str));
	write(STDERR_FILENO, arg, ftstrlen(arg));
	write(STDERR_FILENO, "\n", 1);
	exit (1);
}
