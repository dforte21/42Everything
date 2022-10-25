#include "minishell.h"

void	ft_heredoc(char **matrix, int row)
{
	char	*end;
	char	*line;
	int		fd[2];

	if (matrix[row][2] == '\0')
		end = ft_strdup(matrix[row + 1]);
	else
		end = ft_strdup(&matrix[row][2]);
	while (matrix[row])
	{
		free(matrix[row]);
		matrix[row] = NULL;
		row++;
	}
	pipe(fd);
	line = readline("> ");
	while (ft_strncmp(line, end, ft_strlen(end)))
	{
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	free(end);
	write(fd[1], "\0", 1);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	ft_redirection(char **matrix)
{
	int		row;

	row = 0;
	while (matrix[row])
	{
		if (matrix[row][0] == '<' && matrix[row][1] != '<')
			continue ;
		else if (matrix[row][0] == '>' && matrix[row][1] != '>')
			continue ;
		else if (ft_strncmp(matrix[row], "<<", 2) == 0)
			ft_heredoc(matrix, row);
		else if (ft_strncmp(matrix[row], ">>", 2) == 0)
			continue ;
		row++;
	}
}