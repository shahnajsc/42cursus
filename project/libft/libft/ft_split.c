/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:02:38 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/15 15:42:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

static size_t	count_words2(char const *s, char c)
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

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

/*static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
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
}*/

#include <stdio.h>
int main(void)
{
	printf("word count 1: %ld\n", count_words("a123a456a789a012a12a", 'x'));
	printf("word count 2: %ld\n", count_words2("a123a456a789a012a12a", 'x'));

	printf("%ld\n", get_word_len("a123a456a7894a012a12a", 'x'));
}
/*static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	words = ft_strlen(s + i) ? 1 : 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static int	len_first_word(char const *s, char c)
{
	int i;
	int chars;

	chars = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		chars++;
		i++;
	}
	return (chars);
}

static int	fill_word(char *word, char const *s, char c)
{
	int i;
	int j;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = 0;
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

void		emergency_clean(char **array, int arr_i)
{
	while (--arr_i >= 0)
		free(array[arr_i]);
	free(array);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		arr_i;
	int		word_len;

	array = NULL;
	if (s && (array = malloc(sizeof(char*) * (count_words(s, c) + 1))))
	{
		arr_i = 0;
		if (count_words(s, c))
		{
			while (*s)
			{
				word_len = len_first_word(s, c) + 1;
				if ((array[arr_i] = malloc(word_len)))
					s += fill_word(array[arr_i++], s, c);
				else
				{
					emergency_clean(array, arr_i);
					return (NULL);
				}
			}
		}
		array[arr_i] = NULL;
	}
	return (array);
}*/

/*
char **ft_split(char const *s, char c)
{
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
*/	
