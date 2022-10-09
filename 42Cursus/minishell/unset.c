#include "minishell.h"

void	ftUnset(t_comms *comms, char **envp)
{
	int	i;
	int	j;

	i = 1;
	while (comms->cargs[i])
	{
		j = findEnv(comms->cargs[i], envp);
		if (j == -1)
			continue ;
		free(envp[j]);
		envp[j] = NULL;
		while (envp[j + 1])
		{
			envp[j] = envp[j + 1];
			envp[j + 1] = NULL;
			j++;
		}
		i++;
	}
	comms->lenv--;
	g_exit_status = 0;
}

int	checkEnv(char *arg, char **envp)
{
	int	i;
	int	j;

	i = 0;
	i = findEnv(arg, envp);
	if (i == -1)
		return (0);
	j = ftStrchr(arg, '=', 0);
	if (!arg[j])
		return (-1);
	free(envp[i]);
	envp[i] = NULL;
	return (1);
}

int	findEnv(char *arg, char **envp)
{
	int	i;
	int	j;

	i = ftStrchr(arg, '=', 0);
	j = 0;
	while (envp[j])
	{
		if (ft_strncmp(arg, envp[j], i + 1) == 0)
			return (j);
		if (ft_strncmp(arg, envp[j], i) == 0 && envp[j][i] == '=')
			return (j);
		j++;
	}
	return (-1);
}
