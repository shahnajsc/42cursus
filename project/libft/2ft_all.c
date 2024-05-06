/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ft_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:42:16 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/22 10:37:01 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_memcpy(char *restrict dst, const char *restrict src, int n)
{

	int count;

	if(!dst && !src)
	{
		return (0);
	}
	count = 0;
	while (count < n)
	{
		dst[count] = src[count];
		count++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int main (void)
{
	// memcpy
	char dst[] = "123456789";
	char src[] = "abcd";
	int n = 7;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("after ft memcpy: %s\n", ft_memcpy(dst, src, n));
	printf("after lib memcpy: %s\n", memcpy(dst, src, n));
}

