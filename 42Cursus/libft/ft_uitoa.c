/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:28:23 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:02:25 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*num(void)
{
	char	*num;

	num = ft_calloc(2, sizeof(char));
	num[0] = '0';
	if (!num)
		return (NULL);
	return (num);
}

static size_t	g_len(t_uint n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_uitoa(t_uint n)
{
	char	*nm;
	size_t	len;

	len = g_len(n);
	if (n == 0)
		return (num());
	nm = ft_calloc(len + 1, sizeof(char));
	if (!nm)
		return (NULL);
	while (n > 0)
	{
		nm[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (nm);
}
