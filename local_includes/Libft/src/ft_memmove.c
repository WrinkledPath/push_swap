/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:48:22 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 19:01:13 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*srcf;
	unsigned char	*destf;

	srcf = (unsigned char *)src;
	destf = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (srcf < destf)
	{
		i = size;
		while (i > 0)
		{
			i--;
			destf[i] = srcf[i];
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, size));
	return (dest);
}
