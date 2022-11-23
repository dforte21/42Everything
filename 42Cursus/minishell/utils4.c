#include "minishell.h"

char	*ft_skip_strchr(char *str, char c)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (str[i])
	{
		i = ft_skip_quotes(str, i, '\"');
		i = ft_skip_quotes(str, i, '\'');
		if (str[i] == c)
		{
			ptr = &str[i];
			break ;
		}
		i++;
	}
	return (ptr);
}

char	*ft_skip_strrchr(char *str, char c)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (str[i])
	{
		i = ft_skip_quotes(str, i, '\"');
		i = ft_skip_quotes(str, i, '\'');
		if (str[i] == c)
			ptr = &str[i];
		i++;
	}
	return (ptr);
}

int	ft_skip_parenthesis(char *str, int i)
{
	int	count;

	if (i == -1 || str[i] != '(')
		return (i);
	count = 1;
	i += 1;
	while (str[i] && count != 0)
	{
		i = ft_skip_quotes(str, i, '\"');
		i = ft_skip_quotes(str, i, '\'');
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;
		i++;
	}
	if (count != 0)
		return (-1);
	return (i);
}

int	**allocRed(t_comms *comms)
{
	int	**fd;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (comms->pipes[j])
		j++;
	fd = malloc(sizeof(int *) * j);
	while (comms->pipes[i])
	{
		fd[i] = malloc(sizeof(int) * 3);
		fd[i][0] = -1;
		fd[i][1] = -1;
		fd[i][2] = -1;
		i++;
	}
	return (fd);
}
