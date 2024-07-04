/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:54:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/04 15:54:25 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (str[len])
	{
		if (write(1, &str[len], 1) != 1)
			return (-1);
		len++;
	}
	return (len);
}