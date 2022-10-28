#include "minishell.h"

void	ft_heredoc(char *cmd, int *fd)
{
	char	*line;
	char	*endstr;
	int		pp[2];

	pipe(pp);
	endstr = ft_substr(cmd, 2, ft_strlen(cmd) - 2);
	endstr = ft_strtrim(endstr, " ");
	line = readline("> ");
	while (ft_strncmp(line, endstr, ft_strlen(line) + 1) != 0)
	{
		write(pp[1], line, ft_strlen(line));
		write(pp[1], "\n", 1);
		free(line);
		line = readline("> ");
	}
	close(pp[1]);
	if (fd[0] != -1)
		close(fd[0]);
	fd[0] = dup(pp[0]);
	close(pp[0]);
	free(endstr);
	free(line);
}

int	ft_redirection(char *cmd, int *fd)
{
	int	i;
	int	end;

	i = 0;
	fd[0] = -1;
	fd[1] = -1;
	while (cmd[i])
	{
		i = ft_skip_quotes(cmd, i, '\"');
		i = ft_skip_quotes(cmd, i, '\'');
		if (cmd[i] == '<' || cmd[i] == '>')
		{
			end = execRedirect(cmd, i, fd);
			if (end == -1)
				return (-1);
			while (i < end)
			{
				cmd[i] = ' ';
				i++;
			}
		}
		else
			i++;
	}
	return (0);
}

int	execRedirect(char *cmd, int i, int *fd)
{
	int 	end;
	int		flag;
	char	*red;

	end = i + 1;
	if (cmd[end] == '<' || cmd[end] == '>')
		end++;
	while (cmd[end] == ' ')
		end++;
	while (cmd[end] != ' ' && cmd[end])
	{
		end = ft_skip_quotes(cmd, end, '\'');
		end = ft_skip_quotes(cmd, end, '\"');
		end++;
	}
	red = ft_substr(cmd, i, end - i);
	if (ft_strncmp(red, "<<", 2) == 0)
		ft_heredoc(red, fd);
	else
		flag = createFd(red, fd);
	free(red);
	if (flag == -1)
		return (-1);
	return (end);
}

int	createFd(char *cmd, int *fd)
{
	char	*path[2];
	int		i;

	i = 1;
	if (cmd[i] == '<' || cmd[i] == '>')
		i++;
	path[0] = ft_substr(cmd, i, ft_strlen(cmd) - i);
	path[0] = ft_strtrim(path[0], " ");
	path[1] = NULL;
	if (ft_strncmp(cmd, ">>", 2) == 0)
	{
		if (fd[1] != -1)
			close(fd[1]);
		fd[1] = open(path[0], O_RDWR | O_CREAT | O_APPEND, 0666);
	}
	else if(cmd[0] == '>' && cmd[1] != '>')
	{
		if (fd[1] != -1)
			close(fd[1]);
		fd[1] = open(path[0], O_RDWR | O_CREAT | O_TRUNC, 0666);
	}
	else if (cmd[0] == '<')
	{
		if (fd[0] != -1)
			close(fd[0]);
		fd[0] = open(path[0], O_RDONLY);
		if (fd[0] == -1)
			return (-1);
	}
	free(path[0]);
	return (0);
}

int	checkHD(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd[i])
	{
		i = ft_skip_quotes(cmd, i, '\"');
		i = ft_skip_quotes(cmd, i, '\'');
		if (cmd[i] == '<')
			return (1);
		i++;
	}
	return (0);
}
