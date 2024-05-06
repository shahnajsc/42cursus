/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:42:04 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/26 09:59:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = (char *)s;
	while (count < n)
	{
		ptr[count] = 0;
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
#include <stdio.h>

int main(void)
{
*/
