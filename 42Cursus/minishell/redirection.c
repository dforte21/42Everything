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
	while (line && ft_strncmp(line, endstr, ft_strlen(line) + 1) != 0)
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
	if (line)
		free(line);
}

int	ft_redirection(char *cmd, int *fd, int caller)
{
	int	i;
	int	end;

	i = 0;
	while (cmd[i])
	{
		i = ft_skip_quotes(cmd, i, '\"');
		i = ft_skip_quotes(cmd, i, '\'');
		if (cmd[i] == '<' || cmd[i] == '>')
		{
			end = execRedirect(cmd, i, fd, caller);
			if (end == -1)
				return (-1);
			if (caller == 0)
				i = end;
			while (i < end && caller == 1)
			{
				cmd[i] = ' ';
				i++;
			}
		}
		else
			i++;
	}
	if (caller == 0)
		return (ft_redirection(cmd, fd, 1));
	else
		return (0);
}

int	execRedirect(char *cmd, int i, int *fd, int caller)
{
	int 	end;
	int		flag;
	char	*red;

	end = i + 1;
	flag = 0;
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
	if (ft_strncmp(red, "<<", 2) == 0 && caller == 0)
		ft_heredoc(red, fd);
	else if (ft_strncmp(red, "<<", 2) != 0 && caller == 1)
		flag = createFd(red, fd, cmd, end);
	free(red);
	if (flag == -1)
		return (-1);
	return (end);
}

int	createFd(char *cmd, int *fd, char *fullcmd, int j)
{
	char	*path[2];
	int		i;

	i = 1;
	if (cmd[i] == '<' || cmd[i] == '>')
		i++;
	path[0] = ft_substr(cmd, i, ft_strlen(cmd) - i);
	path[0] = ft_strtrim(path[0], " ");
	path[1] = NULL;
	if (cmd[0] == '>')
		outRedirection(cmd, fd, path);
	else if (cmd[0] == '<')
	{
		if (fd[2] != -1)
			close(fd[2]);
		fd[2] = open(path[0], O_RDONLY);
		if (fd[2] == -1)
		{
			errno = 2;
			ftError(path, 2, 0);
			free(path[0]);
			return (-1);
		}
		else if (!checkHD(&fullcmd[j]))
		{
			if (fd[0] != -1)
				close(fd[0]);
			fd[0] = dup(fd[2]);
			close(fd[2]);
			fd[2] = -1;
		}
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
