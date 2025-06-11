#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483648)

char	*ft_itoa(int n);

int	main(void)
{
	int	test_cases[7];
	int	i;
	char	*result;

	test_cases[0] = 0;
	test_cases[1] = 42;
	test_cases[2] = -42;
	test_cases[3] = 123456;
	test_cases[4] = -123456;
	test_cases[5] = 2147483647;
	test_cases[6] = -2147483648;
	i = 0;
	while (i < 7)
	{
		result = ft_itoa(test_cases[i]);
		if (result)
		{
			printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], result);
			free(result);
		}
		else
			printf("ft_itoa(%d) failed!\n", test_cases[i]);
	}
	return (0);
}
