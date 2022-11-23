#include "minishell.h"

static int	ft_rowcount(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count += 1;
		while (str[i] != c && str[i] != '\0')
		{
			i = ft_skip_quotes(str, i, '\'');
			i = ft_skip_quotes(str, i, '\"');
			i = ft_skip_parenthesis(str, i);
			if (i == -1)
				return (-1);
			i++;
		}
	}
	return (count);
}

static int	ft_rowlen(char *str, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i] == c)
	{
		i++;
		len++;
	}
	while (str[i])
	{
		i = ft_skip_quotes(str, i, '\'');
		i = ft_skip_quotes(str, i, '\"');
		i = ft_skip_parenthesis(str, i);
		if (str[i] == c)
			break ;
		i++;
	}
	return (i - len);
}

char	**ft_smart_split(char *s, char c)
{
	char	**matrix;
	int		count;
	int		len;
	int		row;

	count = ft_rowcount(s, c);
	if (count == -1)
		return (NULL);
	matrix = (char **) malloc (sizeof(char *) * (count + 1));
	matrix[count] = NULL;
	len = 0;
	row = 0;
	while (row < count)
	{
		len = ft_rowlen(s, c);
		while (*s == c)
			s++;
		matrix[row] = (char *) malloc (sizeof(char) * (len + 1));
		ft_strlcpy(matrix[row], s, len + 1);
		s += len + 1;
		row++;
	}
	return (matrix);
}