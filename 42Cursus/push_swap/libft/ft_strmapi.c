/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:42:51 by dforte            #+#    #+#             */
/*   Updated: 2022/01/13 22:59:23 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		s1[i] = (*f)(i, (char)s[i]);
		i++;
	}
	return (s1);
}
