/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:49:13 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/04 15:49:36 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# define HEXBASEL "0123456789abcdef"
# define HEXBASEH "0123456789ABCDEF"

int		ft_putchar(int c);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
size_t	str_length(char *str);
int		ft_putpoint(void *str);
int		ft_putnbr(int n);
int		ft_putnum_unsign(unsigned int n);
int		ft_puthex(int nbr, char *str);

#endif