/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:15:38 by dforte            #+#    #+#             */
/*   Updated: 2022/01/14 22:37:01 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_copy(char *str, char const *s, size_t len, int *flag)
{
	*flag = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s, len + 1);
	return (str);
}

static void	do_split(char **str, char const *s, char c, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		flag;

	i = 0;
	j = 0;
	k = 0;
	flag = 0;
	while (k < len)
	{
		if (s[j] != c && flag == 0)
		{
			i = j;
			flag = 1;
		}
		if ((s[j] == c || s[j] == 0) && flag == 1)
		{
			str[k] = do_copy(str[k], &s[i], j - i, &flag);
			k++;
		}
		j++;
	}
}

static size_t	count_strs(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s[j] != 0)
	{
		if (s[j] != c && flag == 0)
		{
			i++;
			flag = 1;
		}
		if (s[j] == c)
			flag = 0;
		j++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;

	len = count_strs(s, c);
	str = malloc((len + 1) * sizeof(char *));
	str[len] = NULL;
	if (!str)
		return (NULL);
	if (len == 0)
		return (str);
	do_split(str, s, c, len);
	return (str);
}
