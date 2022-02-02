/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:56:29 by dforte            #+#    #+#             */
/*   Updated: 2021/12/07 14:58:16 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	print_arg(int n, char **str);
void	printstr(char *str);

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*ptr;

	i = 1;
	if (argc <= 1)
		return (0);
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
			{
				ptr = argv[i];
				argv[i] = argv[j];
				argv[j] = ptr;
			}
			j++;
		}
		i++;
	}
	print_arg(argc, argv);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	n1;
	int	n2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		n1 = (int)s1[i];
		n2 = (int)s2[i];
		if (n1 < n2)
			return (0);
		if (n1 > n2)
			return (1);
		i++;
	}
	return (0);
}

void	print_arg(int n, char **str)
{
	int	i;

	i = 1;
	while (i < n)
	{
		printstr(str[i]);
		i++;
	}
}

void	printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}
