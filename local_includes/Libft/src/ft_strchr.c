/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:49:26 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 17:49:29 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Returns a pointer to the first chr ocurrance
char	*ft_strchr(const char *str, int chr)
{
	if (!str)
		return (NULL);
	while (*str != (char) chr && *str)
		str++;
	if (*str == (char) chr)
		return ((char *) str);
	return (NULL);
}
