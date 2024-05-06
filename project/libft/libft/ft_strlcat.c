/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:15:31 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/24 10:07:44 by shachowd         ###   ########.fr       */
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
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstcount;
	size_t	srccount;

	dstcount = 0;
	srccount = 0;
	while (dstcount < dstsize && dst[dstcount])
	{
		dstcount++;
	}
	while ((dstcount + srccount + 1) < dstsize && src[srccount])
	{
		dst[dstcount + srccount] = src[srccount];
		srccount++;
	}
	if (dstcount != dstsize)
	{
		dst[dstcount + srccount] = '\0';
	}
	return (dstcount + ft_strlen(src));
}
/*

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dst[] = "";
	char src[] = "abcd";

	size_t liblen= strlcat(dst, src, sizeof(dst));
	
	printf("lib length copied: %zu\n", liblen);
	printf("lib copied string: %s\n\n", dst);

	char dst1[] = "";
	char src1[] = "abcd";

	int ftlen = ft_strlcat(dst1, src1, sizeof(dst1));
	printf("ft length: %d\n", ftlen);
	printf("ft copied string: %s\n", dst1);
}
*/
