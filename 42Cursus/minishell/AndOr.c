#include "minishell.h"

int	checkMltCmd(t_comms *comms, int i)
{
	int	end;

	end = i;
	comms->cmdflag = 0;
	while (comms->line[end])
	{
		end = ft_skip_quotes(comms->line, end, '\"');
		end = ft_skip_quotes(comms->line, end, '\'');
		end = ft_skip_quotes(comms->line, end, ')');
		if (comms->line[end] == '&' || ft_strncmp(&comms->line[end], "||", 2) == 0)
		{
			if (comms->line[end] == '&')
				comms->cmdflag = 1;
			if (comms->line[end] == '|')
				comms->cmdflag = 2;
			break ;
		}
		end++;
	}
	while (comms->line[end] && (comms->line[end] == '&' || comms->line[end] == '|'))
		end++;
	comms->cmd = ft_substr(comms->line, i, end - i);
	comms->cmd = ft_strtrim(comms->cmd, "&&");
	return (end);
}

int	checkFlag(t_comms *comms)
{
	if (comms->cmdflag == 1 && g_exit_status != 0)
		return (0);
	else if (comms->cmdflag == 2 && g_exit_status == 0)
		return (0);
	return (1);
}

char	*ft_buildss(t_comms *comms, int i)
{
	pid_t	pid;
	int		j;
	char	*cmd;

	j = 0;
	while (comms->pipes[i][j])
		j++;
	cmd = ft_substr(comms->pipes[i], 1, j - 2);
	return (cmd);
}

void	ft_subshell(t_comms *comms, char **envp)
{
	pid_t	pid;
	char	*av[4];
	char	*path;
	int		status;

	path = ft_strdup("./minishell");
	av[0] = ft_strdup("minishell");
	av[1] = ft_strdup(comms->subsh);
	av[2] = ft_itoa(g_exit_status);
	av[3] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve(path, av, envp);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	free(path);
	free(av[0]);
	free(av[1]);
	free(av[2]);
}
