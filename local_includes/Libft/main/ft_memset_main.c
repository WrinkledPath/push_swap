#include <unistd.h>

void    ft_memset(void *ptr, int value, unsigned long len);
void    ft_puthex(unsigned char c); 

int     main(void)
{
        unsigned char buffer[20];
        int     i;  

        i = 0;
        ft_memset(buffer, '.', 20);
        while (i < 20) 
        {   
                ft_puthex(buffer[i]);
                write(1, " ", 1); 
                i++;
        }   
        write(1, "\n", 1); 
        return (0);
}

void    ft_puthex(unsigned char c)
{
        char    *hex_chars;

        hex_chars = "0123456789ABCDEF";

        write(1, &hex_chars[c / 16], 1); 
        write(1, &hex_chars[c % 16], 1); 
}


