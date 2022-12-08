/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:18:56 by dforte            #+#    #+#             */
/*   Updated: 2022/11/24 16:35:33 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_comms	comms;

	ac = 0;
	initargs(&comms, envp);
	if (av[1] && av[0][0] != '.')
	{
		g_exit_status = ft_atoi(av[2]);
		ft_subcommand(av, envp, &comms);
		ftexit(&comms);
	}
	ft_ctrlc(envp);
	incrementshlvl(envp, &comms);
	ftprocess(comms, envp);
	ftexit(&comms);
}

void	ftprocess(t_comms comms, char **envp)
{
	while (comms.exit == 0)
	{
		ft_signal();
		comms.line = readline("Minishell-1.39$ ");
		if (!comms.line)
		{
			write(STDERR_FILENO, "exit\n", 5);
			break ;
		}
		if (ft_strlen(comms.line) != 0)
			add_history(comms.line);
		if (ft_strlen(comms.line) == 0)
			continue ;
		parsecmdline(&comms, envp);
		free(comms.line);
	}
}

void	parsecmdline(t_comms *comms, char **envp)
{
	int	i;

	i = 0;
	while (comms->line[i])
	{
		if (ft_check_char(comms->line, '|') || ft_check_char(comms->line, '&')
			|| ft_check_syntax(comms->line) || ft_check_char(comms->line, '>')
			|| ft_check_char(comms->line, '<'))
			break ;
		i = checkmltcmd(comms, i);
		comms->pipes = ft_smart_split(comms->cmd, '|');
		comms->pipefd = allocpipe(comms);
		comms->redfd = allocred(comms);
		ftparser(comms, envp);
		free(comms->cmd);
		ftfree(comms->pipes);
		if (!checkflag(comms) || comms->exit != 0)
			break ;
	}
}

void	incrementshlvl(char **envp, t_comms *comms)
{
	int		lvl;
	char	*input;
	char	*shlvl;
	char	*newlvl;

	input = ft_strdup("SHLVL");
	shlvl = fdgetenv(input, envp);
	shlvl = ft_strtrim(shlvl, "\"");
	lvl = ft_atoi(shlvl);
	free(shlvl);
	newlvl = ft_itoa(lvl + 1);
	comms->cargs = ft_calloc(3, sizeof(char *));
	comms->cargs[0] = ft_strdup("export");
	comms->cargs[1] = ft_strdup("SHLVL=");
	comms->cargs[1] = ft_strjoin(comms->cargs[1], newlvl);
	free(newlvl);
	ftexport(comms, envp, 0, 0);
	free(input);
	ftfree(comms->cargs);
}

void	ft_subcommand(char **av, char **envp, t_comms *comms)
{
	int	i;

	i = 0;
	comms->line = ft_strdup(av[1]);
	while (comms->line[i])
	{
		i = checkmltcmd(comms, i);
		comms->pipes = ft_smart_split(comms->cmd, '|');
		comms->pipefd = allocpipe(comms);
		comms->redfd = allocred(comms);
		ftparser(comms, envp);
		ftfree(comms->pipes);
	}
}
