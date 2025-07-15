/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:51:00 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/13 15:41:19 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns a pointer to the last occurrence of the char c in the string str

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char) c)
			return ((char *) &str[len]);
		len--;
	}
	return (NULL);
}
