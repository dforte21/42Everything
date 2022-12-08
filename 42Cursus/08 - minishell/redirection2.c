/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:31:06 by dforte            #+#    #+#             */
/*   Updated: 2022/11/24 16:29:20 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	outredirection(char *cmd, int *fd, char **path)
{
	if (ft_strncmp(cmd, ">>", 2) == 0)
	{
		if (fd[1] != -1)
			close(fd[1]);
		fd[1] = open(path[0], O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else if (cmd[0] == '>' && cmd[1] != '>')
	{
		if (fd[1] != -1)
			close(fd[1]);
		fd[1] = open(path[0], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
}

int	inredirection(int *fd, char **path, int check)
{
	if (fd[2] != -1)
		close(fd[2]);
	fd[2] = open(path[0], O_RDONLY);
	if (fd[2] == -1)
	{
		errno = 2;
		fterror(path, 2, 0);
		free(path[0]);
		return (-1);
	}
	else if (!check)
	{
		if (fd[0] != -1)
			close(fd[0]);
		fd[0] = dup(fd[2]);
		close(fd[2]);
		fd[2] = -1;
	}
	return (0);
}
