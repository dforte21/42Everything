/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:28:23 by dforte            #+#    #+#             */
/*   Updated: 2022/01/14 22:48:46 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*num(int n)
{
	char	*num;

	if (n == -2147483648)
	{
		num = ft_calloc(12, sizeof(char));
		num[0] = '-';
		num[1] = '2';
		num[2] = '1';
		num[3] = '4';
		num[4] = '7';
		num[5] = '4';
		num[6] = '8';
		num[7] = '3';
		num[8] = '6';
		num[9] = '4';
		num[10] = '8';
	}
	else
	{
		num = ft_calloc(2, sizeof(char));
		num[0] = '0';
	}
	if (!num)
		return (NULL);
	return (num);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	get_len(int n)
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

char	*ft_itoa(int n)
{
	char	*nm;
	size_t	len;

	len = get_len(ft_abs(n));
	if (n == -2147483648 || n == 0)
		return (num(n));
	if (n < 0)
	{
		nm = ft_calloc(len + 2, sizeof(char));
		n *= -1;
		nm[0] = 45;
		len++;
	}
	else
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
