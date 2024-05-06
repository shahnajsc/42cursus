/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:31:36 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/24 16:04:49 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (*str == ch)
		{
			return (str);
		}
		str++;
		count++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "1294567r";
	int c = 114;
	
	printf("from lib function: %s\n", memchr(str, c, 15));
	printf("from ft function: %s\n", ft_memchr(str, c, 15));
}
*/
