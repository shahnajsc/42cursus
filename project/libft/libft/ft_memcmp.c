/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:05:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/24 16:39:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (str1[count] != str2[count])
		{
			return (str1[count] - str2[count]);
		}
		count++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    char *dst = "18123458";
	char *src = "18\\23448";
	int n = 9;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
    printf("after ft strncmp: %d\n", ft_memcmp(dst, src, n));
	printf("after lib strncmp: %d\n", memcmp(dst, src, n));
}
*/
