/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/11 17:12:43 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

static char *fill_read_buffer(int fd, char *read_buffer, char *left_buffer)
{
    ssize_t read_bytes;
    char    *tmp_left_buffer;

    if (fd < 0)
    {
        free(read_buffer);
        free(left_buffer);
        return (NULL);
    }
    read_bytes = 1;
    while (read_bytes > 0)
    {
    read_bytes = read(fd, read_buffer, BUFFER_SIZE);
    if (read_bytes == -1)
    {
        free(left_buffer);
        return (NULL);
    }
    if (read_bytes == 0)
    {
        break;
    }
    read_buffer[read_bytes] = '\0'; 
    if (!left_buffer)
    {
        left_buffer = ft_strdup("");
    }
    tmp_left_buffer = left_buffer;
    left_buffer = ft_strjoin(tmp_left_buffer, read_buffer);
    free(tmp_left_buffer);
    tmp_left_buffer = NULL;
    if (ft_strchr(read_buffer, '\n'))
    {
        break;
    }
    }
    return(left_buffer);
}

static char *set_line(char *read_buffer)
{
    char    *left_buffer;
    size_t  count;

    count = 0;
    while (read_buffer[count] != '\n' && read_buffer[count] != '\0')
        count++;
    if (read_buffer[count] == 0 || read_buffer[1] == 0)
        return (NULL);
    left_buffer = ft_substr(read_buffer, count + 1, ft_strlen(read_buffer) - count);
    if (*left_buffer == 0)
    {
        free(left_buffer);
        left_buffer = NULL;
    }   
    read_buffer[count + 1] = 0;
    return (left_buffer);
}

char *get_next_line(int fd)
{
    char        *read_buffer;
    static char *left_buffer;
    char        *line_read;

    read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0)< 0)
    {
        free(read_buffer);
        free(left_buffer);
        read_buffer = NULL;
        left_buffer = NULL;
        return (NULL);
    }
    if (!read_buffer)
    {
        return (NULL);
    }
    line_read = fill_read_buffer(fd, read_buffer, left_buffer); // the text read including the text after line (if any). 
    free(read_buffer);
    read_buffer = NULL;
    if (!line_read)
        return (NULL);
    left_buffer = set_line(line_read);
    return (line_read);
    //left_buffer = NULL; // reamining part of read buffer after the coplete line.
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
    
}*/