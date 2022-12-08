/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:51:47 by dforte            #+#    #+#             */
/*   Updated: 2022/01/15 18:46:38 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] != 0 && i < len)
	{
		while (str[i + j] == needle[j] && (i + j) < len)
			j++;
		if (needle[j] == 0)
			return ((char *)&str[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
