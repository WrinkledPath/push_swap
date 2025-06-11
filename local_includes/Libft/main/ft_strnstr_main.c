#include <unistd.h>

char    *ft_strnstr(const char *big, const char *small, int len);

int     main(void)
{
        const char      *smallstr;
        const char      *bigstr;
        char    *result;

        smallstr = "Big";
        bigstr = "Happy Big Planet";
        write(1, "Testing:\nIs ", 12);
        write(1, smallstr, 3); 
        write(1, " in ", 4); 
        write(1, bigstr, 16);
        write(1, "--->", 4); 
        result = ft_strnstr(bigstr, smallstr, 16);
        write(1, result, 10);
        return (0);
}


