#include "head.h"

int main(int ac, char **av)
{
	FILE	*fd;
	t_backg back;
	t_shape shape;
	char	**map;
	int 	count = 0;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(fd = fopen(av[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (checkArg(av[1]) || readBack(&back, fd))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (closereturn(fd));
	}
	map = fillMap(&back);
	count = fscanf(fd, "%c %f %f %f %c\n", &shape.def, &shape.tx, &shape.ty, &shape.radius, &shape.schar);
	while (count != -1)
	{
		drawrect(map, &shape);
		count = fscanf(fd, "%c %f %f %f %c\n", &shape.def, &shape.tx, &shape.ty, &shape.radius, &shape.schar);
	}
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
	ftFree(map);
	fclose(fd);
	return (0);
}

void	drawrect(char **map, t_shape *shape)
{
	float	dist;

	if (shape->def == 'c')
	{
		for (int i = 0; map[i]; i++)
		{
			for (int j = 0; map[i][j]; j++)
			{
				dist = sqrt(powf(i - shape->ty, 2.0) + powf(j - shape->tx, 2.0));
				if ((shape->radius - dist) >= 0.0 && (shape->radius - dist) < 1.0)
					map[i][j] = shape->schar;
			}
		}
		return ;
	}
	if (shape->def == 'C')
	{
		for (int i = 0; map[i]; i++)
		{
			for (int j = 0; map[i][j]; j++)
			{
				dist = sqrt(powf(i - shape->ty, 2.0) + powf(j - shape->tx, 2.0));
				if ((shape->radius - dist) >= 0.0 && (shape->radius - dist) <= shape->radius)
					map[i][j] = shape->schar;
			}
		}
	}
}

void	ftFree(char **map)
{
	for (int i = 0; map[i]; i++)
		free(map[i]);
	free(map);
}

int	readBack(t_backg *back, FILE *fd)
{
	int count;

	count = fscanf(fd, "%d %d %c\n", &back->width, &back->height, &back->backc);
	if (back->width < 1 || back->width > 300 || back->height < 1 || back->height > 300)
		return (1);
	return (0);
}

char **fillMap(t_backg *back)
{
	int	i = 0, j;
	char	**map;
	
	map = calloc(back->height + 1, sizeof(char *));
	for(;i < back->height; i++)
	{
		map[i] = calloc(back->width + 1, 1);
		for (j = 0; j < back->width; j++)
			map[i][j] = back->backc;
	}
	return (map);
}

int	checkArg(char *path)
{
	FILE *fd;
	t_backg back;
	t_shape shape;
	int 	count;

	fd = fopen(path, "r");
	count = fscanf(fd, "%d %d %c\n", &back.width, &back.height, &back.backc);
	if (count != 3)
		return (1);
	count = fscanf(fd, "%c %f %f %f %c\n", &shape.def, &shape.tx, &shape.ty, &shape.radius, &shape.schar);
	while (count != -1)
	{
		if (count != 5)
			return (1);
		if ((shape.radius <= 0.0) || (shape.def != 'c' && shape.def != 'C'))
			return (1);
		count = fscanf(fd, "%c %f %f %f %c\n", &shape.def, &shape.tx, &shape.ty, &shape.radius, &shape.schar);
	}
	return (0);
}

int	closereturn(FILE *fd)
{
	fclose(fd);
	return (1);
}
