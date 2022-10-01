#include "minishell.h"

void	ftPwd(t_comms *comms)
{
	char	line[1000];

	getcwd(line, 1000);
	printf("%s\n\b", line);
}

void	ftCd(t_comms *comms)
{
	int	r;

	r = chdir(comms->cargs[1]);
	printf("\b");
}
