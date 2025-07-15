#include <unistd.h>

int	ft_isdigit(char c);

int     main(void)
{
        char    result;
        char    c;  

        c = '0';
        write(1, "Numbers: ", 9);
        while (c <= '9')
        {   
                result = ft_isdigit(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        c = 'A';
        write(1, "\nCapital: ", 10);
        while (c <= 'Z')
        {   
                result = ft_isdigit(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        c = 'a';
        write(1, "\nLowercase: ", 12);
        while (c <= 'z')
        {   
                result = ft_isdigit(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        c = ':';
        write(1, "\nNon alphanumeric: ", 19);
        while (c <= '@')
        {   
                result = ft_isdigit(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        write(1, "\n", 1); 
}

