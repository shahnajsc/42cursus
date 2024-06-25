/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:36:40 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/25 22:07:05 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(char const *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

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
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	/*t		i;
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
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);*/
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_strchr("cspdiuxX%", *(str + i + 1)))
		{
			length += ft_formats(args, *(str + i + 1));
			i++;
		}
		else
			length += ft_printchar(*(str + i));
		i++;
	}
	va_end(args);
	return (length);
}
/*
#include <stdio.h>

int main()
{
	printf("lib1: %c %c %c \n", '0', 0, '1');
	ft_printf("ft1: %c %c %c \n", '0', 0, '1');
	printf(" lib2: %c %s %c \n", '1', "234567", '3');
	ft_printf(" ft2: %c %s %c \n", '1', "2", '3');
	printf("lib 3:  %c %c %c \n", '2', '1', 0);
	ft_printf("ft 3:  %c %c %c \n", '2', '1', 0);	
	
	printf("print charac: %c\n", 'A');
	ft_printf("print charac: %c\n", 'A');

	
	ft_printf("print charac: %%\n");
	printf("print charac: %%\n");

	ft_printf("ftprint string: %s\n", "abcdefgh%");
	printf("print string: %s\n", "abcdefgh%");
	ft_printf("ftprint NULL string: %s\n", "");
	printf("print NULL string: %s\n", "");
}
*/