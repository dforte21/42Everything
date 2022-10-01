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
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args[i]);
		free(args);
	}
}

void	ftExit(t_comms *comms)
{
	int	i;

	i = 0;
	clear_history();
	ftFree(comms->path);
	exit (0);
}

void	ftStrReplace(char *str, char old, char new)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
}
