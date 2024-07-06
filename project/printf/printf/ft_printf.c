/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/06 22:50:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, const char format)
{
	int	p_len;

	p_len = 0;
	if (format == 'c')
		p_len = ft_print_char(va_arg(args, int));
	else if (format == 's')
		p_len = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		p_len = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		p_len = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		p_len = ft_print_unsign(va_arg(args, unsigned int));
	else if (format == 'x')
		p_len = ft_print_hex(va_arg(args, unsigned int), HEX_LOWER);
	else if (format == 'X')
		p_len = ft_print_hex(va_arg(args, unsigned int), HEX_UPPER);
	else if (format == '%')
		p_len = ft_print_percent();
	if (p_len == -1)
	{
		return (-1);
	}
	return (p_len);
}

int	ft_printf(const char *str, ...)
{
	int			p_len;
	va_list		args;

	p_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			p_len += ft_check_format(args, (*(++str)));
			if (p_len == -1)
				return (-1);
		}
		else
		{
			p_len += ft_print_char(*str);
			if (p_len == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (p_len);
}
