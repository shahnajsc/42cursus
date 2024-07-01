/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:24:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/01 19:36:27 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void ft_get_hex(unsigned int n, const char format)
{
    if (n >= 16)
    {
        ft_get_hex(n / 16, format);
        ft_get_hex(n % 16, format);
    }
    else
    {
        if (n < 10)
        {
            ft_printchar(n + '0');
        }
        else
        {
            if (format == 'x')
            {
                ft_printchar(n - 10 + 'a');
            }
            if (format == 'X')
            {
                ft_printchar(n - 10 + 'A');
            }
        }
    }
}

int ft_print_hex(unsigned int n, const char format)
{
    int print_len;

    ft_get_hex(n, format);
    print_len = ft_len_hex(n);
    if (print_len == -1)
        return (-1);
    return (print_len);
}
