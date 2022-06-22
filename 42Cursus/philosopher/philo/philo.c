/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:27:14 by dforte            #+#    #+#             */
/*   Updated: 2022/06/22 19:45:43 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules rules;

	//if (!check_args(ac, av))
	//	return (ft_error());
	initialize_arg(ac, av, &rules);
	initialize_philo(&rules);	
	initialize_mutex(&rules);

	ft_thread(&rules);
}

void	initialize_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nphilo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].isdeath = FALSE;
		rules->philo[i].eat = 0;
		rules->philo[i].end = FALSE;
		rules->philo[i].rules = rules;
		rules->philo[i].left = &rules->forks[i];
		rules->philo[i].right = &rules->forks[i + 1];
		if (i == rules->nphilo - 1)
			rules->philo[i].right = &rules->forks[0];
		i++;
	}
}

void	initialize_arg(int ac, char **av, t_rules *rules)
{
	int	i;

	i = 0;
	rules->nphilo = ft_atoi(av[1]);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nphilo);
	rules->philo = malloc(sizeof(t_philo) * rules->nphilo);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->must_eat = ft_atoi(av[5]);
	else
		rules->must_eat = -1;
	while (i < rules->nphilo) 
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
}

void	initialize_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_init(&rules->philo_time, NULL);
	pthread_mutex_init(&rules->die_mutex, NULL);
	pthread_mutex_init(&rules->lock, NULL);
	pthread_mutex_init(&rules->must_eat_mutex, NULL);
}

//int	check_args(int ac, char **av)
//{
//	return (1);
//}
