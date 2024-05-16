/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:37:49 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 16:19:05 by shachowd         ###   ########.fr       */
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
	- It copies 'len' bytes from string 'src' to 'dst'.
	- Two string may overlap.
	- Copy is always done in a non-destructive manner. 
	- It returns original values of 'dst'. 
	-- It starts from base location and copies untill 'len'
*/