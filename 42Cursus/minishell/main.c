#include "minishell.h"

int g_exit_status;

int main(int ac, char **av, char **envp)
{
	t_comms	comms;

	comms.exit = 0;
	comms.lenv = 0;
	while (envp[comms.lenv])
		comms.lenv++;
	comms.path = getPath();
	//while (comms.exit == 0)
	//{
		comms.line = readline("Minishell-1.0$ ");
		comms.pipes = ft_split(comms.line, '|');
		comms.pipefd = allocPipe(&comms);
		ftParser(&comms, envp);
		free(comms.line);
		ftFree(comms.pipes);
	//}
	printf("exit\n");
	ftExit(&comms);
}

char	**getPath(void)
{
	char	**path;
	char	*env;
	int		i;

	i = 0;
	env = getenv("PATH");
	path = ft_split(env, ':');
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}

int	**allocPipe(t_comms *comms)
{
	int	**fd;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (comms->pipes[j])
		j++;
	fd = malloc(sizeof(int *) * j);
	while (comms->pipes[i])
	{
		fd[i] = malloc(sizeof(int) * 2);
		i++;
	}
	return (fd);
}
