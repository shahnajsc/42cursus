/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:16:46 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/27 21:45:10 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_philo(void *arg)
{
	t_philo *philo;
	//int i = 0;

	philo = (t_philo  *)arg;
	if (thinking_philo(philo))
		return (NULL);
	if (philo->philo_id % 2 == 0 && philo->data->arg.philo_total != 1)
	{
		if (philo_waiting(philo, philo->data->arg.eat_time - 10))
			return (NULL);
	}
	while (philo->philo_state == ACTIVE) //philo->dead_flag == 0
	{
		if (eating_philo(philo))
			return (NULL);
		if (sleeping_philo(philo))
			return (NULL);
		if (thinking_philo(philo))
			return (NULL);
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

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_create(&data->threads[i], NULL, &routine_philo, &data->philo[i]) != 0)
		{
			pthread_mutex_lock(&data->data_update);
			data->sim_state = FAILURE;
			usleep(100);
			pthread_mutex_lock(&data->data_update);
			while(i--)
				pthread_join(data->threads[i], NULL);
			return (data_error("Thread creatiion failed"));
		}
		data->philo[i].thread_id = data->threads[i];
		i++;
	}
	return (0);
}

t_simstate	simulation_initiate(t_data *data)
{

	if (create_thread(data))
	{
		free_clean_exit(data);
		return (FAILURE);
	}
	if (simulation_monitor(data) == FAILURE)
	{
		free_clean_exit(data);
		return (FAILURE);
	}
	if (wait_to_join(data))
	{
		free_clean_exit(data);
		return (FAILURE);
	}
	//printf("%ld All philosophers finished their maximum meals\n", get_time_ms() - data->arg.start_time);
	free_clean_exit(data);
	return (FINISH);
}
