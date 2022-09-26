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
		ft_printf("Minishell: %s: command not found\n", args[0]);
	add_history(line);
	ftFree(args, line);
}