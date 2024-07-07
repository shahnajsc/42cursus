/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:20:51 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/07 16:00:12 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	if (write(1, &c, 1) != 1)
	{
		return (-1);
	}
	return (1);
}

int	ft_print_percent(void)
{
	if (write(1, "%", 1) != 1)
	{
		return (-1);
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char )c)
		return ((char *)s);
	return (0);
}
