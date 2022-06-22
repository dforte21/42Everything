/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:55 by dforte            #+#    #+#             */
/*   Updated: 2022/06/22 22:37:11 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(void)
{
	return (1);
}

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	my_sleep(long long time)
{
	long long	tmp;

	tmp = ft_time();
	usleep(time * 1000 - 20000);
	while (ft_time() < tmp + time)
		continue ;
}

bool	check_mutex(int flag, t_philo *philo)
{
	bool	tmp;

	tmp = TRUE;
	if (flag == 0)
	{
		pthread_mutex_lock(&philo->rules->die_mutex);
		tmp = philo->rules->isdeath;
		pthread_mutex_unlock(&philo->rules->die_mutex);
	}
	if (flag == 1)
	{
		pthread_mutex_lock(&philo->rules->must_eat_mutex);
		tmp = philo->end;
		pthread_mutex_unlock(&philo->rules->must_eat_mutex);
	}
	return (tmp);
}

void	ft_message(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->rules->philo_time);
	printf("%lld %d %s\n", ft_time() - ph->rules->start, ph->id, msg);
	pthread_mutex_unlock(&ph->rules->philo_time);
}
