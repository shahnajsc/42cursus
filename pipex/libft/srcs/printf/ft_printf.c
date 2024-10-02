/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/11 23:35:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsign(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), HEX_LOWER));
	else if (format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), HEX_UPPER));
	else if (format == '%')
		return (ft_print_percent());
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	int			p_len;
	va_list		args;
	int			temp_len;

	p_len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *(str + 1)))
			temp_len = ft_check_format(args, (*(++str)));
		else
			temp_len = ft_print_char(*str);
		if (temp_len == -1)
			return (-1);
		p_len += temp_len;
		str++;
	}
	va_end(args);
	return (p_len);
}
