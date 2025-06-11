#include "libft.h"

char    *ft_substr(const char *s, unsigned int start, size_t len);

int	main(void)
{
	char	*str;

	str = "This is the String";
	printf("Original String: %s", str);
	str = ft_substr(str, 5, 8); // Should be "is the S"
	printf("Sub String: %s", str);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int	i;
	int	j;
	int	s_len;
	unsigned char	*s;

	i = 0;
	s_len = ft_strlen(s);
	dest = malloc(len * sizeof(char));
	if (start > s_len || start + len > s_len)
		return (NULL);
	while (s[i])`
	{
		if (i == start)
		{
			j = 0;
			while (j < len)
			{
				dest[j] = s[i];	
				j++;
			}
		}
		i++;
	}
	return (dest);
}
