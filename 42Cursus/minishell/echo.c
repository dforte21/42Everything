#include "minishell.h"

int	ftEcho(t_comms *comms)
{
	int	i;

	i = 1;
	while (comms->cargs[i] && ft_strncmp(comms->cargs[i], "-n", 3) == 0)
		i++;
	while (comms->cargs[i])
	{
		printf("%s", comms->cargs[i]);
		if (comms->cargs[i + 1])
			printf(" ");
		i++;
	}
	if (!comms->cargs[1] || ft_strncmp(comms->cargs[1], "-n", 3) != 0)
		printf("\n");
	return (0);
}
