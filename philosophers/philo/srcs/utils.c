/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:39:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/30 14:58:26 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_uatoi(char *str)
{
	int		check;
	int		number;

	if (!str)
		return (0);
	check = 0;
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (0);
		str++;
	}
	while (*str >= 48 && *str <= 59)
	{
		check = (number * 10) + *str - 48;
		if (check / 10 != number)
			return (0);
		number = check;
		str++;
	}
	return (number);
}
