#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <term.h>
# include <stdio.h>
# include <fcntl.h>
# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>

int	g_exit_status;

typedef struct s_comms
{
	char	*line;
	char	**pargs;
	char	**cargs;
	int		pipefd[2];
	int		exit;
}              t_comms;

void	writePipe(char *args, int pipefd);
void	ftEcho(t_comms *comms);
void	ftEnv(t_comms *comms, char **envp);
void	ftParser(t_comms *comms, char **envp);
void	exeCommand(t_comms *comms, char **envp);
void	ftFree(char **args);
void	ftExit(t_comms *comms);
void	ftError(char *arg, int pipefd);
void	ftStrReplace(char *str, char c);
void	copyArgs(int words, char **args, char *line, int i);
char	**newSplit(char *line);
char	*readPipe(int pipefd);
int		countWords(char *line);
int		ftStrchr(char *str, char c, int start);

#endif