/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:28:23 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:49:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_fd(char *file_name, char *str, t_cub3d *data)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("%s ", str);
		ft_error("file", data);
	}
	close(fd);
}

void	ft_check_file(char *file_name, t_cub3d *data)
{
	if (ft_strlen(file_name) < 5)
		ft_error("Map name", data);
	if (ft_memcmp(&file_name[ft_strlen(file_name) - 4], ".cup", 4) != 0)
		ft_error("Map extension", data);
	ft_check_fd(file_name, "Map", data);
}

void	ft_check_color(char *str, t_cub3d *data)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ',' && str[i] != '\n')
			ft_error("Color", data);
		if (str[i] == ',')
			count++;
		i++;
	}
	str[i - 1] = '\0';
	if (count != 2)
		ft_error("Color", data);
}

void	ft_check_info(t_cub3d *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL)
		ft_error("Info", data);
	if (data->ea == NULL || data->f < 0 || data->c < 0)
		ft_error("Info", data);
	ft_check_fd(data->no, "Texture", data);
	ft_check_fd(data->so, "Texture", data);
	ft_check_fd(data->we, "Texture", data);
	ft_check_fd(data->ea, "Texture", data);
}
