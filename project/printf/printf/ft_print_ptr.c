/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:24:33 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/08 16:05:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	int	p_len;

	p_len = 0;
	if (ptr == 0)
	{
		p_len = ft_print_str(PTR_NULL);
		if (p_len == -1)
			return (-1);
		return (p_len);
	}
	p_len += ft_print_str("0x");
	if (p_len == -1)
		return (-1);
	p_len += ft_print_hex(ptr, HEX_LOWER);
	if (p_len == -1)
		return (-1);
	return (p_len);
}
