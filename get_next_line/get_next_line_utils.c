/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:07:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/18 22:24:00 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t	ft_len_line(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0' && str[count] != '\n')
	{
		count++;
	}
	if (str[count] == '\n')
		count++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	if (!str || !c)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	if (*str == (char)c)
	{
		return (str);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char *string, char *buffer)
{
	size_t	len;
	size_t	count;
	char	*words;

	len = ft_strlen(string) + ft_strlen(buffer);
	count = 0;
	words = malloc((len + 1) * sizeof(char));
	if (words == NULL)
		return (NULL);
	len = 0;
	if (string)
	{
		while (string[len] != '\0')
		{
			words[len] = string[len];
			len++;
		}
	}
	while (buffer[count] != '\0')
	{
		words[len + count] = buffer[count];
		count++;
	}
	words[len + count] = '\0';
	return (words);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	count;
	unsigned int	i;

	count = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		len = 0;
	else if (len > (ft_strlen(str) - start))
		len = ft_strlen(str) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (str[count] != '\0' && count < start)
		count++;
	i = 0;
	while ((count < ft_strlen(str)) && i < len)
	{
		ptr[i] = str[count];
		i++;
		count++;
	}
	ptr[i] = '\0';
	return (ptr);
}
