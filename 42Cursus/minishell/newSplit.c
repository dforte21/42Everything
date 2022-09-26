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
		if (line[i] == ' ' && line[i + 1] != 34)
		{
			while (line[i] == ' ')
				i++;
			i = ftStrchr(line, ' ', i);
			n++;
		}
		else if (line[i] == 34)
		{
			i = ftStrchr(line, 34, i + 1) + 1;
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
		j = i;
		if (line[i] == ' ' && line[i + 1] != 34)
		{
			while (line[i] == ' ')
				i++;
			j = i - 1;
			i = ftStrchr(line, ' ', i);
			args[k] = ft_calloc(i - j, sizeof(char));
			ft_strlcpy(args[k], &line[j + 1], i - j);
			k++;
		}
		else if (line[i] == 34)
		{
			i = ftStrchr(line, 34, i + 1) + 1;
			args[k] = ft_calloc(i - j, sizeof(char));
			ft_strlcpy(args[k], &line[j + 1], i - j - 1);
			k++;
		}
		else
			i++;
	}
}
