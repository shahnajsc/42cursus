/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/27 11:18:24 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_formats(va_list args, const char format)
{
	//int	print_length;

	//print_length = 0;
	if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == '%')
		return (ft_printpercent());
	else if (format == 'd' || format == 'i')
		return (ft_printnum(va_arg(args, int)));
	else
		return (-1);
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
			i++;
		}
		else
		{
			print_length += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}
