/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:59:22 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/22 23:00:37 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	first_process(t_pipex *data, int infd, int outfd)
{
	close(data->fd[0]);
	redirect_fd(infd, outfd);
	close(data->fd[1]);
	execve_init(data, data->argv[2]);
}

static void	middle_process(t_pipex *data, int infd, int outfd)
{
	close(data->fd[1]);
	redirect_fd(infd, outfd);
	close(data->fd[0]);
	execve_init(data, data->argv[3]);
}

static void	last_process(t_pipex *data, int infd, int outfd)
{
	close(data->fd[1]);
	redirect_fd(infd, outfd);
	close(data->fd[0]);
	execve_init(data, data->argv[3]);
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
	else if ((i > data->argc - 2) && (i < data->argc - 1 ))
	{
		pipe_init(data->fd);
	}
	else
	{
		infd = data->fd[0];
		outfd = get_file_fd(1, data->argv[4]);
		last_process(data, infd, outfd);
	}
	close_fds(data->fd);
	close(infd);
	close(outfd);
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
			error_return("fork()", "", 1);
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
