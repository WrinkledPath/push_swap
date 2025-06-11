#include <unistd.h>

void    ft_putnbr(int i); 
int     ft_strlcat(char *dst, char *src, int src_size);

int     main(void)
{
        int     i;  
        int     size;
        char    *src;
        char    dest[19] = "This is ";
            
        i = 0;
        src = "the string";
        write(1, "Original Strings:\n", 18);
        write(1, "Source: ", 8); 
        write(1, src, 10);
        write(1, "    ", 4); 
        write(1, "Destination: ", 13);
        write(1, &dest, 10);
        write(1, "\n", 1); 
        size = ft_strlcat(dest, src, sizeof(dest));
        write(1, "ASCII Values After ft_strlcpy:\n", 31);
        while (i < 19) 
        {   
                ft_putnbr(dest[i]);
                write(1, " ", 1); 
                i++;
        }   
        write(1, "\nLength of string is:\n", 22);
        ft_putnbr(size);
        write(1, "\n", 1); 
        write(1, "Final String is:\n", 17);
        write(1, &dest, size);
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

