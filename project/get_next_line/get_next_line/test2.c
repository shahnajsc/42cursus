/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:16:32 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/10 15:04:30 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		return (0);
	}
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
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
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	char	*ptrjoin;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
	{
		return (NULL);
	}
	ptrjoin = ptr;
	while (*s1 != '\0')
	{
		*ptr++ = *s1++;
	}
	while (*s2 != '\0')
	{
		*ptr++ = *s2++;
	}
	*ptr++ = '\0';
	return (ptrjoin);
}
char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	int		count;

	if (!str)
	{
		return (0);
	}
	count = 0;
	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		return (NULL);
	}
	while (str[count] != '\0' && count < len)
	{
		ptr[count] = str[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}

char *get_next_line(int fd)
{
    char    *read_buffer;
    ssize_t read_bytes;
    static char *store_buffer;

    if (fd < 0)
    {
        return (NULL);
    }
    read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!read_buffer)
    {
       return (NULL);
    }
    read_bytes = 1;
    while (read_bytes > 0)
    {
        read_bytes = read(fd, read_buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            return (NULL);
        }
        else if (read_bytes == 0)
        {
            break;
        }
        if (!store_buffer)
        {
			store_buffer = ft_strdup("");
        }
        store_buffer = ft_strjoin(store_buffer, read_buffer);
        if (ft_strchr(read_buffer, '\n'))
        {
            break;
        }
    }
    return(store_buffer);
}

int main ()
{
    int fd;

    fd = open("textfile.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("error openning file %d", fd);
    }
    printf(" all text %s", get_next_line(fd));
    close(fd);

}