/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:02:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/09 17:54:29 by shachowd         ###   ########.fr       */
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
		if (ft_uatoi(argv[i]) <= 0)
			arg_error("Invalid argument value(s)", argv[i]);
		i++;
	}
	data->philo_num = ft_uatoi(argv[1]); //make own atoi !!!!1
	data->die_time = ft_uatoi(argv[2]);
	data->eat_time = ft_uatoi(argv[3]);
	data->sleep_time = ft_uatoi(argv[4]);
	if (argc == 5)
		data->eat_must = 0;
	else
		data->eat_must = atoi(argv[5]);
	data->fork_num = atoi(argv[1]);
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
