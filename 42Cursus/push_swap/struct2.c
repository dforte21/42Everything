/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:53:23 by dforte            #+#    #+#             */
/*   Updated: 2022/05/18 16:02:19 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**loadmat(int *ac, char **av)
{
	int		i;
	int		size;
	char	**mat;

	i = 0;
	if (*ac == 2)
	{
		mat = ft_split(av[1], ' ');
		while (mat[i + 1])
		{
			*ac += 1;
			i++;
		}
		return (mat);
	}
	mat = ft_calloc(*ac, sizeof(char *));
	while (av[i + 1])
	{
		size = (size_t)ft_strlen(av[i + 1]);
		mat[i] = ft_calloc(size + 2, 1);
		ft_strlcpy(mat[i], av[i + 1], size + 1);
		i++;
	}
	return (mat);
}

int	find_best(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len / 2)
	{
		if (stack[i] > stack[i + 1] && check_minmax(stack, len, i))
			break ;
		i++;
	}
	j = len - 1;
	while (j > len / 2)
	{
		if (stack[j] > stack[j + 1] && check_minmax(stack, len, j))
			break ;
		j--;
	}
	if (stack[len] > stack[0] && check_minmax(stack, len, len))
		j = len;
	if ((len - j) < i)
		return (j);
	return (i);
}

int	check_minmax(int *stack, int len, int position)
{
	int	i;
	int	j;

	i = findmin(stack, len);
	j = findmax(stack, len);
	if (position == len)
	{
		if (j == position && i == 0)
			return (0);
	}
	if (j == position && i == j + 1)
		return (0);
	return (1);
}

int	findmin(int	*stack, int len)
{
	int	i;
	int	num;

	i = -1;
	num = 1;
	while (i == -1 && num <= 100)
	{
		i = find_num(stack, len, num);
		num++;
	}
	return (i);
}

int	findmax(int	*stack, int len)
{
	int	i;
	int	num;

	i = -1;
	num = 100;
	while (i == -1 && num > 0)
	{
		i = find_num(stack, len, num);
		num--;
	}
	return (i);
}
