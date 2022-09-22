/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:27:15 by dforte            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/22 18:06:02 by dforte           ###   ########.fr       */
=======
/*   Updated: 2022/09/22 18:07:03 by mabasset         ###   ########.fr       */
>>>>>>> dave
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av)
{
	char	*line;
	size_t	buf;

	while (1)
	{
		line = readline("Minishell>? ");
		ftParser(line);
		free(line);
		asd();
	}
}