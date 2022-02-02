/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:23:41 by dforte            #+#    #+#             */
/*   Updated: 2021/12/08 12:24:56 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index);
void	do_recursive(int *n, int index, int i);

int	ft_fibonacci(int index)
{
	int	n[3];

	n[0] = 0;
	n[1] = 1;
	n[2] = 1;
	if (index < 0)
		return (-1);
	do_recursive(n, index, 0);
	return (n[0]);
}

void	do_recursive(int *n, int index, int i)
{
	if (i == index)
		return ;
	n[0] = n[1];
	n[1] = n[2];
	n[2] = n[0] + n[1];
	i++;
	do_recursive(n, index, i);
	return ;
}
