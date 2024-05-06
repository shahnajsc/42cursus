/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:14:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/23 12:24:44 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			count;
	unsigned char	*ptr;

	count = 0;
	ptr = (unsigned char *)str;
	while (count < len)
	{
		ptr[count] = (unsigned char)c;
		count++;
	}
	return (str);
}
/*
 *
#include <stdio.h>
#include <string.h>
int main(void)
{
	// memset
	char b[] = "-1233456789";
	int len = 4;
	printf("main string: %s\n", b);
	printf("lib memset: %s\n", memset(b, 'Z', len));
	printf("ft memset: %s\n", ft_memset(b, 'u', len));
}
*/
