/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:17:54 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 17:49:07 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fdgetenv(char *str, char **envp)
{
	int		row;
	int		col;
	char	*dst;

	dst = 0;
	row = 0;
	while (envp[row])
	{
		if (!ft_strncmp(str, envp[row], ft_strlen(str)))
		{
			col = 0;
			while (envp[row][col] != '=')
				col++;
			if (col == ft_strlen(str))
			{
				dst = ft_strdup(&envp[row][col + 1]);
				break ;
			}
		}
		row++;
	}
	return (dst);
}

int	ftenv(t_comms *comms, char **envp)
{
	char	*env;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][ftstrchr(envp[i], '=', 0)])
		{
			env = ft_strdup(envp[i]);
			env = ft_no_quotes(env);
			printf("%s", env);
			printf("\n");
			free(env);
		}
		i++;
	}
	return (0);
}
