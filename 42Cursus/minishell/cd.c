#include "minishell.h"

int	ftPwd(t_comms *comms)
{
	char	line[1000];

	getcwd(line, 1000);
	printf("%s\n", line);
	return (0);
}

int	ftCd(t_comms *comms)
{
	int		r;
	char	*home;

	if (!comms->cargs[1])
	{
		home = getenv("HOME");
		r = chdir(home);
	}
	else
		r = chdir(comms->cargs[1]);
	if (r == -1)
		return (ftError(comms->cargs, 2, 1));
	return (0);
}
