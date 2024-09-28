/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:03:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/28 19:55:40 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*line_mem_realloc(t_pipex *data, char *line, int new_buf_size)
{
	char	*new_line;

	new_line  = (char *)malloc(new_buf_size * sizeof(char));
	if (!new_line)
	{
		free(line);
		read_err_return(data, "malloc()", "", 1);
	}
	ft_memcpy((char *)new_line, line, new_buf_size / 2);
	free(line);
	return(new_line);

}

static char	*read_line(t_pipex *data, int fd, int i, int hd_fd)
{
	char	*line;
	int		read_byte;
	char	read_char;
	int		buffer_size;

	buffer_size = BUFFER_SIZE;
	line = (char *)malloc(sizeof(char) * buffer_size);
	if (!line)
		read_err_return(data, "malloc()", "", 1);
	while (1)
	{
		read_byte = read(fd, &read_char, 1);
		if (read_byte == -1)
		{
			close(hd_fd);
			close(0);
			read_err_return(data, "read()", line, 1);
		}
		if (read_byte == 0 || read_char == '\n')
		{
			if (read_char == '\n')
				line[i++] = read_char;
			break ;
		}
		line[i++] = read_char;
		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
			line = line_mem_realloc(data, line, buffer_size);
		}
	}
	line[i] = '\0';
	return (line);
}

void	read_here_doc(t_pipex *data)
{
	char	*line_text;
	int		hd_fd;

	hd_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (hd_fd == 1)
		error_return(data, "open()", "", 1);
	while (1)
	{
		line_text = read_line(data, 0, 0, hd_fd);
		if (!line_text)
		{
			free(line_text);
			break ;
		}
		if (ft_strncmp(line_text, data->argv[2], ft_strlen(line_text) - 1) == 0)
		{
			break ;
		}
		ft_putstr_fd(line_text, hd_fd);
		free(line_text);
	}
	close(hd_fd);
	if (!line_text)
		error_return(data, "read()", "", 1);
	free(line_text);

}
