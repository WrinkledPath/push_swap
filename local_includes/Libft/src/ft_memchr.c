/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:47:58 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 18:56:20 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*cstr;

	cstr = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == (unsigned char)c)
			return ((void *) &cstr[i]);
		i++;
	}
	return (NULL);
}
