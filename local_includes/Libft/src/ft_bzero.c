/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:44:38 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/13 15:42:31 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Sets memory to 0
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!s)
		return ;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
