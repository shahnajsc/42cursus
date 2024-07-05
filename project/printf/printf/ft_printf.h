/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:38:21 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/05 12:32:40 by shachowd         ###   ########.fr       */
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

int	ft_print_char(char c);
int	ft_print_percent(void);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsign(unsigned int nbr);
int ft_print_ptr(unsigned long long ptr);
int ft_print_hex(unsigned int n, const char format);
int	ft_printf(const char *str, ...);

#endif
