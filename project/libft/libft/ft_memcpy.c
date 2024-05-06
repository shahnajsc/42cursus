/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:15:01 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/23 12:38:26 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*ptrdst;
	char	*ptrsrc;

	count = 0;
	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (!dst && !src)
	{
		return (0);
	}
	while (count < n)
	{
		ptrdst[count] = ptrsrc[count];
		count++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	// memcpy
	char dst[] = "123456789";
	char src[] = "abcd";
	int n = 3;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("after ft memcpy: %s\n", ft_memcpy(dst, src, n));
	printf("after lib memcpy: %s\n", memcpy(dst, src, n));
}
*/
