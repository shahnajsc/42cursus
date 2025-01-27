/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:39:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/27 16:07:59 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_uatoi(char *str)
{
	long long int	number;

	if (!str)
		return (-1);
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str >= 48 && *str <= 59)
	{
		number = (number * 10) + *str - 48;
		if (number > INT_MAX)
			return (-1);
		str++;
	}
	while (*str && (*str < 48 && *str > 59))
		return (-1);
	return ((int)number);
}

long	get_time_ms(void)
{
	struct timeval		start_time;

	if (gettimeofday(&start_time, NULL) == -1)
		return (-1);
	return ((long)(start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
}

void	print_msg(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->msg_print);
	printf("%ld %d %s\n", (get_time_ms() - philo->data->arg.start_time), philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->msg_print);
}
