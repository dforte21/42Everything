#include "minishell.h"

int	getFd(t_comms *comms, int i)
{
	if (comms->pipes[i + 1])
		return (dup(comms->pipefd[1]));
	return (dup(1));
}
