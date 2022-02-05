/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:00:35 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:03:02 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_uint(t_uint nb, int *count, char *spc)
{
	t_uint	i;
	t_flags	flag;

	init_struct(&flag);
	i = 1;
	check_ufplace(spc, &flag, &i);
	flag.width = ft_atoi(&spc[i]);
	while (ft_isdigit((int)spc[i]))
		i++;
	check_uprecision(spc, i, &flag, nb);
	if (flag.precision == 1)
		flag.zero = 0;
	if (flag.minus == 0)
	{
		print_udwidht(flag, count);
		ft_uputnbr(nb, flag, count);
	}
	else
	{
		ft_uputnbr(nb, flag, count);
		print_udwidht(flag, count);
	}
}

void	check_ufplace(char *s, t_flags *strc, t_uint *i)
{
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

void	check_uprecision(char *s, t_uint i, t_flags *strc, t_uint nb)
{
	strc->len = u_nlen(nb);
	if (s[i] == 46)
	{
		strc->precision = 1;
		if (u_nlen(nb) > ft_atoi(&s[i + 1]))
			strc->len = u_nlen(nb);
		else
			strc->len = ft_atoi(&s[i + 1]);
	}
}

void	print_udwidht(t_flags flag, int *count)
{
	if (flag.zero == 1)
		flag.sep = '0';
	if (flag.plus == 1 || flag.space == 1)
		flag.width--;
	flag.width -= flag.len;
	while (flag.width > 0)
	{
		write(1, &flag.sep, 1);
		*count += 1;
		flag.width--;
	}
}

void	ft_uputnbr(t_uint nb, t_flags flag, int *count)
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
	nbr = ft_uitoa(nb);
	if (flag.nsign == -1)
		ft_uputnnbr(nbr, flag, count, nb);
	else
	{
		print_uzero(flag, nb, count);
		putnstr(nbr, (int)ft_strlen(nbr), count);
	}
	free(nbr);
}
