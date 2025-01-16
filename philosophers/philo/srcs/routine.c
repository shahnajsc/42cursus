/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:18 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/16 16:27:29 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_msg(t_philo *philo, char *str)
{
	
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo  *)arg;
	// printf("inside routin: philo %d\n", philo->philo_id);
	// if (philo->philo_id % 2 == 0)
	// {
	// 	printf("%ld philo %d is THINKING\n", get_star_time(), philo->philo_id);
	// }
	// else
	// 	printf("%ld philo %d is EATING\n", get_star_time(), philo->philo_id);
	return (NULL);
}
