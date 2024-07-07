/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:24:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/06 22:51:33 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	ft_len_hex(unsigned	long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{ 
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void ft_get_hex(unsigned long nbr, const char format)
{
    if (nbr >= 16)
    {
        ft_get_hex(nbr / 16, format);
        ft_get_hex(nbr % 16, format);
    }
    else
    {
        if (nbr < 10)
        {
            ft_print_char(nbr + '0');
        }
        else
        {
            if (format == 'X')
            {
                ft_print_char(nbr - 10 + 'A');
            }
            else
            {
                ft_print_char(nbr - 10 + 'a');
            }
        }
    }
}

int ft_print_hex(unsigned long nbr, const char format)
{
    int p_len;

    p_len = 0;
   
    ft_get_hex(nbr, format);
    p_len = ft_len_hex(nbr);
    if (p_len == -1)
        return (-1);
    return (p_len);
}
*/

int	ft_print_hex(unsigned long nbr, char *strhex)
{
	int	p_len;

	p_len = 0;
	if (nbr >= 16)
	{
		p_len += ft_print_hex(nbr / 16, strhex);
		if (p_len == -1)
			return (-1);
		p_len += ft_print_char(strhex[nbr % 16]);
		if (p_len == -1)
			return (-1);
	}
	else
	{
		p_len += ft_print_char(strhex[nbr]);
		if (p_len == -1)
			return (-1);
	}
	return (p_len);
}
