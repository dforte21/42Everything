/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:31:32 by dforte            #+#    #+#             */
/*   Updated: 2021/12/03 11:26:12 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	get_size(char *base);
int	get_nbsize(char *str, char *base);
int	get_int(char *str, char *base, int i, int size);
int	get_pow(int a, int b);

int	ft_atoi_base(char *str, char *base)
{
	int	size;
	int	i;
	int	nb;

	size = get_size(&base[0]);
	if (size == 0)
		return (0);
	i = get_nbsize(&str[0], &base[0]);
	if (i < 0)
		return (0);
	nb = get_int(&str[0], &base[0], i, size);
	return (nb);
}

int	get_size(char *base)
{
	int	size;
	int	i;
	int	flag;

	size = 0;
	flag = 0;
	while (base[size] != 0)
	{
		i = size + 1;
		while (base[i] != 0)
		{
			if (base[size] == base[i])
				flag = 1;
			i++;
		}
		if (base[size] == 43 || base[size] == 45)
			flag = 1;
		size++;
	}
	if (size <= 1 || flag == 1)
		return (0);
	return (size);
}

int	get_nbsize(char *str, char *base)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	if (str[j] == 0)
		return (0);
	while (str[j] != 0)
	{
		i = 0;
		flag = 1;
		while (base[i] != 0 && flag == 1)
		{
			if (str[j] != base[i] && str[j] != 45)
				flag = 1;
			else
				flag = 0;
			i++;
		}
		if (flag == 1)
			return (-1);
		j++;
	}
	return (j - 1);
}

int	get_int(char *str, char *base, int i, int size)
{
	int	j;
	int	k;
	int	sign;
	int	a;

	k = 0;
	sign = 1;
	a = 0;
	while (str[k] != 0)
	{
		j = 0;
		if (str[k] == 45)
			sign = -1;
		while (str[k] != base[j] && str[k] != 45)
			j++;
		if (sign == -1)
			a = (a + ((j * (get_pow(size, i))) * sign));
		else
			a = a + (j * (get_pow(size, i)));
		k++;
		i--;
	}
	return (a);
}

int	get_pow(int a, int b)
{
	int	na;

	na = a;
	if (b == 0)
		return (1);
	if (b == 1)
		return (a);
	while (b > 1)
	{
		na = na * a;
		b--;
	}
	return (na);
}
