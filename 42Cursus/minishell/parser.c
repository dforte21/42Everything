#include "minishell.h"

void	ftParser(t_comms *comms, char **envp)
{
	char	*line;

	if (pipe(comms->pipefd) == -1)
		return ;
	exeCommand(comms, envp);
	if (comms->exit != 1 && g_exit_status != 127)
	{
		line = readPipe(comms->pipefd[0]);
		if (line)
		{
			ftStrReplace(line, '\a');
			printf("%s", line);
			free(line);
		}
	}
}
