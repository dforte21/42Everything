/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:09:27 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 09:09:29 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <libgen.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		read_stdin(char **av);
void	print_f(int file);
void	print_error(char *file, char *fname);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
