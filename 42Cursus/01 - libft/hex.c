/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:18:09 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:02:46 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_hex(int nb, int *count, char *spc, char *base)
{
	t_uint	i;
	t_flags	flag;
	char	*nbr;

	i = 1;
	init_struct(&flag);
	check_hfplace(spc, &flag, &i, nb);
	nbr = get_hnumber(nb, base, flag);
	flag.width = ft_atoi(&spc[i]);
	while (ft_isdigit((int)spc[i]))
		i++;
	check_hprecision(spc, i, &flag, nbr);
	if (flag.precision == 1)
		flag.zero = 0;
	if (flag.minus == 0)
	{
		print_hwidth(flag, count, nb, base);
		ft_puthex(nbr, flag, count, base);
	}
	else
	{
		ft_puthex(nbr, flag, count, base);
		print_hwidth(flag, count, nb, base);
	}
	free(nbr);
}

void	check_hfplace(char *s, t_flags *strc, t_uint *i, int nb)
{
	if (nb < 0)
		strc->nsign = -1;
	while (s[*i] == 45 || s[*i] == 48 || s[*i] == 35)
	{
		if (s[*i] == 45)
			strc->minus = 1;
		if (s[*i] == 48)
			strc->zero = 1;
		if (s[*i] == 35)
			strc->hashtag = 1;
		*i += 1;
	}
}

void	check_hprecision(char *s, t_uint i, t_flags *strc, char *nbr)
{
	strc->len = ft_strlen(nbr);
	if (s[i] == 46)
	{
		strc->precision = 1;
		if ((int)ft_strlen(nbr) > ft_atoi(&s[i + 1]))
			strc->len = ft_strlen(nbr);
		else
			strc->len = ft_atoi(&s[i + 1]);
	}
}

void	print_hwidth(t_flags flag, int *count, int nb, char *base)
{
	char	ch[3];

	init_ch(ch, base);
	if (nb == 0)
		flag.hashtag = 0;
	if (flag.zero == 1)
		flag.sep = '0';
	if (flag.hashtag == 1 && flag.sep == '0' && flag.minus != 1)
		write (1, ch, 2);
	if (flag.hashtag == 1)
		flag.width -= 2;
	flag.width -= flag.len;
	while (flag.width > 0)
	{
		write(1, &flag.sep, 1);
		*count += 1;
		flag.width--;
	}
	if (flag.hashtag == 1 && flag.sep == ' ' && flag.minus != 1)
		write (1, ch, 2);
}

void	ft_puthex(char *nbr, t_flags flag, int *count, char *base)
{
	char	ch[3];

	init_ch(ch, base);
	if (flag.minus == 1 && flag.hashtag == 1)
		write (1, ch, 2);
	print_hzero(flag, nbr, count);
	putnstr(nbr, (int)ft_strlen(nbr), count);
	if (flag.hashtag == 1 && nbr[0] != '0')
		*count += 2;
}
