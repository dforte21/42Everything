/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:19 by dforte            #+#    #+#             */
/*   Updated: 2022/01/15 00:45:55 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
	{
		str = ft_calloc(1, sizeof(char));
		str[0] = 0;
		return (str);
	}
	str = ft_calloc(((ft_strlen(s) + 1) - start), sizeof(char));
	if (!str)
		return (NULL);
	while (s[start] != 0 && i < len)
	{
		str[i] = (char)s[start];
		i++;
		start++;
	}
	return (str);
}
