#include "minishell.h"

char	*fdGetEnv(char *str, char **envp)
{
	int		row;
	int		col;
	char	*dst;

	dst = NULL;
	row = 0;
	while (envp[row])
	{
		if (!ft_strncmp(str, envp[row], ft_strlen(str)))
		{
			col = 0;
			while(envp[row][col] != '=')
				col++;
			if (col == ft_strlen(str))
				dst = ft_strdup(&envp[row][col + 1]);
		}
		row++;
	}
	free(str);
	return(dst);
}

int	ftEnv(t_comms *comms, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s", envp[i]);
		printf("\n");
		i++;
	}
	return (0);;
}
