/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:56:18 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/04 07:38:52 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
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
		return (0);
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

int	ft_print_unsigned(unsigned int nbr)
{
	int		len;
	char	*num;

	len = 0;
	if (nbr == 0)
	{
		len = ft_printchar('0');
		//len += ft_printchar('0');
	}
	num = ft_uitoa(nbr);
	/*if (!num)
	{
		return (-1);
		free(num);
	}*/
	len += ft_printstr(num);
    /*if (len == -1)
        return (-1);*/
	free(num);
	return (len);
}