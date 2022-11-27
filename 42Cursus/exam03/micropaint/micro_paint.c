#include "header.h"

int main(int ac, char **av)
{
	FILE *fd;
	t_back back;

	if (ac != 2)
		return (error("Error: argument\n", NULL));
	if (!(fd = fopen(av[1], "r")) || !getinfo(fd, &back))
		return(error("Error: Operation file corrupted\n", fd));
	if (!process(fd, &back))
		return (error("Error: Operation file corrupted\n", fd));
	fclose (fd);
	return (0);
}

int	process(FILE *fd, t_back *back)
{
	char **map;
	t_shape shape;
	int count = 0;

	map = fillMap(back);
	count = fscanf(fd, "%c %f %f %f %f %c\n", &shape.def, &shape.tx, &shape.ty, &shape.bx, &shape.by, &shape.shapec);
	while (count != -1)
	{
		if (count != 6 || shape.bx <= 0.0 || shape.by <= 0.0 || (shape.def != 'r' && shape.def != 'R'))
		{
			ftFree(map);
			return (0);
		}
		arrotonda(&shape);
		draw(&shape, map);
		count = fscanf(fd, "%c %f %f %f %f %c\n", &shape.def, &shape.tx, &shape.ty, &shape.bx, &shape.by, &shape.shapec);
	}
	for (int i = 0; map[i]; i++)
	{
		write(1, map[i], ftlen(map[i]));
		write(1, "\n", 1);
	}
	ftFree(map);
	return (1);
}

void	draw(t_shape *shape, char **map)
{
	if (shape->def == 'r')
	{
		for (int i = 0; map[i]; i++)
		{
			for (int j = 0; map[i][j]; j++)
			{
				if (i < shape->ty || i > shape->by || j < shape->tx || j > shape->bx)
					continue ;
				if (i == shape->by || i == shape->ty || j == shape->tx || j == shape->bx)
					map[i][j] = shape->shapec;
			}
		}
	}
	if (shape->def == 'R')
    {
        for (int i = 0; map[i]; i++)
        {
            for (int j = 0; map[i][j]; j++)
            {
                if (i < shape->ty || i > shape->by || j < shape->tx || j > shape->bx)
                    continue ;
                if (i <= shape->by && i >= shape->ty && j >= shape->tx && j <= shape->bx)
                    map[i][j] = shape->shapec;
            }
        }
    }
}

void	arrotonda(t_shape *shape)
{
	shape->bx = floorf(shape->tx + shape->bx);
	shape->by = floorf(shape->ty + shape->by);
	if (shape->tx > (int)shape->tx || (shape->tx < 0.0 && shape->tx < (int)shape->tx))
		shape->tx += 1;
	if (shape->tx < 0.0)
        shape->tx -= 1;
	if (shape->ty > (int)shape->ty || (shape->ty < 0.0 && shape->ty < (int)shape->ty))
        shape->ty += 1;
	if (shape->ty < 0.0)
        shape->ty -= 1;
	shape->tx = floorf(shape->tx);
	shape->ty = floorf(shape->ty);
}

void	ftFree(char **map)
{
	for(int i = 0; map[i]; i++)
		free(map[i]);
	free(map);
}

char	**fillMap(t_back *back)
{
	char **map;

	map = calloc(back->height + 1, sizeof(char *));
	for (int i = 0; i < back->height; i++)
	{
		map[i] = calloc(back->width + 1, 1);
		for (int j = 0; j < back->width; j++)
			map[i][j] = back->mapc;
	}
	return (map);
}

int	getinfo(FILE *fd, t_back *back)
{
	int count = 0;

	count = fscanf(fd, "%d %d %c\n", &back->width, &back->height, &back->mapc);
	if (count != 3 || back->width < 1 || back->width > 300 || back->height < 1 || back->height > 300)
		return (0);
	return (1);
}

int	error(char *msg, FILE *fd)
{
	write(1, msg, ftlen(msg));
	if (fd)
		fclose(fd);
	return (1);
}

int ftlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
