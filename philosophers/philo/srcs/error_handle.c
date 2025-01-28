/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:09:02 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/28 17:23:00 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	data_error(char *err_msg)
{
	printf("Error\n%s ..\n", err_msg);
	return (1);
}

static	void	mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	if (data && data->forks)
	{
		while (i < data->arg.philo_total)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->data_update);
	pthread_mutex_destroy(&data->msg_print);
}

void	free_and_clean(t_data *data)
{
	if (!data)
		return ;
	if (data)
		mutex_destroy(data);
	if (data && data->threads)
	{
		free(data->threads);
		data->threads = NULL;
	}
	if (data && data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
}
