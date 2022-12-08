/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:42:20 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:08:32 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pget_len(unsigned long long int nbr, int size, int is_neg)
{
	int	i;

	i = 0;
	if (is_neg == -1)
		i++;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_p_rc(unsigned long long int nbr, char *base, char *res, int is_neg)
{
	int		i;
	int		size;

	i = 0;
	if (nbr < 0)
		nbr *= -1;
	size = pget_len(nbr, (int)ft_strlen(base), is_neg);
	if (is_neg == -1)
		res[0] = '-';
	if (nbr == 0)
	{
		res[0] = base[0];
		res[1] = '\0';
	}
	while (nbr > 0)
	{
		res[(size - i - 1)] = base[nbr % (int)ft_strlen(base)];
		i++;
		nbr /= (int)ft_strlen(base);
	}
	return (res);
}

char	*ft_putnbr_base(unsigned long long int nbr, char *base, int is_neg)
{
	long int	nb;
	char		*res;
	int			size;
	int			len;

	nb = nbr;
	size = (int)ft_strlen(base);
	len = pget_len(nb, size, is_neg);
	res = (char *) malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	if ((is_neg == -1 && len == 1) || (len == 0 && is_neg == 0))
	{
		res[0] = base[0];
		return (res);
	}
	return (ft_p_rc(nb, base, res, is_neg));
}
