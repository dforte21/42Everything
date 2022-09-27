#include "minishell.h"

void	ftEcho(t_comms *comms)
{
	int	i;

	i = 1;
	if (comms->cargs[i] && ft_strncmp(comms->cargs[i], "-n", ft_strlen(comms->cargs[i])) == 0)
		i++;
	while (comms->cargs[i])
	{
		writePipe(comms->cargs[i], comms->pipefd[1]);
		if (comms->cargs[i + 1])
			writePipe(" ", comms->pipefd[1]);
		i++;
	}
	if (ft_strncmp(comms->cargs[1], "-n", ft_strlen(comms->cargs[1])) != 0)
		writePipe("\a", comms->pipefd[1]);
	writePipe("\b", comms->pipefd[1]);
	g_exit_status = 0;
}
