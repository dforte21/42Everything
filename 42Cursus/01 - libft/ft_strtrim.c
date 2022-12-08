/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:39:15 by dforte            #+#    #+#             */
/*   Updated: 2022/01/14 22:50:41 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_coord(char const *s1, char const *set, int *i, int *j)
{
	int	k;
	int	flag;

	k = 0;
	*i = 0;
	*j = 0;
	flag = 0;
	while (checkchar(s1[k], set))
		k++;
	*i = k;
	while (s1[k] != 0)
	{
		if (checkchar(s1[k], set) && flag == 0)
		{
			*j = k;
			flag = 1;
		}
		if (!checkchar(s1[k], set))
			flag = 0;
		k++;
	}
	if (flag == 0)
		*j = k;
	return (*j - *i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;
	int		k;

	k = 0;
	len = get_coord(s1, set, &i, &j);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[k] = (char)s1[i];
		k++;
		i++;
	}
	return (str);
}
