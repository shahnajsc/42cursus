/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:18:35 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/15 13:43:13 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	data_struct_print(t_data *data)
{
	printf("\n");
	printf("  *****ARGUMENT VALUES*****\n");
	printf("\tphilo\t: %d\n", data->arg.philo_total);
	printf("\tdie\t: %d\n", data->arg.die_time);
	printf("\teat\t: %d\n", data->arg.eat_time);
	printf("\tsleep\t: %d\n", data->arg.sleep_time);
	printf("\teat_must: %d\n", data->arg.meals_total);
	printf("\tfork\t: %d\n", data->arg.fork_total);
	printf("\tstart time: %ld\n", data->arg.start_time);
	printf("\n");
}
