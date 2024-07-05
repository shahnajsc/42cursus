/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:56:14 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/05 10:22:32 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0) 
		len++;
	while (n)
	{ 
		n = n / 10;
		len++;
	}
	return (len);
}

static int	abs_value(int n)
{
	int	number;

	number = 1;
	if (n < 0)
		number = number * -n;
	else
		number = number * n;
	return (number);
}

static char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	int				is_neg;
	unsigned int	nbr;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	len = n_len(n);
	nbr = abs_value(n);
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
	if (is_neg == 1)
		str[0] = '-';
	return (str);
}

int	ft_print_num(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	if (!num)
	{
		return (-1);
		free(num);
	}
	free(num);
	return (len);
}