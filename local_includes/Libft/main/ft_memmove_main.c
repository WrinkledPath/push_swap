#include <unistd.h>

void    *ft_memmove(void *dest, void *src, int size);

int     main(void)
{
        int     src[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
        int     i;  
        char    c;  

        i = 0;
        write(1, "Source Memory:\n", 15);
        while (i < 9)
        {   
                c = src[i] + '0';
                write(1, &c, 1); 
                i++;
        }   
        i = 0;
        ft_memmove(src + 2, src, 7 * sizeof(int));
        write(1, "\nDestination Memory:\n", 21);
        while (i < 9)
        {   
                c = src[i] + '0';
                write(1, &c, 1); 
                i++;
        }   
        write(1, "\n", 1); 
        return (0);
}


