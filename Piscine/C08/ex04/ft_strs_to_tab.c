/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:38:13 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 21:16:25 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
int					str_len(char *str);
void				str_cpy(char str[], t_stock_str *strs);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_strs;
	int			i;

	i = 0;
	s_strs = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(s_strs))
		return (NULL);
	while (i < ac)
	{
		if (!(av[i]))
			return (NULL);
		s_strs[i].size = str_len(av[i]);
		s_strs[i].str = av[i];
		str_cpy(av[i], &s_strs[i]);
		i++;
	}
	s_strs[i].str = NULL;
	return (s_strs);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	str_cpy(char str[], t_stock_str *strs)
{
	int	i;

	i = 0;
	strs->copy = malloc(sizeof(char) * (strs->size + 1));
	while (str[i] != 0)
	{
		strs->copy[i] = str[i];
		i++;
	}
	strs->copy[i] = 0;
}
