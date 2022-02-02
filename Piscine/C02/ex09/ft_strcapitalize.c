/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:47:33 by dforte            #+#    #+#             */
/*   Updated: 2021/11/29 17:05:33 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		check_digit(char str);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;
	int	flag2;

	i = 0;
	flag = 0;
	flag2 = 0;
	while (str[i] != '\0')
	{
		flag2 = check_digit(str[i]);
		if (flag2 == 0)
		{
			if ((flag == 0) && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			if ((flag == 1) && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		i++;
	}
	return (str);
}

int	check_digit(char str)
{
	int	flag;

	flag = 0;
	if (str > '9' && str < 'A')
		flag = 1;
	if (str > 'Z' && str < 'a')
		flag = 1;
	if (str < '0' || str > 'z')
		flag = 1;
	if (flag == 0)
		return (0);
	return (1);
}
