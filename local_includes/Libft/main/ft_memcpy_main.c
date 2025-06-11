#include <unistd.h>

void    *ft_memcpy(void *dest, void *src, int size);
void    ft_putnbr(int i); 

int     main(void)
{
        int     i;  
        char    *srcstr;
        char    deststr[10];

        i = 0;
        srcstr = "First Test";
        write(1, "Source Memory:\n", 15);
        while (i < 10) 
        {   
                ft_putnbr(srcstr[i]);
                write(1, " ", 1); 
                i++;
        }   
        write(1, "\n", 1); 
        ft_memcpy(deststr, srcstr, 10);
        i = 0;
        write(1, "Destination Memory:\n", 20);
        while (i < 10) 
        {   
                ft_putnbr(deststr[i]);
                write(1, " ", 1); 
                i++;
        }   
        write(1, "\n", 1); 
        return (0);
}

void    ft_putnbr(int i)
{
        char    c;  
    
        if (i >= 10) 
                ft_putnbr(i / 10);
        c = (i % 10) + '0';
        write(1, &c, 1); 
}


