#include "functions.h"

int main()
{
    int     fp;
    int     byte;
    char    b[5];
    char    c[2];

    fp = open("ft_tail", O_RDONLY);
    byte = read(fp, b, 4);
    while (byte != 0)
    {
        *c = *ft_convert_base(b, "01", "0123456789abcdef");
        printf("%x", c[0]);
        byte = read(fp, b, 4);
        *c = *ft_convert_base(b, "01", "0123456789abcdef");
        printf("%x ", c[0]);
        byte = read(fp, b, 4);
    }
}