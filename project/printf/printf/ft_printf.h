/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:38:21 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/04 09:41:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>

# if defined(__linux__)
#  define NULLPTR "(nil)"
# elif defined(__APPLE__)
#  define NULLPTR "0x0"
# else
#  define NULLPTR "Unknown"
# endif

int	ft_printchar(char c);
int	ft_printpercent(void);
int	ft_printstr(char *str);
int	ft_printnum(int n);
int	ft_print_unsigned(unsigned int nbr);
int ft_print_ptr(unsigned long long ptr);
int ft_print_hex(unsigned int n, const char format);
int	ft_printf(const char *str, ...);

#endif
