#include "minishell.h"

//void	ft_heredoc(char *cmd, int row, int *fd)
//{
	
//}

void	ft_redirection(char *cmd, int *fd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		i = ft_skip_quotes(cmd, i, '\"');
		i = ft_skip_quotes(cmd, i, '\"');
		if (cmd[i] == '<' || cmd[i] == '>')
			i = execRedirect(cmd, i, fd);
		i++;
	}
}

int	execRedirect(char *cmd, int i, int *fd)
{
	int 	end;
	char	*red;

	end = i + 1;
	if (cmd[end] == '<' || cmd[end] == '>')
		end++;
	while (cmd[end] == ' ')
		end++;
	while (cmd[end] != ' ')
		end++;
	red = ft_substr(cmd, i, end - i);
}
