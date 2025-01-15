/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:53:22 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/15 15:12:35 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


static int	init_argument(t_arg *arg, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_uatoi(argv[i]) <= 0) //check is 0 is valid in some cases?
			return (1);
		i++;
	}
	arg->philo_total = ft_uatoi(argv[1]); //make own atoi !!!!1
	arg->die_time = ft_uatoi(argv[2]);
	arg->eat_time = ft_uatoi(argv[3]);
	arg->sleep_time = ft_uatoi(argv[4]);
	if (argc == 5)
		arg->meals_total = 0;
	else
		arg->meals_total = atoi(argv[5]);
	arg->fork_total = atoi(argv[1]);
	arg->start_time = get_star_time();
	return (0);
}
static int	init_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].last_meal  = data->arg.start_time;
		data->philo[i].meal_eaten = 0;
		data->philo[i].state = THINKING;
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int argc, char ** argv)
{
	memset(data, 0, sizeof(t_data));
	if (init_argument(&data->arg, argc, argv))
		return (data_error("Invalid argument value"));
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->arg.philo_total);
	if (!data->threads)
		return (data_error("Memory allocation failed for threads"));
	memset(data->threads, 0, sizeof(pthread_t) * data->arg.philo_total);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->arg.philo_total);
	if (!data->philo)
		return (data_error("Memory allocation failed for philos"));
	memset(data->philo, 0, sizeof(t_philo) * data->arg.philo_total);
	if (init_philo(data))
		return (data_error("Philo initialization failed"));
	if (pthread_mutex_init(&data->plock, NULL))
		return (data_error("Mutex initializatin failed"));
	return (0);
}
//	printf("after check argument init\n");
