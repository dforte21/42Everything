#include "minishell.h"

void	exeCommand(t_comms *comms, char **envp)
{
	comms->cargs = newSplit(comms->line);
	//for (int i = 0; args[i]; i++)
	//	printf("%s\n", args[i]);
	if (ft_strncmp(comms->cargs[0], "exit", 5) == 0)
		comms->exit = 1;
	else if (ft_strncmp(comms->cargs[0], "echo", 5) == 0)
		ftEcho(comms);
	else if (ft_strncmp(comms->cargs[0], "env", 4) == 0)
		ftEnv(comms, envp);
	else
		ftError(comms->cargs[0], comms->pipefd[1]);
	add_history(comms->line);
	ftFree(comms->cargs);
}

void	ftError(char *arg, int pipefd)
{
	printf("Minishell: %s: command not found\n", arg);
	g_exit_status = 127;
}
