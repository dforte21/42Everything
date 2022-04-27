/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:41:09 by dforte            #+#    #+#             */
/*   Updated: 2022/04/26 20:00:44 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main()
{
	int	pid;
	struct sigaction ok;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ok.sa_flags = SA_SIGINFO;
	ok.sa_sigaction = build_msg;
	sigaction(SIGUSR1, &ok, NULL);
	sigaction(SIGUSR2, &ok, NULL);
	while (1)
		pause();
}

void	build_msg(int signal, siginfo_t *info, void *niente)
{
	static int	i = 1;
	static char	c = 0;

	niente = NULL;
	if (signal == SIGUSR1)
		c |= 0;
	else
		c |= 1;	
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		i = 1;
		c = 0;
		return ;
	}
	c <<= 1;
	i++;
}