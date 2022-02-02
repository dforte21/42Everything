/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_results.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:10:27 by dforte            #+#    #+#             */
/*   Updated: 2021/12/05 15:04:03 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	print_mat(int a[16])
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)
	{
		c = a[i] + '0';
		write(1, &c, 1);
		if (i == 3 || i == 7 || i == 11 || i == 15)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

void	get_comb(int nbrs[16], int results[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		results[i] = 0;
		i++;
	}
	i = 0;
	do_backtracking(nbrs, results, i, 0);
	if (results[0] == 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	print_mat(results);
}

void	do_backtracking(int nbrs[16], int results[16], int i, int flag)
{
	results[i]++;
	if (!(is_five(nbrs, results, i)))
		return ;
	if (!(cross_check(results, i, results[i])))
		flag = 1;
	if (i == 3 || i == 7 || i == 11 || i == 15)
	{
		if (!(lrow_check(results, nbrs, i))
			|| !(rrow_check(results, nbrs, i)))
			flag = 1;
	}
	if (i >= 12 && i <= 15)
	{
		if (!(upcol_check(results, nbrs, i))
			|| !(dwcol_check(results, nbrs, i)))
			flag = 1;
	}
	if (flag == 0)
		i++;
	if (i < 16 && i >= 0)
		do_backtracking(nbrs, results, i, 0);
}

int	is_five(int nbrs[16], int results[16], int i)
{
	if (results[i] == 5)
	{
		results[i] = 0;
		do_backtracking(nbrs, results, i - 1, 0);
		return (0);
	}
	return (1);
}
