/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:46:38 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/13 18:28:36 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Creates dynamic memory and initializes it with 0s
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > INT_MAX / size)
		return (NULL);
	tmp = (unsigned char *)malloc(count * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}
