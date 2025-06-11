#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	to_uppercase(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z') 
		*c = *c - 32; 
}

int main()
{
	char str[] = "hello world!";
	ft_striteri(str, to_uppercase);
	printf("Transformed string: %s\n", str);
	return 0;
}

