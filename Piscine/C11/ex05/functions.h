/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:05:15 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:05:16 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <unistd.h>

int		ft_atoi(char *str);
int		is_space(char *str);
int		calc_sign(char *str, int i, int *sign);
int		get_int(char *str, int j, int sign);
int		checka(char **av);
int		checks(char s[]);
void	do_calc(int a, int b, char sign);
void	putnbr(int nb);
int		print_nop(int nb);
int		count_digit(int nb);
void	print_number(int nb, int digitn);

#endif
