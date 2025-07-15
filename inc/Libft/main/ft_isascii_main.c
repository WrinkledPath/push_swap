#include <unistd.h>

int     ft_isascii(int c); 

int     main(void)
{
        char    result;
        int     c;      
            
        c = 0;
        write(1, "ASCII Values: ", 14);
        while (c <= 127)
        {   
                result = ft_isascii(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        write(1, "\nNon-ASCII Values: ", 19);
        while (c <= 140)
        {   
                result = ft_isascii(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        write(1, "\n", 1); 
        return (0);
}

