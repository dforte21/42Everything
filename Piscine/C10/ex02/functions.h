/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:44:26 by dforte            #+#    #+#             */
/*   Updated: 2021/12/15 23:44:27 by dforte           ###   ########.fr       */
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

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_error(char *file, char *fname);
void	printfh(char *filename);
int		process_start(char *filename, char *fread, char *file);
int		checkf(char *file, char *filename);
int		stdin_f(char **av);
int		print_f(int to_read, char *file, int size);
int		get_flen(char *file, int *size);
int		ft_atoi(char *str);
int		is_space(char *str);
int		calc_sign(char *str, int i, int *sign);
int		get_int(char *str, int j, int sign);

#endif
