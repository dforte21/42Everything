#include "minishell.h"

void	ft_quit130(int sig)
{
	(void) sig;
	g_exit_status = 130;
	write(1, "ˆC\n", 4);
}

void	ft_ctrlc(char **envp)
{
	char	*argv[3];
	int		pid;

	argv[0] = ft_strdup("stty");
	argv[1] = ft_strdup("-ctlecho");
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve("/bin/stty", argv, envp);
	waitpid(-1, NULL, 0);
	free(argv[0]);
	free(argv[1]);
}

void	ft_sigint(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 1;
}

void	ft_signal(void)
{	
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
}
