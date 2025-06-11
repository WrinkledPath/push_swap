/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:49 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 18:58:46 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurrence of the string small in the string big, 
where not more than len characters are searched. 
Chars that appear after a null terminator are not searched.
*/

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (small[0] == '\0')
		return ((char *)big);
	if (ft_strlen(small) > len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == small[j] && i + j < len && small[j] != '\0')
		{
			j++;
		}
		if (small[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
