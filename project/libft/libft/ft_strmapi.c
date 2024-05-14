/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahnaj <shahnaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:23:39 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/14 22:39:20 by shahnaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s)) + 1));
	if (!str)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <ctype.h>
char ftcheck(unsigned int i, char c)
{
   if (i == 0 || i == 4)
    //printf("My inner function: index = %d and %c\n", i, str);
    return c - 32;
   else
    return '\t';
}

char ftupper(unsigned int i, char c)
{
    if (i % 2 == 0)
        return toupper(c);
    else
        return tolower(c);
}

int main()
{
char str[10] = "hello";
printf("The result is %s\n", str);
char *result = ft_strmapi(str, ftcheck);
printf("The result is %s\n", result);

char str1[10] = "cat.";
printf("The result is %s\n", str1);
char *result1 = ft_strmapi(str1, ftupper);
printf("The result is %s\n", result1);
return 0;
}
*/
