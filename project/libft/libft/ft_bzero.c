/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:14:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/23 12:31:42 by shachowd         ###   ########.fr       */
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
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
		//bzero
	char s[] = "123456789";
	int n = 4;
	printf("main string: %s\n", s);
	bzero(s, n);
	printf("after lib bzero: %s\n", s);
	ft_bzero(s, n);	
	printf("after ft bzero: %s\n", s);
}
*/
