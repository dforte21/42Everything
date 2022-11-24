/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:27:30 by dforte            #+#    #+#             */
/*   Updated: 2022/11/24 16:33:14 by dforte           ###   ########.fr       */
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
	char	**nep;
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
int		ftecho(t_comms *comms);
int		ftenv(char **envp);
int		ftexport(t_comms *comms, char **envp, int i, int flag);
int		ftunset(t_comms *comms, char **envp, int i);
int		ftpwd(void);
int		ftcd(t_comms *comms);
int		ftexecve(t_comms *comms, char **envp);
int		ft_exit(t_comms *comms);

//pipe&fork
pid_t	choosecommand(t_comms *comms, char **envp, int i);
void	switchcmd(t_comms *comms, char **envp);
void	parsecmdline(t_comms *comms, char **envp);
void	ftprocess(t_comms comms, char **envp);
void	ftparser(t_comms *comms, char **envp);
void	execommand(t_comms *comms, char **envp, int i);
void	childexecute(t_comms *comms, char **envp, int i);
void	checksons(pid_t pid, t_comms *comms, int status, int j);
int		**allocpipe(t_comms *comms);
int		**allocred(t_comms *comms);
int		exefork(t_comms *comms, char **envp, char *path);

//signals
void	ft_quit130(int sig);
void	ft_quitslash(int sig);
void	ft_ctrlc(char **envp);
void	ft_sigint(int sig);
void	ft_signal(void);
void	rl_replace_line(const char *text, int clear_undo);
void	ft_quit131(int sig);

//env
void	addenv(char *arg, char **envp, int flag, t_comms *comms);
void	sortenv(char **envcpy);
void	newenv(t_comms *comms, char *env);
char	**ftExpand(char **src, char **envp);
char	**copyenv(t_comms *comms, char **envp);
char	*fdgetenv(char *str, char **envp);
char	*createenv(char *arg);
int		findenv(char *arg, char **envp);
int		checkenv(char *arg, char **envp, t_comms *comms);
int		delenv(t_comms *comms, char *env);

//initializator
void	initargs(t_comms *comms, char **envp);
void	incrementshlvl(char **envp, t_comms *comms);
char	*buildpath(t_comms *comms);

//utils
void	ftfree(char **args);
void	ftexit(t_comms *comms);
void	ftstrreplace(char *str, char old, char new);
void	ftfreepipe(t_comms *comms, int j);
void	check_status(int exit);
void	set_fd(t_comms *comms, int flag);
char	**ft_delrow(char **src, int del);
char	**ft_remove_quotes(char **matrix);
char	**getpath(char **envp);
char	*ft_multijoin(char **matrix);
char	*ft_expand(char *src, char **envp, char c);
char	*createTmpFile(void);
char	*ftReplace(char *src, char **envp, int i);
char	*ftremovechar(char *str, char c);
char	*ft_skip_strrchr(char *str, char c);
char	*ft_skip_strchr(char *str, char c);
int		ft_check_char(char *str, char c);
int		ft_skip_parenthesis(char *str, int i);
int		ft_skip_quotes(char *str, int i, char c);
int		ft_check_syntax(char *str);
int		fterror(char **arg, int caller, int i);
int		fterror2(char **arg, int caller, int i, char *line);
int		ftstrchr(char *str, char c, int start);
int		checkinput(char *arg);
int		ft_matlen(char **matrix);
int		checkdir(t_comms *comms, struct stat filestat, int r);

//split
char	**ft_smart_split(char *s, char c);
char	*ft_no_quotes(char *scr);

//redirection
void	outredirection(char *cmd, int *fd, char **path);
int		inredirection(int *fd, char **path, int check);
int		ft_redirection(char *cmd, int *fd, int caller);
int		createfd(char *cmd, int *fd, char *fullcmd, int i);
int		execredirect(char *cmd, int i, int *fd, int caller);
int		checkhd(char *cmd);

//andorparenthesis
void	ft_subcommand(char **av, char **envp, t_comms *comms);
void	ft_subshell(t_comms *comms, char **envp);
char	*ft_buildss(t_comms *comms, int i);
int		checkmltcmd(t_comms *comms, int i);
int		checkflag(t_comms *comms);
int		checkspecialcmd(t_comms *comms, int end);

//wildcards
char	*ft_asterisk(char *src, int *i);
char	*ft_wildcard(char *str, char **dir);
char	**ft_get_dir(int row);
char	**ft_between(char **wild, char **dir);
char	**ft_first_last(char *str, char **dir, int flag);
char	*checkstr(char *str, char **dir);
int		ft_dirlen(void);

#endif