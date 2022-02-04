/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:45:50 by dforte            #+#    #+#             */
/*   Updated: 2022/02/04 13:14:08 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*str;
	size_t		i;

	i = 0;
	if (fd < 0 || fd > 1024)
		return (NULL);
	save[fd] = get_line(save[fd], fd);
	if (!save[fd])
		return (NULL);
	while (save[fd][i] != '\n' && save[fd][i])
		i++;
	str = ft_substr(save[fd], 0, i + 1);
	save[fd] = ft_save(save[fd], str);
	return (str);
}

char	*get_line(char *save, int fd)
{
	int		count;
	char	*buffer;

	count = 1;
	if (!save)
		save = ft_calloc(1, 1);
	while (ft_strchr(save, '\n') == -1 && count > 0)
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0 || (count == 0 && save[0] == 0))
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		save = ft_strjoin(save, buffer);
		free(buffer);
	}
	return (save);
}

char	*ft_save(char *save, char *str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
		i++;
	if (save[i] == 0)
	{
		free(save);
		return (NULL);
	}
	tmp = ft_substr(save, i, ft_strlen(save) - i);
	free(save);
	save = ft_substr(tmp, 0, ft_strlen(tmp));
	free(tmp);
	return (save);
}
