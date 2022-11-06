#include "minishell.h"

int	ftUnset(t_comms *comms, char **envp, int i)
{
	int	j;

	while (comms->cargs[i])
	{
		if (checkInput(comms->cargs[1]))
			return (ftError(comms->cargs, 1, i));
		j = findEnv(comms->cargs[i], envp);
		if (j == -1)
		{
			i++;
			continue ;
		}
		if (delEnv(comms, envp[j]))
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
	return (0);
}

int	checkEnv(char *arg, char **envp, t_comms *comms)
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
	if (delEnv(comms, envp[i]))
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
		if (ft_strncmp(arg, envp[j], i) == 0 && (envp[j][i] == '=' || !envp[j][i]))
			return (j);
		j++;
	}
	return (-1);
}

int	checkInput(char *arg)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (arg[0] == '=')
		return (1);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]))
			return (1);
		if (ft_isalpha(arg[i]))
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (1);
	return (0);
}
