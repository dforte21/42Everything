/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:24:54 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 19:14:55 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phbonus.h"

void	ft_thread(t_rules *rules)
{
	int		i;

	i = 0;
	rules->start = ft_time();
	if (rules->must_eat != -1)
		pthread_create(&rules->finish_eat, NULL, ft_must_eat, rules);
	while (i < rules->nphilo)
	{
		rules->philo[i].pid = fork();
		if (rules->philo[i].pid == 0)
			ft_meal(&rules->philo[i]);
		i++;
	}
	sem_wait(rules->isdead);
	ft_exit (rules);
}

void	ft_meal(void *philo)
{
	t_philo	*ph;

	ph = philo;
	ph->strv = ft_time() - ph->rules->start;
	pthread_create(&ph->death, NULL, ft_monitor, ph);
	if (ph->id % 2 == 0)
		my_sleep(ph->rules->time_to_eat);
	while (1)
	{
		sem_wait(ph->rules->forks);
		ft_message(ph, "has taken a fork");
		if (ph->rules->nphilo == 1)
			break ;
		sem_wait(ph->rules->forks);
		ft_message(ph, "has taken a fork");
		ft_message(ph, "is eating");
		ph->eat++;
		ph->strv = ft_time() - ph->rules->start;
		my_sleep(ph->rules->time_to_eat);
		sem_post(ph->rules->forks);
		sem_post(ph->rules->forks);
		ft_message(ph, "is sleeping");
		my_sleep(ph->rules->time_to_sleep);
		ft_message(ph, "is thinking");
	}
}

void	*ft_must_eat(void *rules)
{
	t_rules	*ru;
	int		i;

	ru = rules;
	i = 0;
	while (i < ru->nphilo)
	{
		sem_wait(ru->finish);
		i++;
	}
	i = 0;
	while (i < ru->nphilo)
	{
		kill(ru->philo[i].pid, SIGKILL);
		i++;
	}
	sem_post(ru->isdead);
	return (NULL);
}
