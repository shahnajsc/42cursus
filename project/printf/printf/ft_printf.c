/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/08 16:43:07 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	va_start(args, str);
	if (!str)
	{
		return (-1);
	}
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








// #include <stdio.h>
// #include <unistd.h>
// #include "ft_printf.h"

// int main()
// {
//     //printf("write: %d\n", write(1, "%", 1));
//     //printf("\nprintf: %d\n", printf("%"));
//    // printf("\nprintf: %d\n", printf("%%"));
//    // printf("\nprintf: %d\n", printf("%%%"));
//    // printf("abcd \n");
//     //printf(NULL);
//     //ft_printf("abcd \n");
//     //ft_printf(NULL);
// }