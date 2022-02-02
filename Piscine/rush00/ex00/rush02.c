/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:30:11 by dforte            #+#    #+#             */
/*   Updated: 2021/11/27 19:04:52 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(char c);
void	rush(int a, int b);
void	print_firstline(int a);
void	print_midline(int a, int b);
void	print_lastline(int a, int b);

void	rush(int a, int b)
{
	if (a <= 0 || b <= 0)
	{
		return ;
	}
	print_firstline(a);
	print_midline(a, b);
	print_lastline(a, b);
}

void	print_firstline(int a)
{
	int	i;

	i = 2;
	ft_print('A');
	while (i < a)
	{
		ft_print('B');
		i++;
	}
	if (a > 1)
	{
		ft_print('A');
	}
	ft_print('\n');
}

void	print_midline(int a, int b)
{
	int	i;
	int	j;

	i = 2;
	if (b > 1)
	{
		while (i < b)
		{
			j = 2;
			ft_print('B');
			while (j < a)
			{
				ft_print(' ');
				j++;
			}
			if (a > 1)
			{
				ft_print('B');
			}
			ft_print('\n');
			i++;
		}
	}
}

void	print_lastline(int a, int b)
{
	int	i;

	i = 2;
	if (b <= 1)
	{
		return ;
	}
	ft_print('C');
	while (i < a)
	{
		ft_print('B');
		i++;
	}
	if (a > 1)
	{
		ft_print('C');
	}
	ft_print('\n');
}
