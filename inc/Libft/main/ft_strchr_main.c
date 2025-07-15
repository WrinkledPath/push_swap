#include <unistd.h>

char    *ft_strchr(char *str, int chr);

int     main(void)
{
        char    *c; 
        char    *str1;
        char    *str2;
        char    *str3;

        str1 = "This is the first test"; // Should find E in 11
        str2 = "Second"; // Should be null
        str3 = ""; // Should return null
        write(1, "Test1:\n", 7); 
        c = ft_strchr(str1, 'e');
        write(1, c, 12);
        write(1, "\n", 1); 
        write(1, "Test2:\n", 7); 
        c = ft_strchr(str2, 'z');
        write(1, c, 1); 
        write(1, "\n", 1); 
        write(1, "Test3:\n", 7); 
        c = ft_strchr(str3, 'e');
        write(1, c, 1); 
        write(1, "\n", 1); 
        return (0);
}
