#include <unistd.h>

void    ft_bzero(void *s, unsigned int n); 
void    ft_putnbr(int n); 

int     main(void)
{
        unsigned char   buffer[20] = "This is the string..";
        unsigned int    i;  

        i = 0;
        write(1, "Original Memory:\n", 17);
        while(i++ < 20) 
        {   
                ft_putnbr(buffer[i]);
                write(1, " ", 1); 
        }   
        write(1, "\n", 1); 
        ft_bzero(buffer, 20);
        write(1, "After bzero:\n", 13);
        i = 0;
        while(i++ < 20) 
        {   
                ft_putnbr(buffer[i]);
                write(1, " ", 1); 
        }   
        write(1, "\n", 1); 
        return (0);
}

void    ft_putnbr(int n)
{
        char    c;  

        if (n >= 10) 
                ft_putnbr(n / 10);
        c = (n % 10) + '0';
        write(1, &c, 1); 
}

