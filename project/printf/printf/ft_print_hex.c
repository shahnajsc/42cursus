/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:24:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/28 15:06:23 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hex_len(unsigned int n)
{
    int len;

    len = 0;
    while (n)
    {
        len++;
    }
    return (len);
}



int ft_print_hex(char *str)
{
    int hex;

    hex = 0;
}