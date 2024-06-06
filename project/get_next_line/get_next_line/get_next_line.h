/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:31:55 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/06 13:44:34 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	    ft_strlen(const char *str);
char        *ft_strdup(const char *str);
char        *ft_strchr(const char *s, int c);
char	    *ft_strjoin(const char *s1, const char *s2);
char	    *ft_substr(const char *str, unsigned int start, size_t len);


#endif