/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:36:24 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 18:13:26 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	newenv(t_comms *comms, char *env)
{
	int	i;

	i = 0;
	while (i < 1000 && comms->nep[i])
		i++;
	if (i == 1000)
	{
		free(comms->nep[999]);
		i--;
	}
	comms->nep[i] = ft_strdup(env);
}

int	delenv(t_comms *comms, char *env)
{
	int	i;
	int	len;

	i = 0;
	while (i < 1000)
	{
		if (comms->nep[i])
			len = ft_strncmp(env, comms->nep[i], ft_strlen(comms->nep[i]) + 1);
		if (comms->nep[i] && len == 0)
		{
			free(comms->nep[i]);
			comms->nep[i] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_matlen(char **matrix)
{
	int	row;

	row = 0;
	while (matrix[row])
		row++;
	return (row);
}

char	**ft_delrow(char **src, int del)
{
	int		row;
	char	**dst;

	dst = (char **) malloc (sizeof(char *) * ft_matlen(src));
	row = 0;
	while (row < del)
	{
		dst[row] = ft_strdup(src[row]);
		row++;
	}
	while (1)
	{
		if (src[row + 1] == NULL)
			break ;
		dst[row] = ft_strdup(src[row + 1]);
		row++;
	}
	dst[row] = NULL;
	ftfree(src);
	return (dst);
}

char	*ft_multijoin(char **matrix)
{
	char	*dst;
	int		row;

	if (matrix[0] == NULL)
		return (NULL);
	dst = ft_strdup(matrix[0]);
	free(matrix[0]);
	row = 1;
	while (matrix[row])
	{
		dst = ft_strjoin(dst, matrix[row]);
		free(matrix[row]);
		row++;
	}
	return (dst);
}
