#include "header.h"

int main(int ac, char **av)
{
	FILE *fd;
	t_back back;

	if (ac != 2)
		return (error("Error: argument\n", NULL));
	if (!(fd = fopen(av[1], "r")) || !getinfo(fd, &back))
		return (error("Error: Operation file corrupted\n", fd));
	if (!process(fd, &back))
		return (error("Error: Operation file corrupted\n", fd));
	fclose(fd);
	return (0);
}

int	process(FILE *fd, t_back *back)
{
	char **map;
	t_shape shape;
	int	count = 0;

	map = fillMap(back);
	count = fscanf(fd, "%c %f %f %f %c\n", &shape.def, &shape.cx, &shape.cy, &shape.rad, &shape.shapec);
	while (count != -1)
	{
		if (count != 5 || shape.rad <= 0.0 || (shape.def != 'c' && shape.def != 'C'))
		{
			ftFree(map);
			return (0);
		}
		circle(&shape, map);
		count = fscanf(fd, "%c %f %f %f %c\n", &shape.def, &shape.cx, &shape.cy, &shape.rad, &shape.shapec);
	}
	for (int i = 0; map[i]; i++)
	{
		write(1, map[i], ftlen(map[i]));
		write(1, "\n", 1);
	}
	ftFree(map);
	return (1);
}

void ftFree(char **map)
{
	for (int i = 0; map[i]; i++)
		free(map[i]);
	free(map);
}

void	circle(t_shape *shape, char **map)
{
	float dist;

	if (shape->def == 'c')
	{
		for (int i = 0; map[i]; i++)
		{
			for (int j = 0; map[i][j]; j++)
			{
				dist = sqrtf(powf(shape->cx - j, 2) + powf(shape->cy - i, 2));
				if ((shape->rad - dist) >= 0.0 && (shape->rad - dist) < 1.0)
					map[i][j] = shape->shapec;
			}
		}
	}
	if (shape->def == 'C')
    {
        for (int i = 0; map[i]; i++)
        {
            for (int j = 0; map[i][j]; j++)
            {
                dist = sqrtf(powf(shape->cx - j, 2) + powf(shape->cy - i, 2));
                if ((shape->rad - dist) >= 0.0 && (shape->rad - dist) <= shape->rad)
                    map[i][j] = shape->shapec;
            }
        }
    }
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

int	error(char *str, FILE *fd)
{
	write(1, str, ftlen(str));
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
