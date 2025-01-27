/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:37:41 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/27 21:40:49 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_waiting(t_philo *philo, int wait_time)
{
	long	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < wait_time)
	{
		if (philo->philo_state  == DIED)
			return (1);
		if (philo->philo_state == FULL)
			return (1);
		usleep(100);
		// if (philo->philo_state == FULL)
		// 	return ;
		// if (philo->philo_state == DIED)
			//return ;
	}
	return (0);
}
int	thinking_philo(t_philo *philo)
{
	print_msg(philo, "is thinking");
	return (0);
}
int	lock_both_forks(t_philo *philo)
{
	if (philo->data->sim_state == FINISH || philo->data->sim_state == FAILURE)
		return (-1);
	pthread_mutex_lock(philo->left_fork);
	if (philo->philo_state != ACTIVE)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	print_msg(philo, "has taken left fork");
	// if (philo->data->arg.philo_total == 1)
	// {
	// 	philo_waiting(philo, philo->data->arg.die_time);
	// 	pthread_mutex_unlock(philo->left_fork);
	// 	return (-1);
	// }
	pthread_mutex_lock(philo->right_fork);
	if (philo->philo_state != ACTIVE)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (-1);
	}
	print_msg(philo, "has taken right fork");
	return (1);
}

int	eating_philo(t_philo *philo)
{
	if (lock_both_forks(philo) < 0)
		return (1);
	pthread_mutex_lock(&philo->data->data_update);
	philo->meal_eaten++;
	philo->last_meal = get_time_ms();
	// if (philo->data->arg.meals_total == philo->meal_eaten)
	// 	philo->state = FINISH;
	// else
	// 	philo->state = ACTIVE;
	pthread_mutex_unlock(&philo->data->data_update);
	print_msg(philo, "is eating");
	philo_waiting(philo, philo->data->arg.eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	sleeping_philo(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	philo_waiting(philo, philo->data->arg.sleep_time);
	return (0);
}
