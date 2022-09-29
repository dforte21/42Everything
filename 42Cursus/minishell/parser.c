#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	int		i;
	char	*line;

	i = 0;
	if (pipe(comms->pipefd) == -1)
		return ;
	exeCommand(comms, envp);
}
