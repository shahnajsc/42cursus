/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:12:03 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/14 14:14:07 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	if (*str == (char)c)
	{
		return (str);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char s[] = "teste";

	printf("from lib function: %s\n", strchr("", '\0'));
	printf("from ft function: %s\n", ft_strchr("", '\0'));
}
*/
/*
	-It locates the FIRST occurence of 'c' in the string.
	- 'c' converted to a char.
	- '\0' NULL terminator is also considered as character of string 's'
		and locates.
	- Returns pointer to the located character or NULL if no occurence.
*/