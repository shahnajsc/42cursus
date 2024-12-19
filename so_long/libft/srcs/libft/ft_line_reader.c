/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:49:42 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/19 21:25:33 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*line_mem_realloc(char *line, int new_buf_size)
{
	char	*new_line;

	new_line = (char *)malloc(new_buf_size * sizeof(char));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_memcpy((char *)new_line, line, new_buf_size / 2);
	free(line);
	return (new_line);
}

static void	read_check(int read_byte, char **line, int i)
{
	if (read_byte == -1)
	{
		free(*line);
		*line = NULL;
	}
	if (read_byte == 0 && i == 0)
	{
		free(*line);
		*line = NULL;
	}
}

char	*ft_line_reader(int fd, char *line, int buffer_size, int index)
{
	int		read_byte;
	char	read_char; // add index variable here if there is line

	line = (char *)malloc(sizeof(char) * buffer_size);
	if (!line)
		return (NULL);
	while (1)
	{
		read_byte = read(fd, &read_char, 1);
		read_check(read_byte, &line, index);
		if (!line || read_byte == 0)
			break ;
		if (read_char == '\n')
			break ;
		line[index++] = read_char;
		if (index >= buffer_size)
		{
			buffer_size += buffer_size;
			line = line_mem_realloc(line, buffer_size);
		}
	}
	if (line)
		line[index] = '\0';
	return (line);
}
