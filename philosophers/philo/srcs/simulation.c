/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:16:46 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/20 17:40:36 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


// void	get_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->left_fork);
// 	pthread_mutex_lock(philo->right_fork);
// 	pthread_mutex_unlock(philo->left_fork);
// 	pthread_mutex_unlock(philo->right_fork);
// }

void	*routine_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo  *)arg;
	thinking_philo(philo);
	if  (philo->philo_id % 2 == 0)
		philo_waiting(philo, philo->data->arg.eat_time);
	while (1)
	{
		eating_philo(philo);
		sleeping_philo(philo);
		thinking_philo(philo);
		// if (philo->last_meal + 1 < get_star_time())
		// 	break;
	}
	return (NULL);
}

int	wait_to_join(t_data *data)
{
	int i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
		{
			return (data_error("Thread join failed"));
		}
		i++;
	}
	return (0);
}

int	simulation_initiate(t_data *data)
{
	int	i;

	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_create(&data->threads[i], NULL, &routine_philo, &data->philo[i]) != 0)
		{
			free(data->threads);
			data->threads = NULL;
			return (data_error("Thread creatiion failed"));
		}
		data->philo[i].thread_id = data->threads[i];
		i++;
	}
	simulation_monitor(data);
	if (wait_to_join(data))
		return (1);
	return (0);
}
