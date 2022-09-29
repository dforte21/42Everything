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
	char	**pipes;
	char	**cargs;
	char	**envcpy;
	char	**path;
	int		pipefd[2];
	int		exit;
	int		lenv;
}              t_comms;

void	writePipe(char *args, int pipefd);
void	ftEcho(t_comms *comms);
void	ftEnv(t_comms *comms, char **envp);
void	ftExport(t_comms *comms, char **envp, int i, int flag);
void	ftUnset(t_comms *comms, char **envp);
void	ftParser(t_comms *comms, char **envp);
void	exeFork(t_comms *comms, char **envp, char *path);
void	exeCommand(t_comms *comms, char **envp);
void	ftFree(char **args);
void	ftExit(t_comms *comms);
void	ftError(char *arg, int pipefd);
void	ftStrReplace(char *str, char old, char new);
void	copyArgs(int words, char **args, char *line, int i);
void	addEnv(char *arg, char **envp, int flag, t_comms *comms);
void	sortEnv(t_comms *comms, char **envcpy);
char	**getPath(void);
char	**copyEnv(t_comms *comms, char **envp);
char	**newSplit(char *line);
char	*createEnv(char *arg);
char	*createTmpFile(void);
char	*readPipe(int pipefd);
int		ftExecve (t_comms *comms, char **envp);
int		countWords(char *line);
int		ftStrchr(char *str, char c, int start);
int		findEnv(char *arg, char **envp);
int		checkEnv(char *arg, char **envp);

#endif