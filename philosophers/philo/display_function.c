/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:18:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/12/30 13:23:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	data_struct_print(t_data *data)
{
	printf("philo: %d\n", data->philo_num);
	printf("die: %d\n", data->die_time);
	printf("eat: %d\n", data->eat_time);
	printf("sleep: %d\n", data->sleep_time);
	printf("eat_must: %d\n", data->eat_must);
	printf("fork: %d\n", data->fork_num);
}
