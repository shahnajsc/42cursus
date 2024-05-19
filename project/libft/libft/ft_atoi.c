/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahnaj <shahnaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:30:23 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/19 23:19:30 by shahnaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			signcount;
	long int	number;
	long int	check;

	signcount = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signcount = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		check = (number * 10) + *str - 48;
		if (check / 10 != number && signcount == -1)
			return (0);
		if (check / 10 != number && signcount == 1)
			return (-1);
		number = check;
		str++;
	}
	return (number * signcount);
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{

printf("+46: %d - %d\n", ft_atoi("+46"), atoi("+46"));
	printf("a+47: %d - %d\n", ft_atoi("a+47"), atoi("a+47"));
	printf("   +48: %d - %d\n", ft_atoi("   +48"), atoi("   +48"));
	printf("49: %d - %d\n", ft_atoi("\t\n\r\v\f +48"), atoi("\t\n\r\v\f +48"));
	printf("50: %d - %d\n", ft_atoi("\016 50"), atoi("\016 50"));
	printf("empty string: %d - %d\n", ft_atoi(""), atoi(""));
	printf("INT_MAX: %d - %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("INT_MAX + 1: %d - %d\n", ft_atoi("2147483648"), atoi("2147483648"));
	printf("INT_MIN: %d - %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("INT_MIN - 1: %d - %d\n", ft_atoi("-2147483649"), atoi("-2147483649"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666"), atoi("666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666"), atoi("666666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666666"),
			atoi("666666666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666666666"),
			atoi("666666666666666666666"));
	printf("-Giant: %d - %d\n", ft_atoi("-6666666666666666666666666666666"),
			atoi("-6666666666666666666666666666666"));
printf("-Giant: %d - %d\n", ft_atoi("-2147483648") + 1,
			atoi("-2147483648") + 1);

if ((ft_atoi("-2147483649")) == 0)
{
	printf(" under flow ");
}
if ((ft_atoi("-2147483649")) == -1)
{
	printf(" overflow ");
}
else
	printf(" no way ");
}