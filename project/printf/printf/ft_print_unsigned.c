/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:56:18 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/01 21:06:36 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{ 
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int nbr)
{
	int				len;
	char			*str;

	len = ft_num_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(int nbr)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_uitoa(nbr);
	len = ft_printstr(num);
	if (!num)
	{
		return (-1);
		free(num);
	}
	free(num);
	return (len);
}