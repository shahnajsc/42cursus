/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:18:48 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/15 12:33:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[count] == s2[count]) && (s1[count] != '\0') && (count < n - 1))
	{
		count++;
	}
	if (s1[count] == s2[count])
	{
		return (0);
	}
	else
	{
		return ((unsigned char)(s1[count]) - (unsigned char)(s2[count]));
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    char *dst = "18123458";
	char *src = "18123448";
	int n = 9;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
    printf("after ft strncmp: %d\n", ft_strncmp(dst, src, n));
	printf("after lib strncmp: %d\n", strncmp(dst, src, n));
}
*/
