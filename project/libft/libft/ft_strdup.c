/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:07:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/26 11:00:24 by shachowd         ###   ########.fr       */
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
char	*ft_strdup(const char *src)
{
	unsigned int	len;
	unsigned int	count;
	char			*ptr;

	count = 0;
	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		return (NULL);
	}
	while (count < len)
	{
		ptr[count] = src[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
/*

#include <stdio.h>

int main(void)
{
	char *s1 = "eretert";

	printf("%s\n", ft_strdup(s1));
}
*/
