/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:52:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/17 16:25:59 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

static void	first_process(t_pipex *data, int infd, int outfd)
{
	close(data->fd[0]);
	redirect_fd(infd, outfd);
	close(data->fd[1]);
	execve_init(data, data->argv[2]);
	//error handle
}

static void	last_process(t_pipex *data, int infd, int outfd)
{
	close(data->fd[1]);
	redirect_fd(infd, outfd);
	close(data->fd[0]);
	execve_init(data, data->argv[4]);
	// error handle
}

static void	handle_proces(t_pipex *data, int i)
{
	int	infd;
	int	outfd;

	if (i == 0)
	{
		infd = get_file_fd(0, data->argv[1]);
		outfd = data->fd[1];
		first_process(data, infd, outfd);
	}
	else
	{
		infd = data->fd[0];
		outfd = get_file_fd(1, data->argv[4]);
		last_process(data, infd, outfd);
	}
	close_fds(data->fd);
	//close infd amd outfd???
	exit(EXIT_SUCCESS);
}

int	pipex(t_pipex *data)
{
	pid_t	p_id[2];
	int		pipe_status;
	int		i;

	pipe_init(data->fd);
	i = 0;
	while (i < data->argc - 3)
	{
		p_id[i] = fork();
		if (p_id[i] == -1)
			error_return(NULL, "", 1); // set error id for 'fork' error
		if (p_id[i] == 0)
			handle_proces(data, i);
		i++;
	}
	close_fds(data->fd);
	i = 0;
	while (i < 2)
	{
		pipe_status = wait_process(p_id[i]);
		i++;
	}
	return (pipe_status);
}
