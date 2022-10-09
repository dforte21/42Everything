#include "minishell.h"

void	ftEcho(t_comms *comms)
{
	int	i;

	i = 1;
	if (comms->cargs[i] && ft_strncmp(comms->cargs[i], "-n", ft_strlen(comms->cargs[i])) == 0)
		i++;
	while (comms->cargs[i])
	{
		printf("%s", comms->cargs[i]);
		if (comms->cargs[i + 1])
			printf(" ");
		i++;
	}
	if (!comms->cargs[1] || ft_strncmp(comms->cargs[1], "-n", ft_strlen(comms->cargs[1])) != 0)
		printf("\n");
	g_exit_status = 0;
}
