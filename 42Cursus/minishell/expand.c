#include "minishell.h"

char	**ftExpand(char **src, char **envp)
{
	int	row;
	int	col;

	row = 0;
	while (src[row])
	{
		col = 0;
		while (src[row][col])
		{
			if (src[row][col] == '$')
				src[row] = ftReplace(src[row], envp, col);
			col++;
		}
		row++;
	}
	return (src);
}

char *ftReplace(char *src, char **envp, int i)
{
	char	*dst;
	char	*matrix[4];
	int		j;

	j = 0;
	while (src[i + j] != ' ' && src[i + j])
		j++;
	dst = malloc (sizeof(char) * j);
	ft_strlcpy(dst, &src[i + 1], j);
	matrix[1] = fdGetEnv(dst, envp);
	if (!matrix[1])
	 	return (src);
	matrix[2] = ft_strdup(&src[i + j]);
	j = 0;
	while (src[j] != '$' && src[j])
		j++;
	matrix[0] = malloc (sizeof(char) * j + 1);
	ft_strlcpy(matrix[0], src, j + 1);
	dst = ft_strjoin(matrix[0], matrix[1]);
	dst = ft_strjoin(dst, matrix[2]);
	matrix[3] = NULL;
	return (dst);
}
