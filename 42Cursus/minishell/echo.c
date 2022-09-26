#include "minishell.h"

void	ftEcho(char **args)
{
	int	i;

	i = 1;
	if (args[i] && ft_strncmp(args[i], "-n", ft_strlen(args[i])) == 0)
	{
		i++;
		while (args[i])
		{
			printf("%s", args[i]);
			if (args[i + 1])
				printf(" ");
			i++;
		}
	}
	else
	{
		while (args[i])
		{
			printf("%s ", args[i]);
			i++;
		}
		printf("\n");
	}
}
