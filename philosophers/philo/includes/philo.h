/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:09:49 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/16 16:01:16 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// LIBRARIES //
# include <unistd.h>		// for write, usleep
# include <stdio.h>			// for printf
# include <stdlib.h>		// for mallo, free, NULL
# include <string.h>		// for memset
# include <pthread.h>		// for thread
# include <sys/time.h>		// for gettimeofday
# include <limits.h>		// for INT_MAX

// VARIABLE DECLARATIN //

typedef struct s_arg
{
	int		philo_total;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		meals_total;
	int		fork_total;
	long	start_time;
}	t_arg;

typedef enum s_state
{
	THINKING,
	EATING,
	SLEEPING,
	DIED,
}	t_state;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	int				meal_eaten;
	long				last_meal;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	t_state			state;
}	t_philo;

typedef struct s_data
{
	t_arg		arg;
	t_philo		*philo;
	pthread_t	*threads;
	pthread_mutex_t	plock;
}	t_data;

// FUNCTINS //

//error handle
int		data_error(char *err_msg);
int		free_clean_exit(t_data *data, int exit_code);

// utils
int		ft_uatoi(char *str);
long	get_star_time(void);

// data initialization
int		init_data(t_data *data, int argc, char ** argv);

// thread handle
int		thread_initiate(t_data *data);
//TEST// remove below functions (display function)
void	data_struct_print(t_data *data);
int		thread_test(t_data *data);


#endif
