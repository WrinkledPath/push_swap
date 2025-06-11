#include "ft_printf.h"

int		ft_putchar(const char c)
{	
	return(write(1, &c, 1));
}

int		ft_putstr(const char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return(write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;		
	}
	return (i);
}
