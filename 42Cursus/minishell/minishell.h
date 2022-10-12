#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <term.h>
# include <errno.h>
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
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int	g_exit_status;

typedef struct s_comms
{
	char	*line;
	char	**pipes;
	char	**cargs;
	char	**envcpy;
	char	**path;
	char	*heredoc[20];
	int		**pipefd;
	int		redirection[20][2];
	int		exit;
	int		lenv;
}              t_comms;

//commands
int		ftEcho(t_comms *comms);
int		ftEnv(t_comms *comms, char **envp);
int		ftExport(t_comms *comms, char **envp, int i, int flag);
int		ftUnset(t_comms *comms, char **envp);
int		ftPwd(t_comms *comms);
int		ftCd(t_comms *comms);
int		ftExecve (t_comms *comms, char **envp);
int		ft_exit(t_comms *comms);

//pipe&fork
void	ftParser(t_comms *comms, char **envp);
void	exeCommand(t_comms *comms, char **envp, int i);
void	childExecute(t_comms *comms, char **envp, int i, int j);
void	chooseCommand(t_comms *comms, char **envp, int i, int j);
int		**allocPipe(t_comms *comms);
int		exeFork(t_comms *comms, char **envp, char *path);

//signals
void	ft_ctrlc(char **envp);
void	ft_sigint(int sig);
void	ft_signal(void);
void 	rl_replace_line (const char *text, int clear_undo);

//env
void	addEnv(char *arg, char **envp, int flag, t_comms *comms);
void	sortEnv(t_comms *comms, char **envcpy);
char	**ftExpand(char **src, char **envp);
char	**copyEnv(t_comms *comms, char **envp);
char	*fdGetEnv(char *str, char **envp);
char	*createEnv(char *arg);
int		findEnv(char *arg, char **envp);
int		checkEnv(char *arg, char **envp);

//initializator
void	initArgs(t_comms *comms, char **envp);
void	incrementShlvl(char **envp, t_comms *comms);
char	*buildPath(t_comms *comms);

//utils
void	ftFree(char **args);
void	ftExit(t_comms *comms);
void	ftStrReplace(char *str, char old, char new);
void	ftFreePipe(t_comms *comms, int j);
void	check_status(int exit, t_comms *comms, int i);
char	**getPath(void);
char	*createTmpFile(void);
char 	*ftReplace(char *src, char **envp, int i);
char	*ftRemoveChar(char *str, char c);
int		ftError(char **arg, int caller, int i);
int		ftStrchr(char *str, char c, int start);
int		checkInput(char *arg);

//split
void	copyArgs(int words, char **args, char *line, int i);
void	checkArgs(char **args, char c);
char	**newSplit(char *line);
int		countWords(char *line);

#endif