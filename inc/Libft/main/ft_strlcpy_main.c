#include <unistd.h>

void    ft_putnbr(int i);
int     ft_strlcpy(char *dst, char *src, int dst_len);

int     main(void)
{
        char    *str;
        char    dest[11];
        int     i;

        i = 0;
        str = "This is it";
        write(1, "Source String:\n", 15);
        while (i < 11) 
        {   
                ft_putnbr(str[i]);
                write(1, " ", 1); 
                i++;
        }   
        i = 0;
        ft_strlcpy(dest, str, sizeof(dest));
        write(1, "\nDestination String:\n", 21);
        while (i < 11)
        {   
                ft_putnbr(dest[i]);
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


