#include "libft.h"
#include <limits.h>  

int main() {
    ft_putnbr_fd(12345, 1);  // Output: 12345
    
    ft_putnbr_fd(-12345, 1); // Output: -12345

    ft_putnbr_fd(0, 1);      // Output: 0

    ft_putnbr_fd(INT_MIN, 1); // Output: -2147483648

    ft_putnbr_fd(INT_MAX, 1); // Output: 2147483647
    
    return 0;
}

