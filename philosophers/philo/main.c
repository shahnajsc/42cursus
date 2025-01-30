/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:02:30 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/30 10:37:59 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (data_error("Invalid number of arguments"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (data_error("Memory allocation failed for data struct"));
	if (init_data(data, argc, argv))
	{
		free_and_clean(data);
		return (EXIT_FAILURE);
	}
	if (simulation_initiate(data) == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
