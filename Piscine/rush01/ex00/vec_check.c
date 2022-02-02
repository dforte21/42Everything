/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:11:04 by dforte            #+#    #+#             */
/*   Updated: 2021/12/05 14:13:52 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	cross_check(int *vec, int i, int n)
{
	int	a;
	int	j;
	int	flag;

	a = (i / 4) * 4;
	flag = 0;
	j = a;
	while (j < a + 4)
	{
		if (vec[j] == n)
			flag++;
		j++;
	}
	a = i % 4;
	while (a < 16 && a >= 0)
	{
		if (vec[a] == n)
			flag++;
		a += 4;
	}
	if (flag == 2)
		return (1);
	return (0);
}

int	lrow_check(int *vet, int *nbr, int i)
{
	int	a;
	int	j;
	int	k;
	int	n;

	a = (i / 4) * 4;
	j = a;
	n = 0;
	k = 0;
	while (j < a + 4)
	{
		if (n < vet[j])
		{
			n = vet[j];
			k++;
		}
		j++;
	}
	a = i / 4;
	if (k == nbr[a + 8])
		return (1);
	return (0);
}

int	rrow_check(int *vet, int *nbr, int i)
{
	int	a;
	int	n;
	int	j;
	int	k;

	a = (i / 4) * 4;
	j = a + 3;
	n = 0;
	k = 0;
	while (j >= a)
	{
		if (n < vet[j])
		{
			n = vet[j];
			k++;
		}
		j--;
	}
	a = i / 4;
	if (k == nbr[a + 12])
		return (1);
	return (0);
}

int	upcol_check(int *vet, int *nbr, int i)
{
	int	n;
	int	j;
	int	k;

	n = 0;
	k = 0;
	j = i - 12;
	while (j < 16)
	{
		if (n < vet[j])
		{
			n = vet[j];
			k++;
		}
		j += 4;
	}
	if (k == nbr[i - 12])
		return (1);
	return (0);
}

int	dwcol_check(int *vet, int *nbr, int i)
{
	int	n;
	int	k;
	int	j;

	n = 0;
	k = 0;
	j = i;
	while (j >= 0)
	{
		if (n < vet[j])
		{
			n = vet[j];
			k++;
		}
		j -= 4;
	}
	if (k == nbr[i - 8])
		return (1);
	return (0);
}
