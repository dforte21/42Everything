#include "minishell.h"

void	ftEcho(char **args)
{
	int	i;

	i = 1;
	if (args[i] && ft_strncmp(args[i], "-n", ft_strlen(args[i])) == 0)
		i++;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (ft_strncmp(args[1], "-n", ft_strlen(args[1])) != 0)
		printf("\n");
	g_exit_status = 0;
}
