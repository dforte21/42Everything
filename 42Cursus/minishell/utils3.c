#include "minishell.h"

void	newEnv(t_comms *comms, char *env)
{
	int	i;

	i = 0;
	while (i < 100 && comms->newenvcp[i])
		i++;
	if (i == 100)
	{
		free(comms->newenvcp[99]);
		i--;
	}
	comms->newenvcp[i] = ft_strdup(env);
}

int	delEnv(t_comms *comms, char *env)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		if (comms->newenvcp[i] && ft_strncmp(env, comms->newenvcp[i], sizeof(comms->newenvcp[i]) + 1) == 0)
		{
			free(comms->newenvcp[i]);
			comms->newenvcp[i] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}
