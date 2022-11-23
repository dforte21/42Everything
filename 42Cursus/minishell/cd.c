/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:33 by dforte            #+#    #+#             */
/*   Updated: 2022/11/23 17:48:15 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ftpwd(t_comms *comms)
{
	char	line[1000];

	getcwd(line, 1000);
	printf("%s\n", line);
	return (0);
}

int	ftcd(t_comms *comms)
{
	int		r;
	char	*home;

	if (!comms->cargs[1])
	{
		home = getenv("HOME");
		r = chdir(home);
	}
	else
		r = chdir(comms->cargs[1]);
	if (r == -1)
		return (fterror(comms->cargs, 2, 1));
	return (0);
}
