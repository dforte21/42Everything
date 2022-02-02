/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:36:42 by dforte            #+#    #+#             */
/*   Updated: 2021/12/01 12:26:55 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);
int		ft_compare(char *str, char *find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] != 0)
	{
		j = 0;
		if (str[i] == to_find[j])
			flag = ft_compare(&str[i], &to_find[j]);
		if (flag == 1)
			return (&str[i]);
		i++;
	}
	return (0);
}

int	ft_compare(char *str, char *find)
{
	int	i;

	i = 0;
	while (find[i] != 0)
	{
		if (str[i] != find[i])
			return (0);
		else
			i++;
	}
	return (1);
}
