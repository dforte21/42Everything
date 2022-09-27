#include "minishell.h"

int	ftStrchr(char *str, char c, int start)
{
	int	i;

	i = start;
	while(str[i] != c && str[i])
		i++;
	return (i);
}

void	ftFree(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

void	ftExit(t_comms *comms)
{
	clear_history();
	close(comms->pipefd[0]);
	close(comms->pipefd[1]);
	printf("exit\n");
	exit (0);
}

void	ftStrReplace(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = '\n';
		i++;
	}
}
