#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(char *str, int c);

int main(void)
{
	char	str[] = "Hello, world!";
	char	c = 'o';
	char	*result;

	result = ft_strrchr(str, c);
	if (result)
		printf("Found '%c' at position: %ld\n", c, result - str);
	else
		printf("Character '%c' not found.\n", c);
	c = 'z';
	result = strrchr(str, c);
	if (result)
		printf("Found '%c' at position: %ld\n", c, result - str);
	else
		printf("Character '%c' not found.\n", c);
	return 0;
}

