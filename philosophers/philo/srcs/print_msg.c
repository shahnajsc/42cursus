/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:16:31 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/31 14:59:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	routine_msg_print(t_philo *philo, char *str)
{
	if (check_sim_state(philo->data) == FAILURE
		|| check_sim_state(philo->data) == FINISH)
		return ;
	pthread_mutex_lock(&philo->data->msg_print);
	printf("%ld %d %s\n", (get_time_ms() - philo->data->arg.start_time),
		philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->msg_print);
}

void	closing_msg_print(t_philo *philo)
{
	if (check_sim_state(philo->data) == FAILURE)
	{
		pthread_mutex_lock(&philo->data->msg_print);
		printf("%ld %d %s\n", (get_time_ms() - philo->data->arg.start_time),
			philo->philo_id, "is dead");
		pthread_mutex_unlock(&philo->data->msg_print);
	}
	else
	{
		pthread_mutex_lock(&philo->data->msg_print);
		printf("All philosophers finished their maximum (%d) meals\n",
			philo->data->arg.meals_total);
		pthread_mutex_unlock(&philo->data->msg_print);
		return ;
	}
}
