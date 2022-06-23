/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:39:30 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 13:25:38 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define FALSE 0
# define TRUE 1
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	long long int	strv;
	bool			end;
	struct s_rules	*rules;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
}				t_philo;

typedef struct s_rules
{
	int				nphilo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			isdeath;
	long long int	start;
	t_philo			*philo;
	pthread_mutex_t	philo_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	must_eat_mutex;
}			t_rules;

int			ft_error(char *err);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			check_args(int ac, char **av);
int			ft_atoi(const char *str);
int			ft_take_fork(t_philo *philo);
int			ft_finish(t_philo *philo);
bool		check_mutex(int flag, t_philo *philo);
void		ft_message(t_philo *ph, char *msg);
void		my_sleep(long long time);
void		ft_starving(t_philo *philo);
void		initialize_arg(int ac, char **av, t_rules *rules);
void		initialize_philo(t_rules *rules);
void		ft_thread(t_rules *rules);
void		*ft_meal(void *philo);
void		ft_death(t_philo *philo);
void		ft_routine(t_philo *ph);
void		initialize_mutex(t_rules *rules);
void		ft_exit(t_rules *rules);
void		ft_monitor(t_rules *rules);
size_t		ft_strlen(const char *s);
long long	ft_time(void);

#endif
