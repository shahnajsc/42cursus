/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:31:55 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/10 15:03:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 6

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t      ft_strlen(const char *str);
//char        *ft_strdup(const char *str);
//char        *ft_strchr(const char *s, int c);
char        *ft_strjoin(const char *s1, const char *s2);
//char        *ft_substr(const char *str, unsigned int start, size_t len);
//void        ill_str(char *res, char *s1, char *s2);
//static char *_set_line(char *line_buffer);
//static char *_fill_line_buffer(int fd, char *left_c, char *buffer);
char        *get_next_line(int fd);

#endif