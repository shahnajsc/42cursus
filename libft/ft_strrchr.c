/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:46:07 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/17 13:19:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	/*char	*str;

	str = (char *)s;
	 + ft_strlen(s);
	while (str >= s)
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str--;
	}
	return (NULL);*/
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{	
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	return (NULL);
}
/*
	-It locates the LAST occurence of 'c' in the string.
	- 'c' converted to a char.
	- '\0' NULL terminator is also considered as character of string 's'
		and locates.
	- Returns pointer to the located character or NULL if no occurence.
*/