//#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		len = 0;
	if (size - start < len)
		len = size - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
	char	*str;

	i = 0;
	j = 0;
	str = (char *)s;
	while (i < str_count)
	{
		while (str[j] != '\0' && str[j] == c)
			j++;
		array[i] = ft_substr(str, j, get_substr_len(&str[j], c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (str[j] != '\0' && str[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
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