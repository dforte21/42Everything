/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phbonus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:10:36 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 19:08:17 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHBONUS_H
# define PHBONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int				id;
	int				eat;
	long long		strv;
	struct s_rules	*rules;
	pid_t			pid;
	pthread_t		death;
}				t_philo;

typedef struct s_rules
{
	int				nphilo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long int	start;
	pthread_t		finish_eat;
	sem_t			*msg;
	sem_t			*forks;
	sem_t			*finish;
	sem_t			*isdead;
	t_philo			*philo;
}				t_rules;

int				main(int ac, char **av);
int				ft_atoi(const char *str);
int				check_args(int ac, char **av);
int				ft_error(char *err);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_finish(t_philo *philo);
void			ft_exit(t_rules *rules);
void			ft_message(t_philo *ph, char *msg);
void			my_sleep(long long time);
void			ft_thread(t_rules *rules);
void			ft_meal(void *philo);
void			*ft_monitor(void *philo);
void			*ft_must_eat(void *rules);
void			initialize_philo(t_rules *rules);
void			initialize_arg(int ac, char **av, t_rules *rules);
size_t			ft_strlen(const char *s);
long long		ft_time(void);

#endif