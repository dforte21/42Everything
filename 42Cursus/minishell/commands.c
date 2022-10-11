#include "minishell.h"

void	exeCommand(t_comms *comms, char **envp, int i)
{
	comms->pipes[i] = ft_strtrim(comms->pipes[i], " ");
	comms->cargs = ft_split(comms->pipes[i], ' ');
	if (ft_strncmp(comms->cargs[0], "exit", 5) == 0)
		comms->exit = 1;
	else if (ft_strncmp(comms->cargs[0], "echo", 5) == 0)
		ftEcho(comms);
	else if (ft_strncmp(comms->cargs[0], "env", 4) == 0)
		ftEnv(comms, envp);
	else if (ft_strncmp(comms->cargs[0], "export", 7) == 0)
		ftExport(comms, envp, 0, 0);
	else if (ft_strncmp(comms->cargs[0], "unset", 6) == 0)
		ftUnset(comms, envp);
	else if (ft_strncmp(comms->cargs[0], "cd", 3) == 0)
		ftCd(comms);
	else if (ft_strncmp(comms->cargs[0], "pwd", 4) == 0)
		ftPwd(comms);
	else
	{
		if (ftExecve(comms, envp) == 1)
			ftError(comms->cargs[0]);	
	}
	ftFree(comms->cargs);
}

void	ftError(char *arg)
{
	perror(arg);
	strerror(errno);
	g_exit_status = 127;
}
