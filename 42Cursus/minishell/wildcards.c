#include "minishell.h"

int		ft_dirlen(void)
{
	DIR				*d;
	struct dirent	*dir;
	int				row;

	d = opendir(".");
	dir = readdir(d);
	row = 0;
	while (dir != NULL)
	{
		if(dir->d_name[0] == '.')
		{
			dir = readdir(d);
			continue ;
		}
		row++;
		dir = readdir(d);
	}
	closedir(d);
	return (row);
}

char	**ft_get_dir(void)
{
	DIR				*d;
	struct dirent	*dir;
	char			**matrix;
	int				row;

	d = opendir(".");
	matrix = (char **) malloc (sizeof(char *) * (ft_dirlen() + 1));
	dir = readdir(d);
	row = 0;
	while (dir != NULL)
	{
		if(dir->d_name[0] == '.')
		{
			dir = readdir(d);
			continue ;
		}
		matrix[row] = (char *) malloc (sizeof(char) * (ft_strlen(dir->d_name) + 2));
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

char	**ft_first_last(char *str, char **dir, int flag)
{
	int	len;
	int	row;

	len = ft_strlen(str);
	row = 0;
	if (!flag)
	{
		while (dir[row])
		{
			if (ft_strncmp(dir[row], str, len))
				dir = ft_delrow(dir, row);
			else
				row++;
		}
		return (dir);
	}
	while (dir[row])
	{
		if (ft_strncmp(&dir[row][ft_strlen(dir[row]) - (len + 1)], str, len))
			dir = ft_delrow(dir, row);
		else
			row++;
	}
	return (dir);
}

char	**ft_between(char **wild, char **dir)
{
	int		row;
	int		col;
	int		i;

	row = 0;
	while (dir[row])
	{
		i = 0;
		col = 0;
		while (dir[row][col])
		{
			if (!ft_strncmp(&dir[row][col], wild[i], ft_strlen(wild[i])))
				i++;
			if (wild[i] == NULL)
				break ;
			col++;
		}
		if (wild[i] != NULL)
			dir = ft_delrow(dir, row);
		else
			row++;
	}
	return (dir);
}

char	*ft_wildcard(char *str, char **dir)
{
	char	**wild;
	char	*dst;

	str = ft_no_quotes(str);
	if (ft_strlen(str) == 1)
	{
		free(str);
		dst = ft_multijoin(dir);
		free(dir);
		return (dst);
	}
	wild = ft_split(str, '*');
	if (str[0] != '*')
		dir = ft_first_last(wild[0], dir, 0);
	if (str[ft_strlen(str) - 1] != '*')
		dir = ft_first_last(wild[ft_matlen(wild) - 1], dir, 1);
	dir = ft_between(wild, dir);
	ftFree(wild);
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

char	*ft_asterisk(char *src, int *i)
{
	char	*matrix[4];
	char	*dst;
	int		j;

	j = *i;
	while (src[j] != ' ' && j >= 0)
		j--;
	matrix[0] = ft_substr(src, 0, j + 1);
	while (src[*i] != ' ' && src[*i])
		*i += 1;
	matrix[2] = ft_substr(src, *i, ft_strlen(src));
	matrix[1] = ft_wildcard(ft_substr(src, j + 1, *i - j - 1), ft_get_dir());
	matrix[3] = NULL;
	dst = ft_multijoin(matrix);
	return (dst);
}
