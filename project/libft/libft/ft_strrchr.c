/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:46:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/24 14:28:26 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_strlen(const char *s)
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
char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s + ft_strlen(s);
	while (*str != c)
	{
		if (str == s)
		{
			return (NULL);
		}
		str--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "abcdefgh123456e";

	printf("from lib function: %s\n", strrchr(s, '3'));
	printf("from ft function: %s\n", ft_strrchr(s, '3'));
}
*/
