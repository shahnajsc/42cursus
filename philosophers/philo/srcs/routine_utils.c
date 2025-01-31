/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:37:41 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/31 15:29:16 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_waiting(t_philo *philo, int wait_time)
{
	long	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < wait_time)
	{
		if (check_philo_state(philo) == DIED)
			return (1);
		usleep(100);
	}
	return (0);
}

int	thinking_philo(t_philo *philo)
{
	routine_msg_print(philo, "is thinking");
	return (0);
}

int	sleeping_philo(t_philo *philo)
{
	routine_msg_print(philo, "is sleeping");
	if (philo_waiting(philo, philo->data->arg.sleep_time))
		return (1);
	return (0);
}

static int	lock_both_forks(t_philo *philo)
{
	if (check_sim_state(philo->data) == FINISH
		|| check_sim_state(philo->data) == FAILURE)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	if (check_philo_state(philo) != ACTIVE)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	routine_msg_print(philo, "has taken left fork");
	if (philo->data->arg.philo_total == 1)
	{
		philo_waiting(philo, philo->data->arg.die_time);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (check_philo_state(philo) != ACTIVE)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	routine_msg_print(philo, "has taken right fork");
	return (0);
}

int	eating_philo(t_philo *philo)
{
	if (lock_both_forks(philo))
		return (1);
	routine_msg_print(philo, "is eating");
	if (philo_waiting(philo, philo->data->arg.eat_time))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->data->data_update);
	philo->meal_eaten++;
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->data->data_update);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}
