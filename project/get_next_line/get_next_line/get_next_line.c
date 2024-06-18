/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/18 11:13:34 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd, char *read_buffer, char *left_buffer)
{
	ssize_t	read_bytes;
	char	*tmp_left_buffer;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			return (NULL);
		}
		if (read_bytes == 0)
		{
			break ;
		}
		read_buffer[read_bytes] = '\0';
		tmp_left_buffer = left_buffer;
		left_buffer = ft_strjoin(left_buffer, read_buffer);
		free(tmp_left_buffer);
		if (ft_strchr(read_buffer, '\n'))
		{
			break ;
		}
	}
	free(read_buffer);
	return (left_buffer);
}

static char	*get_line(char *read_buffer)
{
	char	*left_buffer;
	size_t	count;

	count = 0;
	while (read_buffer[count] != '\n' && read_buffer[count] != '\0')
		count++;
	if (read_buffer[count] == 0 || read_buffer[1] == 0)
	{
		free(read_buffer);
		read_buffer = NULL;
		return (NULL);
	}
	left_buffer = ft_substr(read_buffer, count + 1, ft_strlen(read_buffer) - count);
	if (!left_buffer)
	{
		free(read_buffer);
		read_buffer = NULL;
		return (NULL);
	}
	if (ft_strlen(left_buffer) == 0)
	{
		free(read_buffer);
		read_buffer = NULL;
		free(left_buffer);
		left_buffer = NULL;
		return (NULL);
	}
	free(read_buffer);
	read_buffer = NULL;
	return (left_buffer);
}

char	*get_next_line(int fd)
{
	char		*read_buffer;
	static char	*left_buffer;
	char		*line_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_buffer);
		left_buffer = NULL;
		return (NULL);
	}
	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
	{
		free(left_buffer);
		left_buffer = NULL;
		return (NULL);
	}
	left_buffer = get_buffer(fd, read_buffer, left_buffer);
	if (!left_buffer)
	{
		return (NULL);
	}
	line_read = ft_set_newline(left_buffer);
	if (!line_read)
	{
		free(left_buffer);
		left_buffer = NULL;
		return (NULL);
	}
	left_buffer = get_line(left_buffer);
	return (line_read);
}
/*
#include <stdio.h>

int main()
{
    int fd;

    fd = open("textfile.txt", O_RDONLY);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    int  fd;
    char *line;
    int  count;

    count = 0;
    fd = open("textfile.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    } 
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        break ;
        count++;
        printf("[%d]:%s\n", count, line);
        line = NULL;
    }
    close(fd);
    return (0);
    
}
*/
