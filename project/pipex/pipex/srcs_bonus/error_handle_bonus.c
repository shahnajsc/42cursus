/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:40:02 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/25 22:23:25 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_grid(void **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	close_fds(t_pipex *data)
{
	int	i;

	i = 0;
	if (!data->fd)
		return ;
	while (data->fd[i] != NULL)
	{
		if (data->fd[i][0] >= 0)
			close(data->fd[i][0]);
		if (data->fd[i][1] >= 0)
			close(data->fd[i][1]);
		free(data->fd[i]);
		i++;
	}
	free(data->fd);
	data->fd = NULL;
}

void	error_return(t_pipex *data, char *err_in, char *msg_err, int ret_value)
{
	ft_putstr_fd("pipex: ", 2);
	if (*err_in != '\0')
	{
		ft_putstr_fd(err_in, 2);
	}
	if (*msg_err == '\0' || !msg_err)
	{
		ft_putstr_fd(": ", 2);
		perror("");
	}
	else
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg_err, 2);
		ft_putstr_fd("\n", 2);
	}
	if (data->splitted_cmd)
		free_grid((void *)data->splitted_cmd);
	if (data->envp_paths != NULL)
		free(data->cmd_path);
	if (data->envp_paths)
		free_grid((void *)data->envp_paths); // need for mandatory also
	close_fds(data);
	exit(ret_value);
}
