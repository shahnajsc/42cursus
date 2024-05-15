/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:21:31 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/15 12:00:21 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* allocate memory with malloc() for a substring. */
/*This substring is obtained from main string s staring from 'start' index. */
/*maximum length of the substring is 'len'. */

#include "libft.h"

static size_t	str_len(char const *s)
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
	unsigned int	count;
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (NULL);
	if (start > str_len(s))
		len = 0;
	else if (len > (str_len(s) - start))
		len = str_len(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	count = 0;
	while (s[count] != '\0' && count < start)
		count++;
	i = 0;
	while ((count < str_len(s)) && i < len)
	{
		ptr[i] = s[count];
		i++;
		count++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include<stdio.h>
int main()
{
	char	s1[] = "hola";

	printf("%s\n", ft_substr(s1, 0, 18446744073709551615));
}
*/
