#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_MIN "0123456789abcdef"
# define HEX_MAY "0123456789ABCDEF"
# define DECIMAL "0123456789"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(const char c);
int		type_div(const char id, va_list args);
int		ft_putstr(const char *s);
int		print_nbr(long n, const char *base);
int		print_unbr(unsigned long n, const char *base);
int		print_ptr(unsigned long p);

#endif
