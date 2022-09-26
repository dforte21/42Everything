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
	char	*echo;
	char	*cd;
	char	*pwd;
	char	*export;
	char	*unset;
	char	*env;
	char	*exit;
}              t_comms;

void	ftEcho(char **args);
void	ftParser(char *line);
void	ftFree(char **args, char *line);
void	ftExit(char **args, char *line);
void	copyArgs(int words, char **args, char *line, int i);
char	**newSplit(char *line);
int		countWords(char *line);
int		ftStrchr(char *str, char c, int start);

#endif