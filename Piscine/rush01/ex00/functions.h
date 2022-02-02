/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:17:13 by dforte            #+#    #+#             */
/*   Updated: 2021/12/05 14:59:41 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <unistd.h>

void	get_comb(int nbrs[16], int results[16]);
void	print_mat(int a[16]);
void	do_backtracking(int nbrs[16], int results[16], int i, int flag);
void	ft_erase(char *str, int dest[16], char c);
void	ft_putchar(char c);
void	ft_error(void);
int		is_five(int nbrs[16], int results[16], int i);
int		cross_check(int *vec, int i, int n);
int		lrow_check(int *vet, int *nbr, int i);
int		rrow_check(int *vet, int *nbr, int i);
int		upcol_check(int *vet, int *nbr, int i);
int		dwcol_check(int *vet, int *nbr, int i);
int		ft_strlen(char *str);
int		check(char *str);

#endif
