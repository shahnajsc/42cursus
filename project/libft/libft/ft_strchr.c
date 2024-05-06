/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:12:03 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/25 11:25:35 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "teste";

	printf("from lib function: %s\n", strchr(s, 'e'));
	printf("from ft function: %s\n", ft_strchr(s, 'e'));
}

