#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	t_comms	comms;

	comms.exit = 0;
	comms.lenv = 0;
	while (envp[comms.lenv])
		comms.lenv++;
	while (comms.exit == 0)
	{
		comms.line = readline("Minishell-1.0$ ");
		ftParser(&comms, envp);
		free(comms.line);
	}
	ftExit(&comms);
}