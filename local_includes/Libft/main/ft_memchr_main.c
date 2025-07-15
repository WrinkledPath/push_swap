#include <unistd.h>

void    *ft_memchr(const void *str, int c, int n);

int     main(void)
{
        char    str[] = "First test";
        char    c;
        char    *result;

        c = 'e';
        write(1, "Test1:\n", 7);
        write(1, str, 10);
        result = ft_memchr(str, c, sizeof(str));
        write(1, " --> ", 5);
        write(1, result, 3);
        return (0);
}
