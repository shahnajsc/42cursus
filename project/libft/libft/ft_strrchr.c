/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:46:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/14 16:33:14 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s + ft_strlen(s);
	while (str >= s)
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char s[] = "abcdefgh123456e";

	printf("from lib function: %s\n", strrchr("npe y ceparlos", 'n'));
	printf("from ft function: %s\n", ft_strrchr("npe y ceparlos", 'n'));

	//if (*str == (char)c)
	//{
	//	return (str);
	//}
}
*/
/*
	-It locates the LAST occurence of 'c' in the string.
	- 'c' converted to a char.
	- '\0' NULL terminator is also considered as character of string 's'
		and locates.
	- Returns pointer to the located character or NULL if no occurence.
*/