/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:24:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/01 11:09:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex(unsigned int n, const char format)
{
    int print_len;

    print_len = 0;
    if (n >= 16)
    {
        print_len = ft_print_hex(n / 16, format);
        if (print_len == -1)
            return (-1);
        print_len = ft_print_hex(n % 16, format);
        if (print_len == -1)
            return (-1);
    }
    else
    {
        if (n <=9)
            return (ft_printchar(n + '0'));
        else
        {
            if (format == 'x')
                return ((n - 10 + 'a'));
            else if (format == 'X')
                return ((n -10 + 'A'));
        }
    }
}
