#include "minishell.h"

void	ftParser(char *line)
{
	char	**args;

	args = newSplit(line);
	//for (int i = 0; args[i]; i++)
	//	printf("%s\n", args[i]);
	if (ft_strncmp(args[0], "exit", ft_strlen(args[0])) == 0)
		ftExit(args, line);
	else if (ft_strncmp(args[0], "echo", ft_strlen(args[0])) == 0)
		ftEcho(args);
	else
		ftError(args[0]);
	add_history(line);
	ftFree(args, line);
}

void	ftError(char *arg)
{
	printf("Minishell: %s: command not found\n", arg);
	g_exit_status = 127;
}
