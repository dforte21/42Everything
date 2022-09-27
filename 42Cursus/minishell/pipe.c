#include "minishell.h"

void	writePipe(char *args, int pipefd)
{
	write (pipefd, args, ft_strlen(args));
}

char	*readPipe(int pipefd)
{
	char	*line;

	line = get_next_line(pipefd);
	return (line);
}
