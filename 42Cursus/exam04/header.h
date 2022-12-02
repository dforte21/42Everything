#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

typedef struct s_cmd
{
	int	pipe[2];
	int stdoutcpy;
	int	stdincpy;
	int	flag;
	char *cmd[1000];
}	t_cmd;

void	ftcommand(char **av, int j, t_cmd *cmd, char **envp);
int	 ftstrlen(char *str);
void	ftcd(t_cmd *cmd);
void	error(char *str, int caller, char *arg);
void	ftpipe(char **av, int j, t_cmd *cmd, char **envp);

#endif