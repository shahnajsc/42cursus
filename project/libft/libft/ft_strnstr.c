/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahnaj <shahnaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:40:04 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/19 23:34:23 by shahnaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hcount;
	size_t	ncount;
	size_t	s_len;
	char	*hay;

	hay = (char *)haystack;
	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return (hay);
	s_len = ft_strlen(needle);
	hcount = 0;
	while (hay[hcount] != '\0' && hcount < len)
	{
		ncount = 0;
		while (hay[hcount + ncount] != '\0' && needle[ncount] != '\0'
			&& hay[hcount + ncount] == needle[ncount] && hcount + ncount < len)
		{
			ncount++;
		}
		if (ncount == s_len)
			return (hay + hcount);
		hcount++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", strnstr(NULL, "lo", 0));
	printf("%s\n", ft_strnstr(NULL, "lo", 0));
}
