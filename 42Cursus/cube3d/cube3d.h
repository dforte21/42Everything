/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:20:26 by dforte            #+#    #+#             */
/*   Updated: 2022/07/29 16:57:36 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define PI				3.14159265359
# define RAD			0.0174533
# define FOV			60
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

# define SPEED	0.1
# define SENS	0.06598132

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"

# define W		13
# define A		0
# define S		1
# define D		2
# define LEFT	123
# define RIGHT	124
# define ESC	53

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		e;
}				t_img;


typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	ldx;
	float	ldy;
	float	angle;
	float	langle;
	int		w;
	int		s;
	int		a;
	int		d;
	int		left;
	int		right;
}				t_player;

typedef	struct s_cub3D
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int			F;
	int			C;
	char		**map;
	int			height;
	int			width;
	int			s_h;
	int			s_w;
	void		*mlx;
	void		*win;
	void		*gun1;
	void		*gun2;
	void		*gun;
	float		dist[FOV * 16];
	int			color[FOV * 16];
	float		wheight[FOV * 16];
	t_player	p;
	t_img		img;
}				t_cub3D;

int		ft_on(int keycode, t_cub3D *data);
int		ft_off(int keycode, t_cub3D *data);
int		ft_get_height(char *file_name, char *str);
int		ft_3d_render(t_cub3D *data);
char	*ft_get_row(char *str, int flag);
void	ft_remove_newline(char *file_name);
void	ft_check_file(char *file_name);
void	ft_put_term(char *str);
void	my_mlx_pixel_put(t_cub3D *data, int x, int y, int color);
void	ft_check_angle(float *angle);
void	get_wall_height(t_cub3D *data);
void	get_distance(t_cub3D *data, float ray);
void	ft_read_file(char *file_name, t_cub3D *data);
void	ft_get_width(t_cub3D *data);
void	ft_get_info(int fd, char *str, t_cub3D *data);
void	ft_move(t_cub3D	*data, float move_x, float move_y);
void	ft_movement(t_cub3D *data);
void	ft_dir(t_cub3D *data, float dir);
void	ft_init(t_cub3D *data);
void	ft_init_img(void);
void	ft_find_p(t_cub3D *data);
void	ft_init_p(t_cub3D *data, char c);
void	ft_free_struct(t_cub3D *data);

#endif