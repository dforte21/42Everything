/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:10:40 by dforte            #+#    #+#             */
/*   Updated: 2021/12/05 14:58:47 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char **argv)
{
	int	nbr[16];
	int	a[16];

	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	if (!(check(argv[1])))
	{
		ft_error();
		return (0);
	}
	ft_erase(argv[1], nbr, ' ');
	get_comb(nbr, a);
}
