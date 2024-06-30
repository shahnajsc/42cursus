/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/30 10:48:55 by shachowd         ###   ########.fr       */
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
		if (print_len == -1)
		{
			return (-1);
		}
		return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			if (print_length == -1)
				return (-1);
			i++;
		}
		else
		{
			print_length += ft_printchar(str[i]);
			if (print_length == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}
