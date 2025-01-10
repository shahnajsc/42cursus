/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:09:49 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/10 16:25:25 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// libraries
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h> // do i need it??
# include <sys/time.h>
# include <pthread.h>

// variable declaration

typedef struct s_data
{
	int	philo_num;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_must;
	int	fork_num;
	time_t	start_time;
}	t_data;

typedef struct s_philo
{
	int	philo_id;
	pthread_t thread;
}	t_philo;

// *** Functions *** //

//error handle
void	arg_error(char *err_msg, char *argv);

// utils
int		ft_uatoi(char *str);
time_t	get_star_time(void);

//TEST// remove below functions (display function)
void	data_struct_print(t_data *data);
void	thread_test(t_data *data);


#endif
