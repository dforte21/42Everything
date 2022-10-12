#include "minishell.h"

void	exeCommand(t_comms *comms, char **envp, int i)
{
	comms->pipes[i] = ft_strtrim(comms->pipes[i], " ");
	comms->cargs = ft_split(comms->pipes[i], ' ');
	if (ft_strncmp(comms->cargs[0], "exit", 5) == 0)
	{
		g_exit_status = 0;
		comms->exit = 1;
	}
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
	free(line);
	return (1);
}
