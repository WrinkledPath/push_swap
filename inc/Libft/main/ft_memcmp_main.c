#include <unistd.h>
#include <stdio.h>

int     ft_memcmp(const void *ptr1, const void *ptr2, int size);

int     main(void)
{
        char    *str1;
        char    *str2;
        int     result;
    
    
        str1 = "aaa";
        str2 = "aab";
        write(1, "Test1: str1 < str2", 18);
        result = ft_memcmp(str1, str2, 3); 
        printf(" - Difference: %i\n", result);

        str1 = "aab";
        str2 = "aaa";
        write(1, "Test2: str1 > str2", 18);
        result = ft_memcmp(str1, str2, 3); 
        printf(" - Difference: %i\n", result);

        str1 = "aaa";
        str2 = "aaa";
        write(1, "Test1: str1 = str2", 18);
        result = ft_memcmp(str1, str2, 3); 
        printf(" - Difference: %i\n", result);
        return (0);
}
