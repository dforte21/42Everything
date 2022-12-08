/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:58:55 by dforte            #+#    #+#             */
/*   Updated: 2022/01/14 20:40:37 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] != 0)
		i++;
	if (i == 0)
	{
		dest = ft_calloc(1, sizeof(char));
		return (dest);
	}
	dest = ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
