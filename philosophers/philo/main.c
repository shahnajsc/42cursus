/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:02:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/14 15:14:27 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	free_and_clean(t_data *data)
{
	if (data && data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	// if (data->philo)
	// {
	// 	free(data->philo);
	// 	data->philo = NULL;
	// }
	if (data)
	{
		free(data);
		data = NULL;
	}
}

void	init_argument(t_arg *arg, int argc, char **argv)
{
	int		i;

	i = 1;
	printf("begin argument init\n");
	while (i < argc - 1)
	{
		printf("%d : %s\n", i, argv[i]);
		if (ft_uatoi(argv[i]) <= 0) //check is 0 is valid in some cases?
		{
			arg_error("Invalid argument value(s)", argv[i]);
			//free_and_clean(data);
		}
		// if (i == 5 && ft_uatoi(argv[i]) < 0) //check is 0 is valid in some cases?
		// 	arg_error("Invalid argument value(s)", argv[i]);
		i++;
	}
	printf("after check argument init\n");
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
}
void	init_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->arg.philo_total)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].last_meal  = 0;
		data->philo[i].meal_eaten = 0;
		data->philo[i].state = THINKING;
		i++;
	}
}
void	init_data(t_data *data, t_arg arg)
{
	printf("begin data init\n");
	memset(data, 0, sizeof(t_data));
	// data->arg = (t_arg *)malloc(sizeof(t_arg));
	// if (!data->arg)
	// {
	// 	printf("arg memory allovation failed\n");
	// }
	data->arg = arg;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->arg.philo_total);
	init_philo(data);
}

int	main(int argc, char **argv)
{
	t_arg arg;
	t_data *data;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	init_argument(&arg, argc, argv);
	printf("arg init done\n");
	data = (t_data *)malloc(sizeof(t_data));
	init_data(data,  arg);
	printf("data init done\n");
	data_struct_print(data);
	printf("\n");
	if (thread_test(data))
		printf("thread error\n");
	free_and_clean(data);
}
