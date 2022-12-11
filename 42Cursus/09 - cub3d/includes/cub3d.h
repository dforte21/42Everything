/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:20:26 by dforte            #+#    #+#             */
/*   Updated: 2022/12/11 14:56:39 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/libft.h"

# define PI				3.14159265359
# define SCREEN_WIDTH	960
# define SCREEN_HEIGHT	720

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

typedef struct s_imgs
{
	t_img	mmap;
	t_img	mmapw;
	t_img	mmapf;
	t_img	mdo;
	t_img	mdc;
	t_img	bground;
	t_img	win;
	t_img	nwall;
	t_img	swall;
	t_img	ewall;
	t_img	wwall;
	t_img	door;
	t_img	hand;
	t_img	face;
}				t_imgs;

typedef struct s_ray
{
	int		wallheight;
	int		itexture;
	double	wx;
	double	wy;
	double	rayangle;
	double	rayx[960];
	double	rayy[960];
	double	raycos[960];
	double	raysin[960];
	double	distance[960];
}				t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	int		pangle;
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}				t_player;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*bground;
	char		**map;
	int			f;
	int			c;
	int			height;
	int			width;
	t_player	p;
	t_imgs		imgs;
	t_ray		*ray;
}				t_cub3d;

//checks
void	ft_check_file(char *file_name, t_cub3d *data);
void	ft_check_info(t_cub3d *data);
void	ft_check_map(char **map, t_cub3d *data, int row, int col);
void	ft_error(char *str, t_cub3d *data);
void	ft_check_color(char *str, t_cub3d *data);

double	degreetoradians(double degree);
char	**loadmap(char *path, t_cub3d *data, int i);
void	draw_minimap(t_cub3d *data, int x, int y, int tiles);
void	launch_ray(t_cub3d *data, t_ray *ray, int i);
void	load_walltiles(t_cub3d *data, int wdth, int hght);
void	read_info(char *path, t_cub3d *data);
void	check_wall(int wx, int wy, t_cub3d *data);
void	freeall(t_cub3d *data);
void	load_mmaptiles(t_cub3d *data, int wdth, int hght);
void	read_file(char *path, t_cub3d *data);
void	getpath(char *raw, t_cub3d *data);
void	initplayer(t_cub3d *data, int i, int j);
void	getangle(t_cub3d *data);
void	drawline(int i, t_ray *ray, t_cub3d *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	raycasting(t_cub3d *data, t_ray *ray);
void	ftmovements(t_cub3d *data);
void	ftdraw(t_cub3d *data, t_ray *ray);
void	ftmove(double angle, t_cub3d *data);
void	ftanimations(t_cub3d *data);
void	getwallorient(t_cub3d *data, t_ray *ray, int x, int y);
void	loadimages(t_cub3d *data);
void	gettextstart(t_ray *ray, int x, double *yincrementer);
void	ftminimap(t_cub3d *data);
void	ftputtiles(t_cub3d *data, int tiles, t_img *img);
void	checkcoords(int *x, int *y, t_cub3d *data);
void	ftplayer(t_cub3d *data, int tiles);
void	hand(t_cub3d *data, int size, t_img *text);
void	face(t_cub3d *data, int size, t_img *text);
int		draw_wall(int x, int y, t_ray *ray, t_cub3d *data);
int		getcolor(char *str, t_cub3d *data);
int		ftdisplay(t_cub3d *data);
int		ft_on(int keycode, t_cub3d *data);
int		ft_off(int keycode, t_cub3d *data);
int		ftmouse(int key, int x, int y, t_cub3d *data);
int		ftexit(t_cub3d *data);
int		gettextcolor(int x, int y, t_img *text);
int		printwallpixel(t_ray *ray, t_img *text, int x);

#endif