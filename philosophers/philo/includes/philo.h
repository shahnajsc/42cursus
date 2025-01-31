/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:09:49 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/31 11:50:10 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// LIBRARIES //
# include <unistd.h>		//for write, usleep //
# include <stdio.h>			// for printf //
# include <stdlib.h>		// for mallo, free, NULL //
# include <string.h>		// for memset //
# include <pthread.h>		// for thread //
# include <sys/time.h>		// for gettimeofday //
# include <limits.h>		// for INT_MAX //

//.......Data Structure........//

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

typedef enum e_philostate
{
	ACTIVE,
	DIED,
	FULL,
}	t_philostat;

typedef enum e_simstate
{
	RUNNING,
	FINISH,
	FAILURE,
}	t_simstate;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	int				meal_eaten;
	long			last_meal;
	t_philostat		philo_state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_arg			arg;
	int				meals_full_philo;
	t_simstate		sim_state;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_print;
	pthread_mutex_t	data_update;
	t_philo			*philo;
}	t_data;

//.......Functions.......//

// data initialization
int				init_data(t_data *data, int argc, char **argv);

// simulation handle
t_simstate		simulation_initiate(t_data *data);
t_simstate		simulation_monitor(t_data *data);

// routine handle
int				thinking_philo(t_philo *philo);
int				eating_philo(t_philo *philo);
int				sleeping_philo(t_philo *philo);
int				philo_waiting(t_philo *philo, int wait_time);

// printing
void			routine_msg_print(t_philo *philo, char *str);
void			closing_msg_print(t_philo *philo);

// error handle
int				data_error(char *err_msg);
void			free_and_clean(t_data *data);

// utils
int				ft_uatoi(char *str);
long			get_time_ms(void);
t_philostat		check_philo_state(t_philo *philo);
t_simstate		check_sim_state(t_data *data);

#endif
