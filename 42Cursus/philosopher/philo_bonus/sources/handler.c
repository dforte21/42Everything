/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:17:02 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 19:39:01 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phbonus.h"

void	*ft_monitor(void *philo)
{
	t_philo	*ph;

	ph = philo;
	while (1)
	{
		if (ft_finish(ph) == 1)
			break ;
	}
	return (NULL);
}

int	ft_finish(t_philo *philo)
{
	int	tmp;

	tmp = ft_time() - philo->rules->start;
	if (philo->eat == philo->rules->must_eat)
	{
		sem_post(philo->rules->finish);
		return (1);
	}
	if (tmp - philo->strv > philo->rules->time_to_die)
	{
		sem_wait(philo->rules->msg);
		printf("%lld %d died\n", ft_time() - philo->rules->start, philo->id);
		sem_post(philo->rules->isdead);
		return (1);
	}
	return (0);
}

void	ft_exit(t_rules *rules)
{
	int		i;

	i = 0;
	while (i < rules->nphilo)
	{
		kill(rules->philo[i].pid, SIGKILL);
		i++;
	}
	sem_close(rules->forks);
	sem_unlink("/forks");
	sem_close(rules->msg);
	sem_unlink("/message");
	sem_close(rules->isdead);
	sem_unlink("/dead");
	sem_close(rules->finish);
	sem_unlink("/must_eat");
	free(rules->philo);
}
