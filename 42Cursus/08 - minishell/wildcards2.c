/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:40:26 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 17:57:42 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_dir(int row)
{
	DIR				*d;
	struct dirent	*dir;
	char			**matrix;

	d = opendir(".");
	matrix = (char **) malloc (sizeof(char *) * (ft_dirlen() + 1));
	dir = readdir(d);
	row = 0;
	while (dir != NULL)
	{
		if (dir->d_name[0] == '.')
		{
			dir = readdir(d);
			continue ;
		}
		matrix[row] = malloc(sizeof(char) * (ft_strlen(dir->d_name) + 2));
		ft_strlcpy(matrix[row], dir->d_name, ft_strlen(dir->d_name) + 1);
		matrix[row][ft_strlen(dir->d_name)] = ' ';
		matrix[row][ft_strlen(dir->d_name) + 1] = '\0';
		row++;
		dir = readdir(d);
	}
	matrix[row] = NULL;
	closedir(d);
	return (matrix);
}

char	*checkstr(char *str, char **dir)
{
	char	*dst;

	str = ft_no_quotes(str);
	if (ft_strlen(str) == 1)
	{
		free(str);
		dst = ft_multijoin(dir);
		free(dir);
		return (dst);
	}
	return (NULL);
}

char	*ft_wildcard(char *str, char **dir)
{
	char	**wild;
	char	*dst;

	dst = checkstr(str, dir);
	if (dst)
		return (dst);
	wild = ft_split(str, '*');
	if (str[0] != '*')
		dir = ft_first_last(wild[0], dir, 0);
	if (str[ft_strlen(str) - 1] != '*')
		dir = ft_first_last(wild[ft_matlen(wild) - 1], dir, 1);
	dir = ft_between(wild, dir);
	ftfree(wild);
	if (dir[0] == NULL)
	{
		free(dir);
		return (str);
	}
	dst = ft_multijoin(dir);
	free(dir);
	free(str);
	return (dst);
}
