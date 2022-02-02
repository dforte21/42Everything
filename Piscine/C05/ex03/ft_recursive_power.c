/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:23:15 by dforte            #+#    #+#             */
/*   Updated: 2021/12/08 12:23:23 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power);
void	recursive(int *tot, int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	int	tot;

	tot = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	recursive(&tot, nb, power);
	return (tot);
}

void	recursive(int *tot, int nb, int power)
{
	*tot *= nb;
	power--;
	if (power > 0)
		recursive(tot, nb, power);
	return ;
}
