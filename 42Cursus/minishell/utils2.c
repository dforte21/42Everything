#include "minishell.h"

void	ftFreePipe(t_comms *comms, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		close(comms->pipefd[i][0]);
		free(comms->pipefd[i]);
		i++;
	}
	free(comms->pipefd);
}

char	*ftRemoveChar(char *str, char c)
{
	char	**arg;
	char	*tmp;
	int		i;

	i = 1;
	arg = ft_split(str, c);
	tmp = ft_strdup(arg[0]);
	while (arg[i])
	{
		tmp = ft_strjoin(tmp, arg[i]);
		i++;
	}
	free(str);
	return (tmp);
}
