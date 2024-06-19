/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:50:29 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/19 09:51:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX_FD 1024
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 6

# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_len_line(char *str);

#endif
