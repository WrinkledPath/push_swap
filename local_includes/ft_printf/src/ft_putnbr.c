#include "ft_printf.h"

int		print_nbr(long n, const char *base)
{
	int				count;
	unsigned long	len_base;
	unsigned long	num;
	len_base = ft_strlen(base);
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		num = (unsigned long)(-(n + 1)) + 1;
	}
	else
		num = (unsigned long)n;
	if (num >= len_base)
	{
		count += print_nbr(num / len_base, base);
	}
	count += ft_putchar(base[num % len_base]);
	return (count);
}

int		print_ptr(unsigned long p)
{
	int		count;

	count = 0;
	if (p == 0)
		return (write(1, "(nil)", 5)); 
	count += write(1, "0x", 2);
	count += print_unbr(p, HEX_MIN);
	return (count);
}

int		print_unbr(unsigned long n, const char *base)
{
	int		count;
	unsigned long		len_base;

	len_base = ft_strlen(base);
	count = 0;
	if (n >= len_base)
	{
		count += print_unbr(n / len_base, base);
	}
	count += ft_putchar(base[n % len_base]);
	return (count);
}

