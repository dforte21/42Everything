#include "minishell.h"

// char	*ft_remove_heredoc(char **matrx, int row)
// {
// 	int	i;

// 	i = 0;
// 	while (i < r
// }

void	ft_between_quotes(char *s1, char *s2, char c, int *i)
{
	i[0] += 1;
	while (s1[i[0]] != c)
	{
		s2[i[1]] = s1[i[0]];
		i[0]++;
		i[1]++;
	}
	i[0] += 1;
}

char	*ft_no_quotes(char *scr)
{
	int		i[2];
	char	*dst;

	if (!ft_strchr(scr, '\"') && !ft_strchr(scr, '\''))
		return (scr);
	dst = malloc (sizeof(char) * ft_strlen(scr));
	i[0] = 0;
	i[1] = 0;
	while (scr[i[0]])
	{
		if (scr[i[0]] == '\'')
			ft_between_quotes(scr, dst, '\'', i);
		else if (scr[i[0]] == '\"')
			ft_between_quotes(scr, dst, '\"', i);
		else
		{
			dst[i[1]] = scr[i[0]];
			i[0]++;
			i[1]++;
		}
	}
	dst[i[1]] = '\0';
	free(scr);
	return (dst);
}

char	**ft_remove_quotes(char **matrix)
{
	int	row;

	row = 0;
	while (matrix[row])
	{
		matrix[row] = ft_no_quotes(matrix[row]);
		row++;
	}
	return(matrix);
}