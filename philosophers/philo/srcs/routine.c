/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:23:18 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/17 19:19:25 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	print_msg(t_philo *philo, char *str)
// {
// 	pthread_mutex_lock(philo->msg_print);
// 	printf("%ld %d %s\n", get_star_time(), philo->philo_id, str);
// 	pthread_mutex_unlock(philo->msg_print);

// }
// void	philo_thinking(t_philo *philo)
// {
// 	print_msg(philo, "is thinking");
// }

// void	philo_eating(t_philo *philo)
// {

// }

// void	philo_sleeping(t_philo *philo)
// {

// }

// void	*routine(void *arg)
// {
// 	t_philo *philo;

// 	philo = (t_philo  *)arg;
// 	// printf("inside routin: philo %d\n", philo->philo_id);
// 	// if (philo->philo_id % 2 == 0)
// 	// {
// 	// 	printf("%ld philo %d is THINKING\n", get_star_time(), philo->philo_id);
// 	// }
// 	// else
// 	// 	printf("%ld philo %d is EATING\n", get_star_time(), philo->philo_id);
// 	return (NULL);
// }

void	*threadt_print(void *arg)
{
	t_philo *philo;

	philo = (t_philo  *)arg;
	printf("**** Phili %d *****\n", philo->philo_id);
	printf("Meal Eaten: %d\n", philo->meal_eaten);
	printf("Last Meal: %ld\n", philo->last_meal);
	printf("State: %u\n", philo->state);
	printf("Thread id: %lu\n", philo->thread_id);
	printf("Karnel Thread ID: %ld\n", pthread_self());
	printf("\n");
	// printf("inside routin: philo %d\n", philo->philo_id);
	// if (philo->philo_id % 2 == 0)
	// {
	// 	printf("%ld philo %d is THINKING\n", get_star_time(), philo->philo_id);
	// }
	// else
	// 	printf("%ld philo %d is EATING\n", get_star_time(), philo->philo_id);
	return (NULL);
}
