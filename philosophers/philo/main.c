/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:02:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/20 15:39:29 by shachowd         ###   ########.fr       */
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
		free_clean_exit(data, 1);
	//data_struct_print(data);
	printf("time: %ld\n", get_time_ms()- data->arg.start_time);
	if (simulation_initiate(data))
		free_clean_exit(data, 1);
	// if (thread_test(data))
	// 	printf("thread error\n");
	free_clean_exit(data, 0);
}
//	printf("data init done\n");
