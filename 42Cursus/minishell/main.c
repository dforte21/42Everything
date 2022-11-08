/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:27:41 by dforte            #+#    #+#             */
/*   Updated: 2022/11/08 12:31:01 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_comms	comms;
	int		i;

	initArgs(&comms, envp, av);
	if (av[1] && av[0][0] != '.')
	{
		g_exit_status = ft_atoi(av[2]);
		ft_subcommand(av, envp, &comms);
		ftExit(&comms);
	}
	incrementShlvl(envp, &comms);
	ftProcess(comms, envp, 0);
	ftExit(&comms);
}

void	ftProcess(t_comms comms, char **envp, int i)
{
	while (comms.exit == 0)
	{
		i = 0;
		ft_signal();
		comms.line = readline("Minishell-1.37$ ");
		if (!comms.line)
		{
			write(STDERR_FILENO, "exit\n", 5);
			break ;
		}
		if (ft_strlen(comms.line) != 0)
			add_history(comms.line);
		if (ft_check_syntax(comms.line) || ft_strlen(comms.line) == 0)
			continue ;
		while (comms.line[i])
		{
			i = checkMltCmd(&comms, i);
			if (comms.subshflag == 1)
			{
				ft_subshell(&comms, envp);
				free(comms.cmd);
				continue ;
			}
			comms.pipes = ft_smart_split(comms.cmd, '|');
			comms.pipefd = allocPipe(&comms);
			ftParser(&comms, envp);
			ftFree(comms.pipes);
			free(comms.cmd);
			if (!checkFlag(&comms) || comms.exit != 0)
				break ;
		}
		free(comms.line);
	}
}

void	initArgs(t_comms *comms, char **envp, char **av)
{
	ft_ctrlc(envp);
	g_exit_status = 0;
	comms->exit = 0;
	comms->lenv = 0;
	while (envp[comms->lenv])
		comms->lenv++;
	comms->path = getPath();
	comms->newenvcp = ft_calloc(101, sizeof(char *));
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

void	ft_subcommand(char **av, char **envp, t_comms *comms)
{
	int	i;

	i = 0;
	comms->line = ft_strdup(av[1]);
	if (ft_check_syntax(comms->line) || ft_strlen(comms->line) == 0)
		return ;
	while (comms->line[i])
	{
		i = checkMltCmd(comms, i);
		if (comms->subshflag == 1)
		{
			ft_subshell(comms, envp);
			continue ;
		}
		comms->pipes = ft_smart_split(comms->cmd, '|');
		comms->pipefd = allocPipe(comms);
		ftParser(comms, envp);
		ftFree(comms->pipes);
	}
}
