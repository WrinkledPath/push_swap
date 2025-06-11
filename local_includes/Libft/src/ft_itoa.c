/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:47:45 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 19:12:51 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n);
static void	fill_number(char *str, long nb, int len);

//Converts int into string

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	nb = (long)n;
	len = num_length(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_number(str, nb, len);
	return (str);
}

//Fills str with nb after converting to char

static void	fill_number(char *str, long nb, int len)
{
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (len-- > (str[0] == '-'))
	{
		str[len] = '0' + (nb % 10);
		nb /= 10;
	}
}

//Calculates the length of the number + 1 if negative

static int	num_length(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}
