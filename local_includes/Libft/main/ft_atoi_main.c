#include <stdio.h>

int     ft_atoi(const char *str);

int     main(void)
{
        char    *s1;
        char    *s2;
        int     a;

        s1 = "4353";
        s2 = "-4265";
        a = ft_atoi(s1);
        printf("S1 = %s --> %i\n", s1, a);
        a = ft_atoi(s2);
        printf("S2 = %s --> %i\n", s2, a);
        return (0);
}


