/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phbonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:47:46 by dforte            #+#    #+#             */
/*   Updated: 2022/06/23 19:26:16 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phbonus.h"

static sem_t	*ft_semaphore(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, value));
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (!check_args(ac, av))
		return (1);
	initialize_arg(ac, av, &rules);
	initialize_philo(&rules);
	ft_thread(&rules);
	return (0);
}

void	initialize_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nphilo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].eat = 0;
		rules->philo[i].rules = rules;
		i++;
	}
}

void	initialize_arg(int ac, char **av, t_rules *rules)
{
	int	i;

	i = 0;
	rules->nphilo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules->must_eat = ft_atoi(av[5]);
	else
		rules->must_eat = -1;
	rules->msg = ft_semaphore("/message", 1);
	rules->forks = ft_semaphore("/forks", rules->nphilo);
	rules->isdead = ft_semaphore("/dead", 0);
	rules->finish = ft_semaphore("/must_eat", 0);
	rules->philo = malloc(sizeof(t_philo) * rules->nphilo);
}
