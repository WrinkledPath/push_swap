#include <unistd.h>

int     ft_isprint(int c); 

int     main(void)
{
        int     c;  
        char    result;
            
        c = 0;
        write(1, "Non-Printable Chars: ", 21);
        while (c < 33) 
        {   
                result = ft_isprint(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }
	c = 33;	
        write(1, "\nPrintable Chars: ", 18);
        while (c < 127)
        {   
                result = ft_isprint(c) + '0';
                write(1, &result, 1); 
                write(1, " ", 1); 
                c++;
        }   
        write(1, "\n", 1); 
        return (0);
}

