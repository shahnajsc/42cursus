/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:01:04 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/29 09:44:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates memory with function malloc() for a new string 
 * and return a pointer to that new string. */
/* New string is concatenation of string s1 and s2. s1 is prefix. */
/* Returns NULL if memory allocation fails. */

#include "libft.h"

/*int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*ptr;
	char			*ptrcat;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (NULL);
	ptrcat = ptr;
	while (*s1)
	{
		*ptr++ = *s1++;
	}
	while (*s2)
	{
		*ptr++ = *s2++;
	}
	*ptr++ = '\0';
	return (ptrcat);
}
/*
#include<stdio.h>
int main()
{
	char	s1[] = "abcdef";
	char s2[] = "ghigklm";

	printf("%s\n", ft_strjoin(s1, s2));
}
*/
