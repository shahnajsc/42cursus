/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:53:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/10 15:05:04 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

char *get_next_line(int fd)
{
    char *read_buffer;
    ssize_t bytes_buffer;
    static char *left_buffer;
    char *line;
    ssize_t i;

    if (fd < 0 )
    {
        return (NULL);
    }
    read_buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
    if (!read_buffer)
    {
        return (NULL);
    }
    bytes_buffer = 1;
    while (bytes_buffer > 0)
    {
    ssize_t bytes_buffer = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_buffer == -1)
    {
        return (NULL);
    }
    else if (bytes_buffer == 0)
        break;
    read_buffer[bytes_buffer] = '\0';
    i = 0;
    while (read_buffer[i] != '\n' || read_buffer[i] != '\0')
    {
        i++;
    }
    if (read_buffer[i] == '\n')
    {
        line = ft_strdup(read_buffer);
    }
    else if(read_buffer == '\0')
    {
        left_buffer = ft_strjoin(left_buffer, read_buffer);
    }
    
    }
}
