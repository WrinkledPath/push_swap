/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:45:11 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 18:56:44 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*srcf;
	unsigned char	*destf;

	i = 0;
	if (!dest || !src)
		return (dest);
	srcf = (unsigned char *)src;
	destf = (unsigned char *)dest;
	while (i < size)
	{
		destf[i] = srcf[i];
		i++;
	}
	return (dest);
}
