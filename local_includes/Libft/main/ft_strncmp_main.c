#include <unistd.h>
#include <stdio.h>

int     ft_strncmp(char *str1, char *str2, int size);

int     main(void)
{
        char    *str1;
        char    *str2;
        int     result;

        str1 = "aaa";
        str2 = "aab";
        write(1, "Test1 - str1 < str2\n", 20);
        result = ft_strncmp(str1, str2, 3); // Should be -1
        printf("%i\n", result);
        str1 = "aab";
        str2 = "aaa";
        write(1, "Test2 - str1 > str2\n", 21); // Should be 1
        result = ft_strncmp(str1, str2, 3); 
        printf("%i\n", result);
        str1 = "aaa";
        str2 = "aaa";
        write(1, "Test3 - str1 = str2\n", 21); // Should be 0
        result = ft_strncmp(str1, str2, 3); 
        printf("%i\n", result);
}

