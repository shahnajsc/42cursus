/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:52:59 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/04 15:53:09 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum_unsign(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len = ft_putnum_unsign(n / 10);
		if (len == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar (('0' + n)) == -1)
			return (-1);
		len++;
	}
	return (len);
}