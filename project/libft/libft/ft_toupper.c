/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:08:11 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/24 10:49:44 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("from ft: %d\n", ft_toupper('$'));
	printf("from lib: %d\n", toupper('$'));
}
*/
