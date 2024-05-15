/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:39:02 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/15 12:32:56 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[count] != '\0' && count < (dstsize -1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dst[20];
	char src[] = "abcdefghi";

	int liblen= strlcpy(dst, src, sizeof(dst));
	int ftlen = ft_strlcpy(dst, src, sizeof(dst));
	printf("lib length copied: %d\n", liblen);
	printf("lib copied string: %s\n\n", dst);

	printf("ft length: %d\n", ftlen);
	printf("ft copied string: %s\n", dst);
}
*/
