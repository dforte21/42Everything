#include "minishell.h"

int	ft_syntax_error(void)
{
	printf("minishell: syntax error\n");
	return(1);
}

int	ft_char_error(char *str, int x, char c)
{
	int	i;

	i = x - 1;
	while (i >= 0 && str[i] != c)
	{
		if (str[i] == ' ')
			i--;
		else
			break;
	}
	if (i == -1 || str[i] == c)
		return (ft_syntax_error());
	i = x + 1;
	while (str[i] != '\0' && str[i] != c)
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	if (str[i] == '\0' || str[i] == c)
		return (ft_syntax_error());
	return (0);
}

int	ft_parse_error(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] == c)
				i++;
			else if (ft_char_error(str, i, c))
					return(1);
		}
		i++;
	}
	return (0);
}

int	ft_check_line(char *str)
{
	int	i;

	if (ft_parse_error(str, '|') || ft_parse_error(str, '>') || ft_parse_error(str, '<'))
		return (1);
	i = 0;
	while (str[i])
	{
		i = ft_skip_quotes(str, i, '\'');
		if (i == -1)
			return (ft_syntax_error());
		i = ft_skip_quotes(str, i, '\"');
		if (i == -1)
			return (ft_syntax_error());
		i++;
	}
	return (0);
}