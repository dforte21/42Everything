/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:08:17 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:02:40 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_arg(char *spc, va_list arg, int *count, int ch)
{
	if (ch == 1)
		p_char(va_arg(arg, int), count, spc);
	if (ch == 2)
		p_string(va_arg(arg, char *), count, spc);
	if (ch == 3)
		p_pointer(va_arg(arg, long int), count, spc);
	if (ch == 4 || ch == 5)
		p_digit(va_arg(arg, int), count, spc);
	if (ch == 6)
		p_uint(va_arg(arg, t_uint), count, spc);
	if (ch == 7)
		p_hex(va_arg(arg, int), count, spc, "0123456789abcdef");
	if (ch == 8)
		p_hex(va_arg(arg, int), count, spc, "0123456789ABCDEF");
	if (ch == 9)
	{
		write(1, "%", 1);
		*count += 1;
	}
}

int	arg_print(const char *print, int *count, va_list args, size_t index)
{
	int		ch;
	size_t	i;
	char	*spc;

	i = 1;
	while (checkch(print[i]) == 0)
		i++;
	ch = checkch(print[i]);
	spc = ft_calloc((i + 1), sizeof(char));
	if (!spc)
		return (0);
	ft_strlcpy(spc, (char *)print, (i + 1));
	print_arg(spc, args, count, ch);
	free(spc);
	return (index + i + 1);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, print);
	while (print[i] != 0)
	{
		while (print[i] != 37 && print[i] != 0)
		{
			write(1, &print[i], 1);
			i++;
			count++;
		}
		if (print[i] == 37)
			i = arg_print(&print[i], &count, args, i);
	}
	return (count);
	va_end(args);
}
