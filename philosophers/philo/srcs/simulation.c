/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:16:46 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/24 14:15:19 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_philo(void *arg)
{
	t_philo *philo;
	//int i = 0;

	philo = (t_philo  *)arg;
	thinking_philo(philo);
	if (philo->philo_id % 2 == 0 && philo->data->arg.philo_total != 1)
		philo_waiting(philo, philo->data->arg.eat_time - 10);
	while (philo->philo_state == ACTIVE) //philo->dead_flag == 0
	{
		eating_philo(philo);
		sleeping_philo(philo);
		thinking_philo(philo);
		//i++;
		//printf(" %d has complted slot[%d] status: %d\n", philo->philo_id, i, philo->data->sim_state);
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

t_simstate	simulation_initiate(t_data *data)
{
	int	i;

	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_create(&data->threads[i], NULL, &routine_philo, &data->philo[i]) != 0)
		{
			free_clean_exit(data);
			printf("Thread creatiion failed\n");
			return (FAILURE);
		}
		data->philo[i].thread_id = data->threads[i];
		i++;
	}
	// pthread_mutex_lock(&data->data_update);
	// 	data->sim_state = RUNNING;
	// pthread_mutex_unlock(&data->data_update);
	// printf("1. thread creation done\n");
	if (simulation_monitor(data) == FAILURE)
	{
		free_clean_exit(data);
		return (FAILURE);
	}
	// printf("2. simulation done\n");
	if (wait_to_join(data))
	{
		free_clean_exit(data);
		return (FAILURE);
	}
	// printf("3. wait join done\n");
	free_clean_exit(data);
	return (FINISH);
}
