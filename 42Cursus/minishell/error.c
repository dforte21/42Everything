#include "minishell.h"

int	ft_syntax_error(void)
{
	write(STDERR_FILENO, "minishell: syntax error\n", 25);
	return(1);
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
		if (str[i] == c)
			if (flag == 0 || ft_char_error(str, i, c))
				return (1);
		i++;
	}
	return (0);
}

int	ft_check_syntax(char *str)
{
	if (ft_check_char(str, '|') || ft_check_char(str, '&'))
	{
		free(str);
		return (ft_syntax_error());
	}
	return (0);
}
