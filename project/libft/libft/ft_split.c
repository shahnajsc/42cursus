/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:02:38 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 12:26:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	get_substr_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split_str(char const *s, char c, char **array, size_t str_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < str_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_substr_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_substr(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split_str(s, c, array, words);
	return (array);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char **array = ft_split("a123a456a789a012a12a", '1');
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", array[i]);
	}

	//printf("%ld\n", get_word_len("a123a456a7894a012a12a", 'x'));
}
*/
/*
	-This function allocates memory with function malloc()
  	 	and returns an array of strings.
	-It splits the given string 's' using the delimeter
   	 	character 'c'.
 	-Given array must end with a 'NULL pointer'. 
	-External function malloc and free.
	-Return Null if memory allocation fails.
	-*It split main string into sub-string using delimeter
	-*first count the total substring 
	-*Thn conut the length if substring
	-*Thn copy the substring using finction ft_substr(string, start, length)
	-*It also free the substring memory if it fails.
	-* Thn allocates memory for array for the total substring +1
	-* Finally subsrings are copies to main array using split_str function.
*/
