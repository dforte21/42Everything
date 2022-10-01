#include "minishell.h"

void	ftFreePipe(t_comms *comms, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		close(comms->pipefd[i][0]);
		if (i == j - 1)
			close(comms->pipefd[i][1]);
		free(comms->pipefd[i]);
		i++;
	}
	free(comms->pipefd);
}
