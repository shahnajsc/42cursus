/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahnaj <shahnaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/18 00:13:11 by shahnaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

static char *get_buffer(int fd, char *read_buffer, char *left_buffer)
{
    ssize_t read_bytes;
    char    *tmp_left_buffer;

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
            break;
        }
     }
    free(read_buffer); // not in sk but needed for me
    read_buffer = NULL;
    return(left_buffer);
}

static char *get_line(char *read_buffer)
{
    char    *left_buffer;
    size_t  count;

    count = 0;
    while (read_buffer[count] != '\n' && read_buffer[count] != '\0')
        count++;
    if (read_buffer[count] == 0 || read_buffer[1] == 0)
        return (NULL);
    left_buffer = ft_substr(read_buffer, count + 1, ft_strlen(read_buffer) - count);
    if (!left_buffer)
    {
        free(left_buffer); // SK
        left_buffer = NULL;
        return (NULL);
    }
    if (ft_strlen(left_buffer) == 0)
    {
        free(left_buffer); // SK
        left_buffer = NULL;
        return (NULL);
    }   
    read_buffer[count + 1] = 0;
    return (left_buffer);
}

char *get_next_line(int fd)
{
    char        *read_buffer;
    static char *left_buffer;
    char        *line_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0)< 0)
    {
        free(left_buffer); // sk
        left_buffer = NULL;
        return (NULL);
    }
    read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!read_buffer)
    {
        free(left_buffer); // sk
        left_buffer = NULL;
        return (NULL);
    }
    line_read = get_buffer(fd, read_buffer, left_buffer);
    if (!line_read)
    {
        return (NULL);
    }
    left_buffer = get_line(line_read);
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

/*
#include  "get_next_line.h"

static char *fill_read_buffer(int fd, char *read_buffer, char *left_buffer)
{
    ssize_t read_bytes;
    char    *tmp_left_buffer;

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
        break;
    }
    read_buffer[read_bytes] = '\0'; 
    if (!left_buffer)
    {
        left_buffer = ft_strdup("");
    }
    tmp_left_buffer = left_buffer;
    left_buffer = ft_strjoin(tmp_left_buffer, read_buffer);
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
    if (!read_buffer)
    {
        return (NULL);
    }
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0)<= 0)
    {
        return (NULL);
    }
    line_read = fill_read_buffer(fd, read_buffer, left_buffer); // the text read including the text after line (if any). 
    if (!line_read)
        return (NULL);
    left_buffer = set_line(line_read);
    return (line_read);
   
}
*/