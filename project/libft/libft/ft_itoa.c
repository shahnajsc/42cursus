/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:18:32 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/30 16:47:53 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	int				is_neg;
	unsigned int	nbr;

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
/*
int main(void)
{
    char *res = ft_itoa(9); 
	
    ft_print_result(res);
    free(res);
}
*/
/* check for :0, 9, -9, 10, -10,
	  8124, -9874, 543000, -2147483648LL, 2147483647*/
