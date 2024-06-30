/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:41:26 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/29 23:36:21 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
		{
			return (-1);
		}
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}

int	ft_printpercent(void)
{
	//write(1, "%", 1);
	//return (1);
	if (write(1, "%", 1) == -1)
	{
		return (-1);
	}
	else
		return (1);
}