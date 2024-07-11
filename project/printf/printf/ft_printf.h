/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:38:21 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/08 17:40:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# if defined(__linux__)
#  define PTR_NULL "(nil)"
# elif defined(__APPLE__)
#  define PTR_NULL "0x0"
# else
#  define PTR_NULL "Unknown"
# endif

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_print_char(char c);
int		ft_print_percent(void);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_unsign(unsigned int nbr);
int		ft_print_ptr(unsigned long ptr);
char	*ft_strchr(const char *s, int c);
int		ft_print_hex(unsigned long n, char *strhex);
int		ft_printf(const char *str, ...);

#endif
