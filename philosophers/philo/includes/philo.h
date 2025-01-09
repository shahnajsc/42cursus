/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:09:49 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/09 17:31:45 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// libraries
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h> // do i need it??
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
}	t_data;

// *** Functions *** //

//error handle
void	arg_error(char *err_msg, char *argv);

// utils
int		ft_uatoi(char *str);

//TEST// remove below functions (display function)
void	data_struct_print(t_data *data);
void	thread_test(t_data *data);


#endif
