#include <iostream>
#include <cstring>

void    strup(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        for (int j = 0; av[i][j]; j++)
            std::cout << (char)toupper(av[i][j]);
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    switch(ac)
    {
        case 1:
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
            break ;
        default:
            strup(av);
            break ;
    }
    return (0);
}