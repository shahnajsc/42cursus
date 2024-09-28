/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:03:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/27 17:00:10 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrdst;
	char	*ptrsrc;

	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (!dst && !src)
	{
		return (0);
	}
	while (n--)
	{
		ptrdst[n] = ptrsrc[n];
	}
	return (dst);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[count] == s2[count]) && s1[count] && (count < n - 1))
	{
		count++;
	}
	if (s1[count] == s2[count])
	{
		return (0);
	}
	else
	{
		return ((unsigned char)(s1[count]) - (unsigned char)(s2[count]));
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

static char	*line_mem_realloc(char *line, int new_buf_size)
{
	char	*new_line;

	new_line  = (char *)malloc(new_buf_size * sizeof(char));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_memcpy((char *)new_line, line, new_buf_size / 2);
	free(line);
	return(new_line);

}

static char	*get_line(int fd, int buffer_size)
{
	char	*line;
	int		read_byte;
	char	read_char;
	int		i;

	line = (char *)malloc(sizeof(char) * buffer_size);
	if (! line)
		return (NULL);
	read_byte = 1;
	i = 0;
	while (read_byte > 0 && read_char != '\n')
	{
		read_byte = read(fd, &read_char, 1);
		if (read_byte == -1)
			return (0); 
		if (read_byte == 0 || read_char == '\n')
			break;
		line[i++] = read_char;
		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
			line = line_mem_realloc(line, buffer_size);
		}
	}
	line[i] = '\0';
	return (line);
}

int	main()
{
	char	*line_text;
	int		hd_fd;
	char *deli = "EOF";

	hd_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (hd_fd == 1)
		return 0;
		//error_return(data, "open()", "", 1);
	while (1)
	{
		line_text = get_line(0, 6);
		if (!line_text)
		{
			free(line_text);
			break ;
		}
		if (ft_strncmp(line_text, deli, ft_strlen(line_text) -1) == 0)
		{
			free(line_text);
			break ;
		}
		write(hd_fd, line_text, ft_strlen(line_text));
		free(line_text);
	}
	close(hd_fd);
	if (!line_text)
		return 0;
		// error_return(data, "get_next_line()", "", 1);
	return(0);
}

