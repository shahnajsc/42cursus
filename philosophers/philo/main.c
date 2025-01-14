/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:02:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/13 17:07:31 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("%d : %s\n", i, argv[i]);
		if (ft_uatoi(argv[i]) <= 0) //check is 0 is valid in some cases?
			arg_error("Invalid argument value(s)", argv[i]);
		// if (i == 5 && ft_uatoi(argv[i]) < 0) //check is 0 is valid in some cases?
		// 	arg_error("Invalid argument value(s)", argv[i]);
		i++;
	}
	data->philo_total = ft_uatoi(argv[1]); //make own atoi !!!!1
	data->die_time = ft_uatoi(argv[2]);
	data->eat_time = ft_uatoi(argv[3]);
	data->sleep_time = ft_uatoi(argv[4]);
	if (argc == 5)
		data->meals_total = 0;
	else
		data->meals_total = atoi(argv[5]);
	data->fork_total = atoi(argv[1]);
	data->start_time = get_star_time();
	data->philo = malloc(sizeof(t_philo) * 1);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	init_data(&data, argc, argv);
	data_struct_print(&data);
	printf("\n");
	thread_test(&data);
}
