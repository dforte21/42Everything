/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:00:42 by dforte            #+#    #+#             */
/*   Updated: 2022/01/23 04:07:18 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef unsigned int	t_uint;

typedef struct s_flags
{
	int		minus;
	int		width;
	int		len;
	int		zero;
	int		space;
	int		plus;
	int		hashtag;
	int		precision;
	int		nsign;
	char	sep;
}				t_flags;

int		ft_printf(const char *print, ...);
int		checkch(char c);
int		arg_print(const char *print, int *count, va_list args, size_t index);
int		c_minus(t_uint *i, char *spc);
int		get_len(unsigned long long int nbr, int size, int is_neg);
int		nlen(int nb);
int		u_nlen(t_uint nb);
char	*ft_p_rc(unsigned long long int nbr, char *base, char *res, int is_neg);
char	*ft_putnbr_base(unsigned long long int nbr, char *base, int is_neg);
char	*ft_uitoa(t_uint n);
char	*get_hnumber(int nb, char *base, t_flags flag);
char	*get_paddr(long int addr, char *base, t_flags flag);
void	print_arg(char *spc, va_list arg, int *count, int ch);
void	p_char(int c, int *count, char *spc);
void	p_string(char *s, int *count, char *spc);
void	p_pointer(long int addr, int *count, char *spc);
void	putnstr(char *s, int len, int *count);
void	print_widht(t_flags flags, int *count, char ch);
void	init_struct(t_flags	*strct);
void	p_digit(int nb, int *count, char *spc);
void	check_fplace(char *s, t_flags *strc, int nb, t_uint *i);
void	check_precision(char *s, t_uint i, t_flags *strc, int nb);
void	print_dwidht(t_flags flag, int *count);
void	ft_putnbr(int nb, t_flags flag, int *count);
void	ft_putnnbr(char *nbr, t_flags flag, int *count, int nb);
void	print_zero(t_flags strc, int nb, int *count);
void	p_uint(t_uint nb, int *count, char *spc);
void	check_ufplace(char *s, t_flags *strc, t_uint *i);
void	check_uprecision(char *s, t_uint i, t_flags *strc, t_uint nb);
void	print_udwidht(t_flags flag, int *count);
void	ft_uputnbr(t_uint nb, t_flags flag, int *count);
void	ft_uputnnbr(char *nbr, t_flags flag, int *count, t_uint nb);
void	p_hex(int nb, int *count, char *spc, char *base);
void	print_uzero(t_flags strc, t_uint nb, int *count);
void	check_hfplace(char *s, t_flags *strc, t_uint *i, int nb);
void	print_hwidth(t_flags flag, int *count, int nb, char *base);
void	ft_puthex(char *nbr, t_flags flag, int *count, char *base);
void	check_hprecision(char *s, t_uint i, t_flags *strc, char *nbr);
void	all_nhex(char *nhex);
void	print_hzero(t_flags strc, char *nbr, int *count);
void	init_ch(char *ch, char *base);

#endif