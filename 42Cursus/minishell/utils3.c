#include "minishell.h"

void	newEnv(t_comms *comms, char *env)
{
	int	i;

	i = 0;
	while (i < 1000 && comms->newenvcp[i])
		i++;
	if (i == 1000)
	{
		free(comms->newenvcp[999]);
		i--;
	}
	comms->newenvcp[i] = ft_strdup(env);
}

int	delEnv(t_comms *comms, char *env)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (comms->newenvcp[i] && ft_strncmp(env, comms->newenvcp[i], sizeof(comms->newenvcp[i]) + 1) == 0)
		{
			free(comms->newenvcp[i]);
			comms->newenvcp[i] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_matlen(char **matrix)
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
			break;
		dst[row] = ft_strdup(src[row + 1]);
		row++;
	}
	dst[row] = NULL;
	ftFree(src);
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
