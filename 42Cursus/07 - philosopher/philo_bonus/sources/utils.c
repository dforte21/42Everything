/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:11:19 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 19:08:02 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phbonus.h"

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

void	ft_message(t_philo *ph, char *msg)
{
	sem_wait(ph->rules->msg);
	printf("%lld %d %s\n", ft_time() - ph->rules->start, ph->id, msg);
	sem_post(ph->rules->msg);
}
