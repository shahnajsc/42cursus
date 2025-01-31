/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:39:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/31 11:31:15 by shachowd         ###   ########.fr       */
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

t_philostat	check_philo_state(t_philo *philo)
{
	t_philostat	state;

	pthread_mutex_lock(&philo->data->data_update);
	state = philo->philo_state;
	pthread_mutex_unlock(&philo->data->data_update);
	return (state);
}

t_simstate	check_sim_state(t_data *data)
{
	t_simstate	state;

	pthread_mutex_lock(&data->data_update);
	state = data->sim_state;
	pthread_mutex_unlock(&data->data_update);
	return (state);
}
