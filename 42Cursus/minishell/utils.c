#include "minishell.h"

int	ft_skip_quotes(char *str, int i, char c)
{
	int count;

	count = 1;
	if (i == -1)
		return (i);
	if (str[i] == c || (str[i] == '(' && c == ')'))
	{
		i++;
		while ((str[i] != c && str[i]) || str[i] == ')')
		{
			if (str[i] == '(')
				count++;
			if (str[i] == ')' && count > 0)
				count--;
			if (str[i] == ')' && count == 0)
				break ;
			i++;
		}
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ftStrchr(char *str, char c, int start)
{
	int	i;

	i = start;
	while(str[i] != c && str[i])
		i++;
	return (i);
}

void	ftFree(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	ftExit(t_comms *comms)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		if (comms->newenvcp[i])
			free(comms->newenvcp[i]);
		i++;
	}
	free(comms->newenvcp);
	clear_history();
	exit (g_exit_status);
}

void	ftStrReplace(char *str, char old, char new)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
}
