/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:10 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/20 17:33:11 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_if_dead(t_data *data)
{
	long	current_time;
	int		i;

	i = 0;
	current_time = get_time_ms();
	while (i < data->arg.philo_total)
	{
		pthread_mutex_lock(&data->data_update);
		if ((current_time - data->philo->last_meal) >= data->arg.die_time)
		{
			pthread_mutex_unlock(&data->data_update);
			print_msg(&data->philo[i], "is dead");
			return (1);
		}
		pthread_mutex_unlock(&data->data_update);
		i++;
	}
	return (0);
}

int	check_max_meals(t_data *data)
{
	int i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		pthread_mutex_lock(&data->data_update);
		if (data->philo[i].meal_eaten == data->arg.meals_total)
			data->meals_full_philo++;
		pthread_mutex_unlock(&data->data_update);
		i++;
	}
	if (data->meals_full_philo == data->arg.philo_total)
		return (1);
	return (0);
}

int	simulation_monitor(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (check_if_dead(data))
			return (1);
		if (check_max_meals(data))
			return (0);
	}
	return (0);
}
