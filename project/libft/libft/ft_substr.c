/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahnaj <shahnaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:21:31 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/14 22:34:33 by shahnaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* allocate memory with malloc() for a substring. */
/*This substring is obtained from main string s staring from 'start' index. */
/*maximum length of the substring is 'len'. */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	count;
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (0);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	count = 0;
	while (s[count] != '\0' && count < start)
	{
		count++;
	}
	i = 0;
	while (count >= start && i < len)
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