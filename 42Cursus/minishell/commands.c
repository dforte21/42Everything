#include "minishell.h"

void	exeCommand(t_comms *comms, char **envp, int i)
{
	set_fd(comms, 0);
	comms->cargs = ft_smart_split(comms->pipes[i], ' ');
	comms->cargs = ft_remove_quotes(comms->cargs);
	if (ft_strncmp(comms->cargs[0], "exit", 5) == 0)
		g_exit_status = ft_exit(comms);
	else if (ft_strncmp(comms->cargs[0], "cd", 3) == 0)
		g_exit_status = ftCd(comms);
	else if (ft_strncmp(comms->cargs[0], "export", 7) == 0)
		g_exit_status = ftExport(comms, envp, 0, 0);
	else if (ft_strncmp(comms->cargs[0], "unset", 6) == 0)
		g_exit_status = ftUnset(comms, envp);
	else if (ft_strncmp(comms->cargs[0], "echo", 5) == 0)
		g_exit_status = ftEcho(comms);
	else if (ft_strncmp(comms->cargs[0], "env", 4) == 0)
		g_exit_status = ftEnv(comms, envp);
	else if (ft_strncmp(comms->cargs[0], "pwd", 4) == 0)
		g_exit_status = ftPwd(comms);
	else
		g_exit_status = ftExecve(comms, envp);
	ftFree(comms->cargs);
	set_fd(comms, 1);
	set_fd(comms, 2);
}

int	ftError(char **arg, int caller, int i)
{
	char	*line;

	line = ft_strdup("Minishell: ");
	line = ft_strjoin(line, arg[0]);
	if (caller == 1)
	{
		line = ft_strjoin(line, ": `");
		line = ft_strjoin(line, arg[i]);
		line = ft_strjoin(line, "': not a valid identifier\n");
		write(STDERR_FILENO, line, ft_strlen(line));
	}
	if (caller == 2)
	{
		perror(line);
	}
	if (caller == 3)
	{
		line = ft_strjoin(line, ": command not found\n");
		write(STDERR_FILENO, line, ft_strlen(line));
		free(line);
		return (127);
	}
	if (caller == 4)
	{
		line = ft_strjoin(line, ": ");
		line = ft_strjoin(line, arg[i]);
		line = ft_strjoin(line, ": numeric argument required\n");
		write(STDERR_FILENO, line, ft_strlen(line));
		return (255);
	}
	free(line);
	return (1);
}

int	ft_exit(t_comms *comms)
{
	int	i;

	i = 0;
	comms->exit = 1;
	if (!comms->pipes[1])
		printf("exit\n");
	if (!comms->cargs[1])
		return (0);
	while (comms->cargs[1][i])
	{
		if (!ft_isdigit(comms->cargs[1][i]))
			return (ftError(comms->cargs, 4, 1));
		i++;
	}
	return (ft_atoi(comms->cargs[1]));
}
