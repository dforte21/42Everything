#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_back
{
	int width;
	int height;
	char mapc;
} t_back;

typedef struct s_shape
{
	char def;
	float tx;
	float ty;
	float bx;
	float by;
	char shapec;
} t_shape;

int ftlen(char *str);
int error(char *msg);
int getinfo(FILE *fd, t_back *back);
int process(FILE *fd, t_back *back);
void    draw(t_shape *shape, char **map);
void    ftFree(char **map);
void    arrotonda(t_shape *shape);
char    **fillMap(t_back *back);

#endif
