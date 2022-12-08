/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:23 by dforte            #+#    #+#             */
/*   Updated: 2022/05/14 16:37:07 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

//client
void	print_message(int pid, char *msg);
void	send_msg(int pid, char msg);
void	build_msg(int signal, siginfo_t *info, void *niente);
void	print_success(int num);
int		checkargs(int ac, char **av);

#endif