/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:37:49 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/14 12:45:20 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*ptrdst;
	char	*ptrsrc;

	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (!dst && !src)
		return (dst);
	if (dst == src)
		return (dst);
	if (ptrdst > ptrsrc)
	{
		while (n--)
		{
			ptrdst[n] = ptrsrc[n];
		}
	}
	else
	{
		while (n--)
		{
			*ptrdst++ = *ptrsrc++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	// memcpy
	char dst[] = "1234";
	char src[] = "abcd";
	int n = 2;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("after ft memmove: %s\n", ft_memmove(dst, src, n));
	printf("after lib memmove: %s\n", memmove(dst, src, n));
} */
/*
	- It copies 'len' bytes from string 'src' to 'dst'.
	- Two string may overlap.
	- Copy is always done in a non-destructive manner. 
	- It returns original values of 'dst'. 
	-- It starts from base location and copies untill 'len'
*/
