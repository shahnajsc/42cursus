/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:17:00 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/11 23:32:47 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) != 6)
		{
			return (-1);
		}
		return (6);
	}
	while (str[count])
	{
		if (write(1, &str[count], 1) != 1)
		{
			return (-1);
		}
		count++;
	}
	return (count);
}
