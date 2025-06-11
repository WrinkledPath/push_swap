#include <unistd.h>

void    ft_putstr(char *str);
int     ft_strlen(char *str);

int     main(void)
{
        char    *str;
        char    result;

        str = "Fist"; // Should be 4
        write(1, "First String: ", 14);
        ft_putstr(str);
        write(1, "\nStr Length: ", 13);
        result = ft_strlen(str) + '0';
        write(1, &result, 1); 
        write(1, "\n", 1);

        str = "Second"; // Should be 6
        write(1, "Second String: ", 15);
        ft_putstr(str);
        write(1, "\nStr Length: ", 13); 
        result = ft_strlen(str) + '0';
        write(1, &result, 1); 
        write(1, "\n", 1);

        str = "Third"; // Should be 5
        write(1, "First String: ", 14);
        ft_putstr(str);
        write(1, "\nStr Length: ", 13); 
        result = ft_strlen(str) + '0';
        write(1, &result, 1); 
        write(1, "\n", 1);
}

void    ft_putstr(char *str)
{       
        while (*str != '\0')
        {   
                write(1, str, 1);
                str++;
        }   
}

