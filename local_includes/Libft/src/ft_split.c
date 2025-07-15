/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:49:18 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/12 18:11:30 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Splits a String into arrays of strings 
static int	word_len(const char *str, char del)
{
	int	i;

	i = 0;
	while (str[i] != del && str[i] != '\0')
		i++;
	return (i);
}

//Counts the amount of words in str seperated by del
static int	count_words(const char *str, char del)
{
	int	i;
	int	words;
	int	current_word;

	i = 0;
	words = 0;
	current_word = 0;
	while (str[i] != '\0')
	{
		if (!current_word && str[i] != del)
		{
			words++;
			current_word = 1;
		}
		if (current_word && str[i] == del)
			current_word = 0;
		i++;
	}
	return (words);
}

//Frees array when necessary
void	free_split(char **array, int current)
{
	while (current >= 0)
		free(array[current--]);
	free(array);
}

//Main Split Function
char	**ft_split(const char *s, char c)
{
	int		words;
	int		i;
	char	**array;

	words = count_words(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		array[i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
		if (array[i] == NULL)
		{
			free_split(array, i);
			return (NULL);
		}
		ft_strlcpy(array[i], s, word_len(s, c) + 1);
		s += word_len(s, c) + 1;
		i++;
	}
	array[i] = NULL;
	return (array);
}
