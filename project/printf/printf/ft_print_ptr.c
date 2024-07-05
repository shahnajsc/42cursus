/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:24:33 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/05 12:44:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_len_ptr(uintptr_t ptr)
{
    int     len;

    len = 0;
    while (ptr != 0)
    {
        ptr = ptr / 16;
        len++;
    }
    return (len);
}

static void  ft_get_ptr(uintptr_t ptr)
{
    if (ptr >= 16)
    {
        ft_get_ptr(ptr / 16);
        ft_get_ptr(ptr % 16);
    }
    else
    {
        if (ptr < 10)
        {
            ft_print_char(ptr + '0');
        }
        else
        {
            ft_print_char(ptr - 10 + 'a');
        }
    }
}

int ft_print_ptr(unsigned long long ptr)
{
    int print_len;

    print_len = 0;
    if (ptr == 0)
    {
        print_len += ft_print_str(NULLPTR);
        if (print_len == -1)
            return (-1);
        return (print_len);
    }
    print_len += ft_print_str("0x");
    ft_get_ptr(ptr);
    print_len += ft_len_ptr(ptr);
    if (print_len == -1)
        return (-1);
    return (print_len);
}