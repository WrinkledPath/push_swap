#include <unistd.h>

int     ft_tolower(int ch);

int     main(void)
{
        char    c1; 
        char    c2; 
        char    c3; 

        c1 = 'a';
        c2 = 'A';
        c3 = '9';
        write(1, "Test1:\n", 6); 
        write(1, &c1, 1); 
        write(1, "  ", 2); 
        c1 = ft_tolower(c1);
        write(1, &c1, 1); 
    
        write(1, "\nTest2:\n", 7); 
        write(1, &c2, 1); 
        write(1, "  ", 2); 
        c2 = ft_tolower(c2);
        write(1, &c2, 1); 

        write(1, "\nTest3:\n", 7); 
        write(1, &c3, 1); 
        write(1, "  ", 2); 
        c3 = ft_tolower(c3);
        write(1, &c3, 1); 
}


