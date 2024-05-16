/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:40:04 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 16:53:16 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haycount;
	size_t	nedcount;
	size_t	s_len;
	char	*hay;

	hay = (char *)haystack;
	s_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return (hay);
	haycount = 0;
	while (hay[haycount] != '\0' && haycount < len)
	{
		nedcount = 0;
		while (hay[haycount + nedcount] != '\0' && needle[nedcount] != '\0'
			&& hay[haycount + nedcount] == needle[nedcount]
			&& haycount + nedcount < len)
		{
			nedcount++;
		}
		if (nedcount == s_len)
			return (hay + haycount);
		haycount++;
	}
	return (0);
}
