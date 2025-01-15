/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:09:02 by shachowd          #+#    #+#             */
/*   Updated: 2025/01/15 13:48:34 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	data_error(char *err_msg)
{
	printf("Error\n%s ..\n", err_msg);
	return(1);
}
int	free_clean_exit(t_data *data, int exit_code)
{
	if (data && data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data && data->threads)
	{
		free(data->threads);
		data->threads = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
	return (exit_code);
}
