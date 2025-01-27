/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:10 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/27 16:09:19 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_simstate	check_if_dead(t_data *data)
{
	//long	current_time;
	int		i;

	i = 0;
	//current_time = get_time_ms();
	while (i < data->arg.philo_total)
	{
		pthread_mutex_lock(&data->data_update);
		if ((get_time_ms() - data->philo[i].last_meal) >= data->arg.die_time)
		{
			data->philo[i].philo_state = DIED;
			data->sim_state = FAILURE;
			pthread_mutex_unlock(&data->data_update);
			usleep(500);
			print_msg(&data->philo[i], "is dead");
			return (FAILURE);
		}
		pthread_mutex_unlock(&data->data_update);
		i++;
	}
	return (RUNNING);
}

t_simstate	check_max_meals(t_data *data)
{
	int i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		pthread_mutex_lock(&data->data_update);
		if (data->philo[i].meal_eaten == data->arg.meals_total && data->philo[i].philo_state != FULL)
		{
			data->meals_full_philo++;
			data->philo[i].philo_state = FULL;
			pthread_mutex_unlock(&data->data_update);
		}
		pthread_mutex_unlock(&data->data_update);
		i++;
	}
	if (data->meals_full_philo == data->arg.philo_total)
	{
		pthread_mutex_lock(&data->msg_print);
		data->sim_state = FINISH;
		usleep(500);
		printf("%ld All philosophers finished their maximum meals\n", get_time_ms() - data->arg.start_time);
		pthread_mutex_unlock(&data->msg_print);
		return (FINISH);
	}
	return (RUNNING);
}

t_simstate	simulation_monitor(t_data *data)
{
	//int	i = 0;

	while (1)
	{
		if (check_if_dead(data)  == FAILURE)
		{
			return (FAILURE);
		}
		if (check_max_meals(data) == FINISH)
			break ;
	}
	return (FINISH);
}
