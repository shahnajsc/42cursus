/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:16:46 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/17 20:40:18 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_msg(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->msg_print);
	printf("%ld %d %s\n", get_star_time(), philo->philo_id, str);
	pthread_mutex_unlock(philo->msg_print);

}

void	wait_philo(t_philo *philo)
{
	
}
void	thinking_philo(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

void	eating_philo(t_philo *philo)
{
	print_msg(philo, "is eating");
}

void	sleeping_philo(t_philo *philo)
{
	print_msg(philo, "is sleeping");
}

void	*routine_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo  *)arg;
	thinking_philo(philo);
	while (1)
	{
		thinking_philo(philo);
		eating_philo(philo);
		sleeping_philo(philo);
		if (philo->last_meal + 1 < get_star_time())
			break;
	}
	return (NULL);
}

int	simulation_initite(t_data *data)
{
	int	i;

	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_create(&data->threads[i], NULL, &routine, &data->philo[i]) != 0)
		{
			free(data->threads);
			data->threads = NULL;
			return (data_error("Thread creatiion failed"));
		}
		data->philo[i].thread_id = data->threads[i];
		i++;
	}
	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_join(data->philo[i].thread_id, NULL) != 0)
			return (data_error("Thread joined failed"));
		i++;
	}
	return (0);
}
