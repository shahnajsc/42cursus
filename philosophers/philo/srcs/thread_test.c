/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:19:53 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/09 18:34:43 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *task_thread(void* i)
{
	int index = *(int *)i;
	printf("number: %d\n", index);
	return ((void *)6);
}

void thread_test(t_data *data)
{
	pthread_t thread;
	int	i;

	i = 0;
	thread = malloc(sizeof(pthread_t) * data->philo_num);
	if (!thread)
		printf("memory not allocated\n");
	while (i < data->philo_num)
	{
		pthread_create(&thread, NULL, &task_thread, &i);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(thread, NULL);
		i++;
	}
}
