/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:44:04 by dforte            #+#    #+#             */
/*   Updated: 2022/04/26 18:59:17 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int pid;

	if (ac != 3)
	{
		ft_printf("%s\n", "ERROR");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, print_success);
	print_message(pid, av[2]);
	while (1)
		pause();
}

void	print_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_msg(pid, msg[i]);
		usleep(100);
		i++;
	}
	send_msg(pid, 0);
}

void	send_msg(int pid, char msg)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((msg >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("%s\n", "ERROR\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("%s\n", "ERROR\n");
				exit(1);
			}
		}
		i--;
		usleep(100);
	}
}

void	print_success(int num)
{
	num = 7;
	ft_printf("MESSAGGIO STAMPATO CORRETTAMENTE\n");
	exit(0);
}