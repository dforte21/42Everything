/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:20:26 by dforte            #+#    #+#             */
/*   Updated: 2022/09/18 17:29:27 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"

# define PI				3.14159265359
# define RAD			0.0174533
# define FOV			60
# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480

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
	t_img	background;
	t_img	win;
	t_img	nWall;
	t_img	sWall;
	t_img	eWall;
	t_img	wWall;
}				t_imgs;

typedef	struct s_ray
{
	int		wallHeight;
	int		iTexture;
	float	rayAngle;
	float	rayX[640];
	float	rayY[640];
	float	rayCos[640];
	float	raySin[640];
	float	distance[640];
}				t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	int	pAngle;
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}				t_player;

typedef	struct s_cub3D
{
	void		*mlx;
	void		*win;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*bGround;
	char		**map;
	int			F;
	int			C;
	int			height;
	int			width;
	t_player	p;
	t_imgs		imgs;
}				t_cub3D;

float	degreeToRadians(float degree);
char	**loadMap(char *path, t_cub3D *data);
void	ftExit(t_cub3D *data);
void	read_file(char *path, t_cub3D *data);
void	getPath(char *raw, t_cub3D *data);
void	freeAll(t_cub3D *data);
void	initPlayer(t_cub3D *data);
void	getAngle(t_cub3D *data);
void	drawLine(int i, t_ray *ray, t_cub3D *data);
void	my_mlx_pixel_put(t_cub3D *data, int x, int y, int color);
void	rayCasting(t_cub3D *data, t_ray *ray);
void	ftMovements(t_cub3D *data);
void	ftDraw(t_cub3D *data, t_ray  *ray);
void	ftMove(float angle, t_cub3D *data);
void	getWallOrient(t_cub3D *data, t_ray *ray, int x, int y);
void	loadImages(t_cub3D *data);
int		getColor(char *str);
int		ftDisplay(t_cub3D *data);
int		ft_on(int keycode, t_cub3D *data);
int		ft_off(int keycode, t_cub3D *data);
int		getTextColor(int x, int y, t_img *text);
int		printWallPixel(t_ray *ray, t_img *text, int x);
int		getTextStart(t_ray *ray, int x);
void	test(void);

#endif