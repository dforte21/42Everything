#include "minishell.h"

void	ftEnv(t_comms *comms, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s", envp[i]);
		printf("\n");
		i++;
	}
	printf("\b");
	g_exit_status = 0;
}
