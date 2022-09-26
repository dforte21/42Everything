#include "minishell.h"

int main(int ac, char **av)
{
	char	*line;
	size_t	buf;

	while (1)
	{
		line = readline("Minishell 1.0>? ");
		ftParser(line);
	}
}