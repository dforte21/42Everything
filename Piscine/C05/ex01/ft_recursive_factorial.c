/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:21:58 by dforte            #+#    #+#             */
/*   Updated: 2021/12/08 15:25:22 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb);
void	recursive(int *nb, int a);

int	ft_recursive_factorial(int nb)
{
	int	a;

	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	a = nb - 1;
	recursive(&nb, a);
	return (nb);
}

void	recursive(int *nb, int a)
{
	*nb *= a;
	a--;
	if (a > 0)
		recursive(nb, a);
	return ;
}
