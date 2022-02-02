/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:48:34 by dforte            #+#    #+#             */
/*   Updated: 2022/01/15 00:20:11 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (c == 0)
	{
		while (str[i] != 0)
			i++;
		return ((char *)&str[i]);
	}
	while (str[i] != 0)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *)&str[j]);
	return (NULL);
}
