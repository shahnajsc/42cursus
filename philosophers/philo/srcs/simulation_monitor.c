/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_monitor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:10 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/30 16:27:08 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	finish_sim(t_philo *philo)
// {
// 	if (philo->left_fork)
// 		pthread_mutex_unlock(philo->left_fork);
// 	if (philo->right_fork)
// 		pthread_mutex_unlock(philo->right_fork);
// 	print_msg(philo, "is dead");
// }

t_simstate	check_if_dead(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		pthread_mutex_lock(&data->data_update);
		if ((get_time_ms() - data->philo[i].last_meal) >= data->arg.die_time)
		{
			data->philo[i].philo_state = DIED;
			data->sim_state = FAILURE;
			usleep(500);
			pthread_mutex_unlock(&data->data_update);
			//print_msg(&data->philo[i], "is dead");
			return (FAILURE);
		}
		pthread_mutex_unlock(&data->data_update);
		i++;
	}
	return (RUNNING);
}

t_simstate	check_max_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		pthread_mutex_lock(&data->data_update);
		if (data->philo[i].meal_eaten == data->arg.meals_total
			&& data->philo[i].philo_state == ACTIVE)
		{
			data->meals_full_philo++;
			data->philo[i].philo_state = FULL;
		}
		pthread_mutex_unlock(&data->data_update);
		i++;
	}
	pthread_mutex_lock(&data->data_update);
	if (data->meals_full_philo == data->arg.philo_total)
	{
		data->sim_state = FINISH;
		usleep(500);
		pthread_mutex_unlock(&data->data_update);
		return (FINISH);
	}
	pthread_mutex_unlock(&data->data_update);
	return (RUNNING);
}

t_simstate	simulation_monitor(t_data *data)
{
	while (1)
	{
		if (check_if_dead(data) == FAILURE)
		{
			return (FAILURE);
		}
		if (check_max_meals(data) == FINISH)
		{
			pthread_mutex_lock(&data->msg_print);
			printf("%ld All philosophers finished their maximum (%d) meals\n",
				get_time_ms() - data->arg.start_time, data->arg.meals_total);
			pthread_mutex_unlock(&data->msg_print);
			break ;
		}
	}
	return (FINISH);
}
