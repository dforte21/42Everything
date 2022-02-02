/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:33:25 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 18:33:28 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		if (!(err_msg()))
			return (0);
	if (ac == 2)
		if ((!av[1] || av[1][0] == 0) || !(check_nbr(av[1])))
			if (!(err_msg()))
				return (0);
	if (ac == 3)
	{
		if (((!av[1] || !av[2]) || (av[1][0] == 0 || av[2][0] == 0))
			|| !(check_nbr(av[2])))
			if (!(err_msg()))
				return (0);
	}
	if (!(check_zero(av[1], av[2], ac)))
		return (0);
	if (ac == 2)
		process_start(av[1], "numbers.dict");
	else
		process_start(av[2], av[1]);
	write(1, "\n", 1);
}

void	process_start(char *str, char *dict)
{
	int				fp;
	int				size;
	int				maxlen;
	int				flag;
	t_dict_struct	*dict_struct;

	flag = 0;
	if (!(count(&size, &maxlen, dict)))
		flag = 1;
	dict_struct = malloc(sizeof(t_dict_struct) * size);
	fp = open(dict, O_RDONLY);
	if (flag == 0)
	{
		initialize_struct(dict_struct, maxlen, size);
		load_dict(dict_struct, fp);
		close (fp);
	}
	if (!(check_dict(dict_struct, size)))
		flag = 2;
	if (flag == 0)
		try_split(dict_struct, str, size);
	if (flag == 1 || fp == -1)
		err_msg();
	free (dict_struct);
}

int	err_msg(void)
{
	write(1, "Error", 5);
	return (0);
}

int	dicterr_msg(void)
{
	write(1, "Dict Error", 10);
	return (0);
}

int	check_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
