#include "minishell.h"

void	outRedirection(char *cmd, int *fd, char **path)
{
	if (ft_strncmp(cmd, ">>", 2) == 0)
	{
		if (fd[1] != -1)
			close(fd[1]);
		fd[1] = open(path[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else if(cmd[0] == '>' && cmd[1] != '>')
	{
		if (fd[1] != -1)
			close(fd[1]);
		fd[1] = open(path[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
}

int	inRedirection()
{}
