/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:04:36 by dforte            #+#    #+#             */
/*   Updated: 2021/12/01 15:00:52 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_count(char *dest, char *src);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	j;
	unsigned int	k;

	a = ft_count(&dest[0], &src[0]);
	j = 0;
	k = 0;
	while (dest[j] != 0)
		j++;
    if (size == 0)
        return (i);
	while (src[k] != 0 && j < size - 1)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	dest[j] = '\0';
	return (a);
}

int	ft_count(char *dest, char *src)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (src[i] != 0)
		i++;
	while (dest[j] != 0)
	{
		i++;
		j++;
	}
	return (i);
}
