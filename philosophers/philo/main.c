/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:02:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/23 10:48:38 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 5 && argc != 6)
		return (data_error("Invalid number of arguments"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (data_error("Memory allocation failed for data struct"));
	if (init_data(data, argc, argv))
	{
		free_clean_exit(data);
		return (EXIT_FAILURE);
	}
	if (simulation_initiate(data) == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
//	printf("data init done\n");
	//data_struct_print(data);
	// if (thread_test(data))
	// 	printf("thread error\n");
	// usleep(10000);
	// printf("time: %ld\n", get_time_ms()- data->arg.start_time);
