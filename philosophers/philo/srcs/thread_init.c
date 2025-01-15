/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:16:46 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/15 16:21:34 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*threadt_print(void *arg)
{
	t_philo *philo;

	philo = (t_philo  *)arg;
	printf("**** Phili %d *****\n", philo->philo_id);
	printf("Meal Eaten: %d\n", philo->meal_eaten);
	printf("Last Meal: %ld\n", philo->last_meal);
	printf("State: %u\n", philo->state);
	printf("Thread id: %lu\n", philo->thread_id);
	printf("Karnel Thread ID: %ld\n", pthread_self());
	printf("\n");
	// printf("inside routin: philo %d\n", philo->philo_id);
	// if (philo->philo_id % 2 == 0)
	// {
	// 	printf("%ld philo %d is THINKING\n", get_star_time(), philo->philo_id);
	// }
	// else
	// 	printf("%ld philo %d is EATING\n", get_star_time(), philo->philo_id);
	return (NULL);
}

// void	*routine(void *arg)
// {
// 	t_philo *philo;

// 	philo = (t_philo  *)arg;
// 	printf("**** Phili %d *****\n", philo->philo_id);
// 	printf("Meal Eaten: %d\n", philo->meal_eaten);
// 	printf("Last Meal: %ld\n", philo->last_meal);
// 	printf("State: %u\n", philo->state);
// 	printf("Thread id: %lu\n", philo->thread_id);
// 	printf("\n");
// 	// printf("inside routin: philo %d\n", philo->philo_id);
// 	// if (philo->philo_id % 2 == 0)
// 	// {
// 	// 	printf("%ld philo %d is THINKING\n", get_star_time(), philo->philo_id);
// 	// }
// 	// else
// 	// 	printf("%ld philo %d is EATING\n", get_star_time(), philo->philo_id);
// 	return (NULL);
// }

int	thread_initiate(t_data *data)
{
	int	i;
	int t = 0;

	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_create(&data->threads[i], NULL, &threadt_print, &data->philo[i]) != 0)
		{
			free(data->threads);
			data->threads = NULL;
			return (data_error("Thread creatiion failed"));
		}
		// else
		// {
		// 	printf("Karnel Thread ID: %ld\n", pthread_self());
		// }
		// 	printf(" thread created: %d  %ld\n", i + 1, get_star_time());
		data->philo[i].thread_id = data->threads[i];
		i++;
	}
	i = 0;
	while ( i < data->arg.philo_total)
	{
		if (pthread_join(data->philo[i].thread_id, NULL) != 0)
			return (data_error("Thread joined failed"));
		t = t + 1;
		pthread_mutex_lock(&data->plock);
		//printf("value of t: %d\n", t);
		pthread_mutex_unlock(&data->plock);
		i++;
	}
	i = 0;
	// while ( i < data->arg.philo_total)
	// {
	// 	//pthread_mutex_lock(&data->plock);
	// 	t = t + 1;
	// 	printf("value of t: %d\n", t);
	// 	//pthread_mutex_unlock(&data->plock);
	// 	i++;
	// }
	// pthread_mutex_destroy(data->philo->plock);
	//printf("value of t: %d\n", i);
	return (0);
}
