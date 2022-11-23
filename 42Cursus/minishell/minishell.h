/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:27:30 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 15:46:51 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	g_exit_status;

typedef struct s_comms
{
	char	*line;
	char	*cmd;
	char	*subsh;
	char	**newenvcp;
	char	**pipes;
	char	**cargs;
	char	**envcpy;
	char	**path;
	int		**pipefd;
	int		**redfd;
	int		stdincpy;
	int		stdoutcpy;
	int		exit;
	int		lenv;
	int		cmdflag;
}					t_comms;

//builtins
int		ftEcho(t_comms *comms);
int		ftEnv(t_comms *comms, char **envp);
int		ftExport(t_comms *comms, char **envp, int i, int flag);
int		ftUnset(t_comms *comms, char **envp, int i);
int		ftPwd(t_comms *comms);
int		ftCd(t_comms *comms);
int		ftExecve(t_comms *comms, char **envp);
int		ft_exit(t_comms *comms);

//pipe&fork
pid_t	chooseCommand(t_comms *comms, char **envp, int i, int j);
void	ftProcess(t_comms comms, char **envp, int i);
void	ftParser(t_comms *comms, char **envp);
void	exeCommand(t_comms *comms, char **envp, int i);
void	childExecute(t_comms *comms, char **envp, int i);
int		**allocPipe(t_comms *comms);
int		**allocRed(t_comms *comms);
int		exeFork(t_comms *comms, char **envp, char *path);

//signals
void	ft_quit130(int sig);
void	ft_quitslash(int sig);
void	ft_ctrlc(char **envp);
void	ft_sigint(int sig);
void	ft_signal(void);
void	rl_replace_line(const char *text, int clear_undo);

//env
void	addEnv(char *arg, char **envp, int flag, t_comms *comms);
void	sortEnv(t_comms *comms, char **envcpy);
void	newEnv(t_comms *comms, char *env);
char	**ftExpand(char **src, char **envp);
char	**copyEnv(t_comms *comms, char **envp);
char	*fdGetEnv(char *str, char **envp);
char	*createEnv(char *arg);
int		findEnv(char *arg, char **envp);
int		checkEnv(char *arg, char **envp, t_comms *comms);
int		delEnv(t_comms *comms, char *env);

//initializator
void	initArgs(t_comms *comms, char **envp, char **av);
void	incrementShlvl(char **envp, t_comms *comms);
char	*buildPath(t_comms *comms);

//utils
void	ftFree(char **args);
void	ftExit(t_comms *comms);
void	ftStrReplace(char *str, char old, char new);
void	ftFreePipe(t_comms *comms, int j);
void	check_status(int exit);
void	set_fd(t_comms *comms, int flag);
char	**ft_delrow(char **src, int del);
char	**ft_remove_quotes(char **matrix);
char	**getPath(char **envp);
char	*ft_multijoin(char **matrix);
char	*ft_expand(char *src, char **envp, char c);
char	*createTmpFile(void);
char	*ftReplace(char *src, char **envp, int i);
char	*ftRemoveChar(char *str, char c);
char	*ft_skip_strrchr(char *str, char c);
char	*ft_skip_strchr(char *str, char c);
int		ft_check_char(char *str, char c);
int		ft_skip_parenthesis(char *str, int i);
int		ft_skip_quotes(char *str, int i, char c);
int		ft_check_syntax(char *str);
int		ftError(char **arg, int caller, int i);
int		ftStrchr(char *str, char c, int start);
int		checkInput(char *arg);
int		ft_matlen(char **matrix);

//split
char	**ft_smart_split(char *s, char c);
char	*ft_no_quotes(char *scr);

//redirection
void	outRedirection(char *cmd, int *fd, char **path);
int		inRedirection(char *cmd, int *fd, char **path, int check);
int		ft_redirection(char *cmd, int *fd, int caller);
int		createFd(char *cmd, int *fd, char *fullcmd, int i);
int		execRedirect(char *cmd, int i, int *fd, int caller);
int		checkHD(char *cmd);

//andorparenthesis
void	ft_subcommand(char **av, char **envp, t_comms *comms);
void	ft_subshell(t_comms *comms, char **envp);
char	*ft_buildss(t_comms *comms, int i);
int		checkMltCmd(t_comms *comms, int i);
int		checkFlag(t_comms *comms);

//wildcards
char	*ft_asterisk(char *src, int *i);

#endif