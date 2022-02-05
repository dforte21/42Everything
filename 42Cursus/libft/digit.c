/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:36:12 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:01:48 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_digit(int nb, int *count, char *spc)
{
	t_uint	i;
	t_flags	flag;

	init_struct(&flag);
	i = 1;
	check_fplace(spc, &flag, nb, &i);
	flag.width = ft_atoi(&spc[i]);
	while (ft_isdigit((int)spc[i]))
		i++;
	check_precision(spc, i, &flag, nb);
	if (flag.precision == 1)
		flag.zero = 0;
	if (flag.minus == 0)
	{
		print_dwidht(flag, count);
		ft_putnbr(nb, flag, count);
	}
	else
	{
		ft_putnbr(nb, flag, count);
		print_dwidht(flag, count);
	}
}

void	check_fplace(char *s, t_flags *strc, int nb, t_uint *i)
{
	if (nb < 0)
		strc->nsign = -1;
	while (s[*i] == 45 || s[*i] == 32 || s[*i] == 43 || s[*i] == 48)
	{
		if (s[*i] == 45)
			strc->minus = 1;
		if (s[*i] == 32 && strc->nsign == 0)
			strc->space = 1;
		if (s[*i] == 43 && strc->nsign == 0)
			strc->plus = 1;
		if (s[*i] == 48)
			strc->zero = 1;
		*i += 1;
	}
}

void	check_precision(char *s, t_uint i, t_flags *strc, int nb)
{
	strc->len = nlen(nb);
	if (s[i] == 46)
	{
		strc->precision = 1;
		if (nlen(nb) > ft_atoi(&s[i + 1]))
			strc->len = nlen(nb);
		else
			strc->len = ft_atoi(&s[i + 1]);
	}
}

void	print_dwidht(t_flags flag, int *count)
{
	if (flag.zero == 1)
		flag.sep = '0';
	if (flag.nsign == -1 && flag.sep == '0' && flag.minus != 1)
		write (1, "-", 1);
	if (flag.nsign == -1)
		flag.width--;
	if (flag.plus == 1 || flag.space == 1)
		flag.width--;
	flag.width -= flag.len;
	while (flag.width > 0)
	{
		write(1, &flag.sep, 1);
		*count += 1;
		flag.width--;
	}
	if (flag.nsign == -1 && flag.sep == ' ' && flag.minus != 1)
		write (1, "-", 1);
}

void	ft_putnbr(int nb, t_flags flag, int *count)
{
	char	*nbr;

	if (flag.plus == 1)
	{
		write(1, "+", 1);
		*count += 1;
	}
	if (flag.space == 1)
	{
		write(1, " ", 1);
		*count += 1;
	}
	nbr = ft_itoa(nb);
	if (flag.nsign == -1)
		ft_putnnbr(nbr, flag, count, nb);
	else
	{
		print_zero(flag, nb, count);
		putnstr(nbr, (int)ft_strlen(nbr), count);
	}
	free(nbr);
}
