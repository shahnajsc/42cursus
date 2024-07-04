/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:51:38 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/04 15:51:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int num, char *str)
{
	int				i;
	unsigned int	n;
	unsigned int	hex_len;

	i = 0;
	n = (unsigned int)num;
	hex_len = str_length(str);
	if (n >= hex_len)
	{
		i = ft_puthex(n / hex_len, str);
		if (i == -1)
			return (-1);
		if (write(1, &str[n % hex_len], 1) == -1)
			return (-1);
		i++;
	}
	else
	{
		if (write(1, &str[n], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}