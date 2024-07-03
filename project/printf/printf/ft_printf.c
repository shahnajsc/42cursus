/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/03 14:04:05 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
		if (format == 'c')
			print_len = ft_printchar(va_arg(args, int));
		else if (format == 's')
			print_len = ft_printstr(va_arg(args, char *));
		else if (format == '%')
			print_len =  ft_printpercent();
		else if (format == 'd' || format == 'i')
			print_len = ft_printnum(va_arg(args, int));
		else if (format == 'p')
			print_len = ft_print_ptr(va_arg(args, int));
		else if (format == 'u')
			print_len = ft_print_unsigned(va_arg(args, int));
		else if (format == 'x')
			print_len = ft_print_hex(va_arg(args, int), 'x');
		else if (format == 'X')
			print_len = ft_print_hex(va_arg(args, int), 'X');
		if (print_len == -1)
		{
			return (-1);
		}
		return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	print_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			print_len += ft_formats(args, (*(++str)));
			if (print_len == -1)
				return (-1);
		}
		else
		{
			print_len += ft_printchar(*str);
			if (print_len == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (print_len);
}
