#include "minishell.h"

void	ftExport(t_comms *comms, char **envp, int i, int flag)
{
	if (comms->cargs[1])
	{
		while (comms->cargs[i + 1])
		{
			flag = checkEnv(comms->cargs[i + 1], envp);
			if (flag != -1)
				addEnv(comms->cargs[i + 1], envp, flag, comms);
			i++;
		}
	}
	else
	{
		comms->envcpy = copyEnv(comms, envp);
		sortEnv(comms, comms->envcpy);
		while (comms->envcpy[i])
		{
			printf("declare -x ");
			printf("%s", comms->envcpy[i]);
			printf("\n");
			i++;
		}
		ftFree(comms->envcpy);
	}
	g_exit_status = 0;
}

char	**copyEnv(t_comms *comms, char **envp)
{
	char	**envc;
	int		i;

	i = 0;
	envc = ft_calloc(comms->lenv + 2, sizeof(char *));
	while (envp[i])
	{
		envc[i] = ft_strdup(envp[i]);
		i++;
	}
	return (envc);
}

void	addEnv(char *arg, char **envp, int flag, t_comms *comms)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (envp[i])
		i++;
	j = ftStrchr(arg, '=', 0);
	if (arg[j])
		tmp = createEnv(arg);
	else
		tmp = ft_strdup(arg);
	envp[i] = ft_strdup(tmp);
	if (!flag)
	{
		envp[i + 1] = NULL;
		comms->lenv++;
	}
	free(tmp);
}

char	*createEnv(char *arg)
{
	char	**var;
	char	*tmp;

	var = ft_split(arg, '=');
	tmp = ft_strdup(var[0]);
	tmp = ft_strjoin(tmp, "=\"");
	if (var[1])
	{
		var[1] = ft_strtrim(var[1], "\"");
		tmp = ft_strjoin(tmp, var[1]);
	}
	tmp = ft_strjoin(tmp, "\"");
	ftFree(var);
	return (tmp);
}

void	sortEnv(t_comms *comms, char **envcpy)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (envcpy[i])
	{
		j = 0;
		while (envcpy[j + 1])
		{
			if (ft_strncmp(envcpy[j], envcpy[j + 1],
					ft_strlen(envcpy[j] + 1)) > 0)
			{
				temp = envcpy[j];
				envcpy[j] = envcpy[j + 1];
				envcpy[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
