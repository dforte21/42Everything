#include "minishell.h"

int g_exit_status;

int main(int ac, char **av, char **envp)
{
	int		status;
	t_comms	comms;

	initArgs(&comms, envp);
	incrementShlvl(envp, &comms);
	while (comms.exit == 0)
	{
		ft_signal();
		comms.line = readline("Minishell-1.33$ ");
		if (!comms.line)
		{
			printf("exit\n");
			break ;
		}
		if (ft_check_line(comms.line) || ft_strlen(comms.line) == 0)
			continue ;
		comms.pipes = ft_smart_split(comms.line, '|');
		comms.pipefd = allocPipe(&comms);
		ftParser(&comms, envp);
		ftFree(comms.pipes);
		free(comms.line);
	}
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

void	initArgs(t_comms *comms, char **envp)
{
	ft_ctrlc(envp);
	g_exit_status = 0;
	comms->exit = 0;
	comms->lenv = 0;
	while (envp[comms->lenv])
		comms->lenv++;
	comms->path = getPath();
	comms->newenvcp=ft_calloc(101, sizeof(char *));
}

void	incrementShlvl(char **envp, t_comms *comms)
{
	int		lvl;
	char	*input;
	char	*shlvl;
	char	*newlvl;

	input = ft_strdup("SHLVL");
	shlvl = fdGetEnv(input, envp);
	shlvl = ft_strtrim(shlvl, "\"");
	lvl = ft_atoi(shlvl);
	free(shlvl);
	newlvl = ft_itoa(lvl + 1);
	comms->cargs = ft_calloc(3, sizeof(char *));
	comms->cargs[0] = ft_strdup("export");
	comms->cargs[1] = ft_strdup("SHLVL=");
	comms->cargs[1] = ft_strjoin(comms->cargs[1], newlvl);
	free(newlvl);
	ftExport(comms, envp, 0, 0);
	free(input);
	ftFree(comms->cargs);
}
