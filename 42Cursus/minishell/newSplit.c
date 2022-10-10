#include "minishell.h"

char	**newSplit(char *line)
{
	int		i;
	int		j;
	int		k;
	int		words;
	char	**args;

	k = 1;
	words = countWords(line);
	args = ft_calloc(words + 1, sizeof(char *));
	i = ftStrchr(line, ' ', 0);
	args[0] = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(args[0], line, i + 1);
	copyArgs(words, args, line, i);
	checkArgs(args, '\"');
	return (args);
}

int	countWords(char *line)
{
	int i;
	int n;

	i = 0;
	n = 1;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
			while (line[i] != ' ' && line[i])
			{
				if (line[i] == '\"' || line[i] == '\'')
					i = ftStrchr(line, line[i], i + 1);
				i++;
			}
			n++;
		}
		else
			i++;
	}
	return (n);
}

void	copyArgs(int words, char **args, char *line, int i)
{
	int j;
	int	k;

	k = 1;
	while (k < words)
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
			j = i;
			while (line[i] != ' ' && line[i])
			{
				if (line[i] == '\"' || line[i] == '\'')
					i = ftStrchr(line, line[i], i + 1);
				i++;
			}
			args[k] = ft_calloc(i - j + 1, sizeof(char));
			ft_strlcpy(args[k], &line[j], i - j + 1);
			k++;
		}
		else
			i++;
	}
}

void	checkArgs(char **args, char c)
{
	char	*tmp;
	char	*tmp3;
	int		i;
	int		j;
	int		k;

	i = 1;
	tmp3 = NULL;
	while(args[i])
	{
		j = 0;
		while (args[i][j])
		{
			k = j;
			j = ftStrchr(args[i], '\"', j + 1);
			if (!args[i][j])
				continue ;
			tmp = ft_substr(args[i], k, j - k + 1);
			if (tmp[0] != '\"' || tmp[j - k] != '\"')
				tmp = ftRemoveChar(tmp, '\'');
			tmp = ftRemoveChar(tmp, '\"');
			if (tmp3)
				tmp3 = ft_strjoin(tmp3, tmp);
			else
				tmp3 = ft_strdup(tmp);
			free(tmp);
		}
		free(args[i]);
		args[i] = ft_strdup(tmp3);
		free(tmp3);
		i++;
	}
}
