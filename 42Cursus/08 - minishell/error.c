/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:19:00 by dforte            #+#    #+#             */
/*   Updated: 2022/11/24 16:31:49 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_syntax_error(void)
{
	write(STDERR_FILENO, "minishell: syntax error\n", 25);
	return (1);
}

int	ft_char_error(char *str, int i, char c)
{
	int	j;

	j = i + 1;
	while (((str[j] != c && str[j] != '|') || j == i + 1) && str[j])
	{
		if (str[j] != ' ' && j != i + 1)
			break ;
		j++;
	}
	if (str[j] == '\0' || str[j] == c || str[j] == '|')
		return (1);
	return (0);
}

int	ft_check_char(char *str, char c)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != c)
			flag = 1;
		i = ft_skip_quotes(str, i, '\"');
		i = ft_skip_quotes(str, i, '\'');
		if (i == -1)
			return (ft_syntax_error());
		if (str[i] == c)
			if ((flag == 0 && (c != '<' && c != '>'))
				|| ft_char_error(str, i, c))
				return (ft_syntax_error());
		i++;
	}
	return (0);
}

int	ft_parparenthesis(char **matrix, int row)
{
	char	*open;
	char	*close;

	open = NULL;
	close = NULL;
	open = ft_skip_strchr(matrix[row], '(');
	close = ft_skip_strrchr(matrix[row], ')');
	if (!open || !close)
	{
		ftfree(matrix);
		return (1);
	}
	return (0);
}

int	ft_check_syntax(char *str)
{
	char	**matrix;
	int		row;

	matrix = ft_smart_split(str, '|');
	if (matrix == NULL)
		return (ft_syntax_error());
	row = 0;
	while (matrix[row])
	{
		if (ft_skip_strchr(matrix[row], '(')
			|| ft_skip_strchr(matrix[row], ')'))
			if (ft_parparenthesis(matrix, row))
				return (ft_syntax_error());
		row++;
	}
	ftfree(matrix);
	return (0);
}
