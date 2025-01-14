/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:18:35 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/14 14:15:04 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	data_struct_print(t_data *data)
{
	printf("philo: %d\n", data->arg.philo_total);
	printf("die: %d\n", data->arg.die_time);
	printf("eat: %d\n", data->arg.eat_time);
	printf("sleep: %d\n", data->arg.sleep_time);
	printf("eat_must: %d\n", data->arg.meals_total);
	printf("fork: %d\n", data->arg.fork_total);
}
