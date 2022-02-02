/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:11:22 by dforte            #+#    #+#             */
/*   Updated: 2021/12/16 12:11:23 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_string_tab(char **tab);
int		ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]))
			{
				ptr = tab[i];
				tab[i] = tab[j];
				tab[j] = ptr;
			}
			j++;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n1;
	int	n2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		n1 = (int)s1[i];
		n2 = (int)s2[i];
		if (n1 < n2)
			return (0);
		if (n1 > n2)
			return (1);
		i++;
	}
	return (0);
}
