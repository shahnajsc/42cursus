/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:19:53 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/15 12:19:22 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void *routine(void* arg)
// {
// 	t_philo *philo;

// 	philo = (t_philo  *)arg;
// 	if (philo->philo_id % 2 == 0)
// 	{
// 		printf("%ld philo %d is THINKING\n", get_star_time(), philo->philo_id);
// 	}
// 	else
// 		printf("philo %d is EATING\n", philo->philo_id);
// 	return ((void *)6);
// }
// void	free_thread(t_data *data)
// {

// }
// int thread_test(t_data *data)
// {
// 	pthread_t *thread;
// 	int	i;

// 	i = 0;
// 	thread = malloc(sizeof(pthread_t) * data->arg.philo_total);
// 	if (!thread)
// 		printf("memory not allocated\n");
// 	while (i < data->arg.philo_total)
// 	{
// 		if (pthread_create(&thread[i], NULL, &routine, &data->philo[i]) != 0)
// 		{
// 			free(thread);
// 			thread = NULL;
// 			return (1);
// 		}
// 		data->philo[i].thread_id = thread[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < data->arg.philo_total)
// 	{
// 		pthread_join(thread[i], NULL);
// 		i++;
// 	}
// 	free(thread);
// 	return (0);
// }
