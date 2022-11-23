/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:24:12 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 18:03:47 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ftexport(t_comms *comms, char **envp, int i, int flag)
{
	if (comms->cargs[1])
	{
		while (comms->cargs[i + 1])
		{
			if (checkinput(comms->cargs[i + 1]))
				return (fterror(comms->cargs, 1, i + 1));
			flag = checkenv(comms->cargs[i + 1], envp, comms);
			if (flag != -1)
				addenv(comms->cargs[i + 1], envp, flag, comms);
			i++;
		}
		return (0);
	}
	comms->envcpy = copyenv(comms, envp);
	sortenv(comms, comms->envcpy);
	while (comms->envcpy[i])
	{
		printf("declare -x ");
		printf("%s", comms->envcpy[i]);
		printf("\n");
		i++;
	}
	ftfree(comms->envcpy);
	return (0);
}

char	**copyenv(t_comms *comms, char **envp)
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

void	addenv(char *arg, char **envp, int flag, t_comms *comms)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (envp[i])
		i++;
	j = ftstrchr(arg, '=', 0);
	if (arg[j])
		tmp = createenv(arg);
	else
		tmp = ft_strdup(arg);
	envp[i] = ft_strdup(tmp);
	if (!flag)
	{
		envp[i + 1] = NULL;
		comms->lenv++;
	}
	newenv(comms, tmp);
	free(tmp);
}

char	*createenv(char *arg)
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
	ftfree(var);
	return (tmp);
}

void	sortenv(t_comms *comms, char **envcpy)
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
