/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:10:15 by dforte            #+#    #+#             */
/*   Updated: 2021/12/02 15:44:34 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	is_space(char *str);
int	calc_sign(char *str, int i, int *sign);
int	get_int(char *str, int j, int sign);

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	sign;
	int	nb;

	sign = 1;
	i = 0;
	j = 0;
	if (str[0] == 0)
		return (0);
	i = is_space(&str[0]);
	j = calc_sign(&str[0], i, &sign);
	nb = get_int(&str[0], j, sign);
	return (nb);
}

int	is_space(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		if (str[i] >= 9 && str[i] <= 13)
			flag = 1;
		if (str[i] == 32)
			flag = 1;
		if (flag == 1)
			i++;
	}
	return (i);
}

int	calc_sign(char *str, int i, int *sign)
{
	int	j;

	j = i;
	while (str[j] == 43 || str[j] == 45)
	{
		if (str[j] == 43)
			*sign *= 1;
		else
			*sign *= -1;
		j++;
	}
	return (j);
}

int	get_int(char *str, int j, int sign)
{
	int	nb;
	int	a;

	nb = 0;
	while (str[j] >= 48 && str[j] <= 57)
	{
		a = str[j] - '0';
		nb = nb * 10 + a;
		j++;
	}
	nb *= sign;
	return (nb);
}
