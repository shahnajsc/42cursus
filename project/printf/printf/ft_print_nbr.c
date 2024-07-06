/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:32:39 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/06 22:42:17 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int	p_len;

	p_len = 0;
	if (nbr == -2147483648)
		return (ft_print_str("-2147483648"));
	if (nbr < 0 && ++p_len)
	{
		nbr = nbr * -1;
		if (ft_print_char('-') == -1)
			return (-1);
	}
	if (nbr >= 10)
	{
		p_len += ft_print_nbr(nbr / 10);
		if (p_len == -1)
			return (-1);
		nbr = nbr % 10;
	}
	if (nbr <= 9)
	{
		p_len += ft_print_char(nbr + '0');
		if (p_len == -1)
			return (-1);
	}
	return (p_len);
}
