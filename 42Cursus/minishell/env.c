#include "minishell.h"

void	ftEnv(t_comms *comms, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		writePipe(envp[i], comms->pipefd[1]);
		writePipe("\a", comms->pipefd[1]);
		i++;
	}
	writePipe("\b", comms->pipefd[1]);
	g_exit_status = 0;
}
