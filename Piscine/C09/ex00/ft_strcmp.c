/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:32:18 by dforte            #+#    #+#             */
/*   Updated: 2021/11/30 15:48:17 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

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
			return (n1 - n2);
		if (n1 > n2)
			return (n1 - n2);
		i++;
	}
	return (0);
}
