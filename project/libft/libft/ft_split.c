/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:02:38 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/02 17:17:20 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int words;
	int i;

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
}

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
