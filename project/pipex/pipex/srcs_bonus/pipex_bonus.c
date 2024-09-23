/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:59:22 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/23 21:42:02 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	first_process(t_pipex *data, int i)
{
	int infd;
	int outfd;

	// if (data->here_doc)
	// {
	// 	read_here_doc(data, i);
	// 	infd = data->fd[i][0];
	// }
	// else
	infd = get_file_fd(0, data);
	outfd = data->fd[i][1];
	close(data->fd[i][0]);
	redirect_fd(infd, outfd);
	close_fds(data);
	execve_init(data, data->argv[i + 2 + data->here_doc]);
}

static void	middle_process(t_pipex *data, int i)
{
	int infd;
	int outfd;

	infd = data->fd[i-1][0];
	outfd = data->fd[i][1];
	close(data->fd[i][0]);
	redirect_fd(infd, outfd);
	close_fds(data);
	execve_init(data, data->argv[i + 2 + data->here_doc]);
}

static void	last_process(t_pipex *data, int i)
{
	int infd;
	int outfd;

	infd = data->fd[i - 1][0];
	outfd = get_file_fd(1, data);
	close(data->fd[i][1]);
	redirect_fd(infd, outfd);
	close_fds(data);
	// close(infd); // now or later??
	// close(outfd);
	execve_init(data, data->argv[i + 2 + data->here_doc]);
}

static void	handle_proces(t_pipex *data, int i)
{
	if (i == 0)
	{
		first_process(data, i);
	}
	else if (i == (data->argc - 3 - data->here_doc - 1))
	{
		last_process(data, i);
	}
	else
	{
		middle_process(data, i);
	}
	close_fds(data);
	exit(EXIT_SUCCESS);
}

int	pipex(t_pipex *data)
{
	pid_t	p_id[data->argc - 3 - data->here_doc];
	int		pipe_status;
	int		i;

	pipe_init(data);
	i = 0;
	while (i < data->argc - 3 - data->here_doc)
	{
		p_id[i] = fork();
		if (p_id[i] == -1)
			error_return("fork()", "", 1);
		if (p_id[i] == 0)
			handle_proces(data, i);
		i++;
	}
	close_fds(data); // need to free
	i = -1;
	while (++i < data->argc - 3 - data->here_doc)
	{
		pipe_status = wait_process(p_id[i]);
	}
	return (pipe_status);
}
