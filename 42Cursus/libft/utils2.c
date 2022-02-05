/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:09:44 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:03:45 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_zero(t_flags strc, int nb, int *count)
{
	while (strc.len > nlen(nb))
	{
		write (1, "0", 1);
		*count += 1;
		strc.len--;
	}
}

void	print_uzero(t_flags strc, t_uint nb, int *count)
{
	while (strc.len > u_nlen(nb))
	{
		write (1, "0", 1);
		*count += 1;
		strc.len--;
	}
}

void	print_hzero(t_flags strc, char *nbr, int *count)
{
	while (strc.len > (int)ft_strlen(nbr))
	{
		write (1, "0", 1);
		*count += 1;
		strc.len--;
	}
}

int	u_nlen(t_uint nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	all_nhex(char *nhex)
{
	nhex = ft_calloc(10, 1);
	nhex = "100000000";
}
