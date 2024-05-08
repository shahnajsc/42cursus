/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:37:49 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/07 16:35:24 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*ptrdst;
	char	*ptrsrc;

	count = 0;
	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (!ptrdst && !ptrsrc)
		return (dst);
	if (ptrdst == ptrsrc)
		return (dst);
	if (ptrdst > ptrsrc)
	{
		while (count < n)
		{
			ptrdst[count] = ptrsrc[count];
		}
	}
	else
	{
		while (count < n)
			*(char *)dst++ = *(char *)src++;
	}
	return (dst);
}
/*i

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
}
*/
