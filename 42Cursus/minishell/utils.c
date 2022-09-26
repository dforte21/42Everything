#include "minishell.h"

int	ftStrchr(char *str, char c, int start)
{
	int	i;

	i = start;
	while(str[i] != c && str[i])
		i++;
	return (i);
}

void	ftFree(char **args, char *line)
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
	free(line);
}

void	ftExit(char **args, char *line)
{
	ftFree(args, line);
	clear_history();
	printf("exit\n");
	exit (0);
}

void	ftExitStatus(void)
{
	printf("%d\n", g_exit_status);
}
