/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:18:53 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/06 18:38:19 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_unsign(unsigned int nbr)
{
    int p_len;

    p_len = 0;
	if (nbr >= 10)
	{
		p_len = ft_print_unsign(nbr / 10);
        if (p_len == -1)
            return (-1);
        nbr = nbr % 10;
	}
    if (nbr <= 9)
    {
        if (ft_print_char((nbr + '0')) == -1)
            return (-1);
        p_len++;
    }
    return(p_len);
}
