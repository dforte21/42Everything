/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:23:28 by dforte            #+#    #+#             */
/*   Updated: 2022/11/24 17:19:04 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_dollar(char *src, char **envp, int i)
{
	char	*dst;
	char	*matrix[4];
	int		j;

	j = 1;
	while ((ft_isalnum(src[i + j]) || src[i + j] == '_') && src[i + j])
		j++;
	dst = ft_substr(src, i + 1, j - 1);
	matrix[1] = fdgetenv(dst, envp);
	free(dst);
	if (matrix[1] == NULL)
		return (NULL);
	matrix[1] = ft_no_quotes(matrix[1]);
	matrix[2] = ft_strdup(&src[i + j]);
	matrix[0] = ft_substr(src, 0, i);
	matrix[3] = NULL;
	if (matrix[1] != NULL)
		dst = ft_multijoin(matrix);
	else
	{
		dst = ft_strjoin(matrix[0], matrix[2]);
		free(matrix[2]);
	}
	return (dst);
}

char	*ft_check_expand(char *src, char **envp, int *i)
{
	char	*dst;
	char	*matrix[4];

	if (src[*i] == '*')
		dst = ft_asterisk(src, i);
	else if (src[*i + 1] == '?')
	{
		matrix[0] = ft_substr(src, 0, *i);
		matrix[1] = ft_itoa(g_exit_status);
		matrix[2] = ft_strdup(&src[*i + 2]);
		matrix[3] = NULL;
		dst = ft_multijoin(matrix);
	}
	else
		dst = ft_dollar(src, envp, *i);
	if (dst == NULL)
	{
		*i += 1;
		return (src);
	}
	free(src);
	return (dst);
}

char	*ft_expand(char *src, char **envp, char c)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '"')
		{
			i += 1;
			while (src[i] != '\"')
			{
				if (src[i] == c && src[i] != '*')
					src = ft_check_expand(src, envp, &i);
				else
					i++;
			}
		}
		i = ft_skip_quotes(src, i, '\'');
		if (src[i] == c)
			src = ft_check_expand(src, envp, &i);
		else
			i++;
	}
	return (src);
}
