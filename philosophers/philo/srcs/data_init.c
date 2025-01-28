/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:53:22 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/28 16:42:31 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_argument(t_arg *arg, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_uatoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	arg->philo_total = ft_uatoi(argv[1]);
	arg->die_time = ft_uatoi(argv[2]);
	arg->eat_time = ft_uatoi(argv[3]);
	arg->sleep_time = ft_uatoi(argv[4]);
	if (argc == 6)
		arg->meals_total = atoi(argv[5]);
	else
		arg->meals_total = -1;
	arg->fork_total = atoi(argv[1]);
	arg->start_time = get_time_ms();
	if (arg->start_time == -1)
		return (1);
	return (0);
}

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].last_meal = data->arg.start_time;
		data->philo[i].meal_eaten = 0;
		data->philo[i].philo_state = ACTIVE;
		data->philo[i].left_fork = &data->forks[i];
		if (i == data->arg.philo_total - 1)
			data->philo[i].right_fork = &data->forks[0];
		else
			data->philo[i].right_fork = &data->forks[i + 1];
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->msg_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->data_update, NULL) != 0)
	{
		pthread_mutex_destroy(&data->msg_print);
		return (1);
	}
	while (i < data->arg.philo_total)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			pthread_mutex_destroy(&data->msg_print);
			pthread_mutex_destroy(&data->data_update);
			while (i--)
				pthread_mutex_destroy(&data->forks[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	memset(data, 0, sizeof(t_data));
	if (init_argument(&data->arg, argc, argv))
		return (data_error("Invalid argument value"));
	data->meals_full_philo = 0;
	data->sim_state = RUNNING;
	data->threads = malloc(sizeof(pthread_t) * data->arg.philo_total);
	if (!data->threads)
		return (data_error("Memory allocation failed for threads"));
	memset(data->threads, 0, sizeof(pthread_t) * data->arg.philo_total);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->arg.philo_total);
	if (!data->forks)
		return (data_error("Memory allocation failed for forks"));
	memset(data->forks, 0, sizeof(pthread_mutex_t) * data->arg.philo_total);
	if (init_mutex(data))
		return (data_error("Mutex initialization failed"));
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->arg.philo_total);
	if (!data->philo)
		return (data_error("Memory allocation failed for philos"));
	memset(data->philo, 0, sizeof(t_philo) * data->arg.philo_total);
	if (init_philo(data) != 0)
		return (data_error("Philo initialization failed"));
	return (0);
}
