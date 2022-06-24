/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:20:26 by dforte            #+#    #+#             */
/*   Updated: 2022/06/24 18:41:09 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define PI		3.14159265359
# define P2		PI/2
# define P3		3*P2
# define DR		0.0174533
# define FOV	60

# define RED 16711680
# define YELLOW 65025
# define BLUE 255
# define BLACK 0
# define WHITE 16777215
# define GREEN 65280

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_img
{
	void	*p;
	void	*w;
	void	*f;
}				t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	a;
}				t_player;

typedef	struct s_cub3D
{
	int			height;
	int			width;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	char		**map;
	void		*mlx;
	void		*win;
	float		dist[FOV];
	t_player	p;
	t_img		img;
}				t_cub3D;

int		ft_get_height(char *file_name, char *str);
int		ft_hooks(int keycode, t_cub3D *data);
int		ft_3d_render(t_cub3D *data);
char	*ft_get_row(char *str, int flag);
void	ft_get_info(int fd, char *str, t_cub3D *data);
void	ft_read_file(char *file_name, t_cub3D *data);
void	ft_init(t_cub3D *data);
void	find_player(t_cub3D *data, int *x, int *y);
void	ft_free_struct(t_cub3D *data);
void	get_distance(t_cub3D *data, float ray);
void	ft_free_matrix(void	**matrix);

#endif