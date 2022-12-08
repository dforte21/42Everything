/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:56:15 by dforte            #+#    #+#             */
/*   Updated: 2022/02/01 17:25:34 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*str;
	size_t	i;
	t_uint	j;

	i = 0;
	j = 0;
	if ((t_uint)ft_strlen(s) < start)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (str);
	while (s1[i] != 0)
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = (char)s2[j];
		i++;
		j++;
	}
	free(s1);
	return (str);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*p;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	p = (char *)ptr;
	while (i < size * count)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
