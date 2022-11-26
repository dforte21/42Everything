#ifndef HEAD_H
# define HEAD_H
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_backg
{
	int 	width;
	int 	height;
	char	backc;
}				t_backg;

typedef struct s_shape
{
	char	def;
	float	tx;
	float	ty;
	float	radius;
	char	schar;
}				t_shape;

int	readBack(t_backg *back, FILE *fd);
char **fillMap(t_backg *back);
void	ftFree(char **map);
int	checkArg(char *path);
int	closereturn(FILE *fd);
void	arrotonda(t_shape *shape, t_backg *back);
void	drawrect(char **map, t_shape *shape);

#endif