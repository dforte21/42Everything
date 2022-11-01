#include "minishell.h"

char	*ft_replace(char *src, char **envp, int i)
{
	char	*dst;
	char	*matrix[3];
	int		j;

	j = 1;
	while ((ft_isalnum(src[i + j]) || src[i + j] == '_') && src[i + j])
		j++;
	dst = malloc (sizeof(char) * j + 1);
	ft_strlcpy(dst, &src[i + 1], j);
	matrix[1] = fdGetEnv(dst, envp);
	free(dst);
	matrix[2] = ft_strdup(&src[i + j]);
	matrix[0] = ft_substr(src, 0, i);
	if (matrix[1] != NULL)
	{
		dst = ft_strjoin(matrix[0], matrix[1]);
		free(matrix[1]);
		dst = ft_strjoin(dst, matrix[2]);
		free(matrix[2]);
	}
	else
		dst = ft_strjoin(matrix[0], matrix[2]);
	return (dst);
}


char	*ft_check_expand(char *src, char **envp, int i)
{
	char	*dst;
	char	*matrix[3];

	if (src[i + 1] == '?')
	{
		matrix[0] = malloc (sizeof(char) * i);
		ft_strlcpy(matrix[0], src, i + 1);
		matrix[1] = ft_itoa(g_exit_status);
		matrix[2] = ft_strdup(&src[i + 2]);
		dst = ft_strjoin(matrix[0], matrix[1]);
		free(matrix[1]);
		dst = ft_strjoin(dst, matrix[2]);
		free(matrix[2]);
	}
	else
		dst = ft_replace(src, envp, i);
	free(src);
	return (dst);
}

char	*ft_expand(char *src, char **envp)
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
				if (src[i] == '$')
					src = ft_check_expand(src, envp, i);
				else
					i++;
			}
		}
		i = ft_skip_quotes(src, i, '\'');
		if (src[i] == '$')
			src = ft_check_expand(src, envp, i);
		else
			i++;
	}
	return (src);
}
