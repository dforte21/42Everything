/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:04:36 by dforte            #+#    #+#             */
/*   Updated: 2022/01/14 21:31:49 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count(char *dest, char *src, size_t *a, size_t size)
{
	size_t		j;

	*a = 0;
	j = 0;
	while (dest[*a] != 0 && size > 0)
	{
		*a += 1;
		size--;
	}
	while (src[j] != 0)
	{
		*a += 1;
		j++;
	}
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	a;
	size_t	j;
	size_t	k;

	ft_count(&dest[0], &src[0], &a, size);
	if (ft_strlen(dest) > size)
		return (a);
	j = 0;
	k = 0;
	while (dest[j])
		j++;
	if (size == 0)
		return (a);
	while (src[k] != 0 && j < (size - 1))
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	dest[j] = '\0';
	return (a);
}
