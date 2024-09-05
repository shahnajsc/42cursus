/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:52:54 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/03 19:48:46 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void first_process(t_pipex *data, int infd, int outfd)
{
		close(data->fd[0]);
		redirect_fd(infd, outfd);
		execve_init(data, data->argv[2]);
		//error handle
}

//int middle_process()

void last_process(t_pipex *data, int infd, int outfd)
{
		close(data->fd[1]);
		redirect_fd(infd, outfd);
		execve_init(data, data->argv[4]);
		// error handle
}

void handle_proces(t_pipex *data, int i)
{
	int infd;
	int outfd;
	
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
	//exit(EXIT_SUCCESS);
}

int pipex(t_pipex *data)
{
	
	//int fd[2];
	pid_t p_id[2];
	int pip_stat;
	int i;

	pipe_init(data->fd);
	i = 0;
	while(i < data->argc - 3)
	{
		p_id[i] = fork();
		if (p_id[i] == -1)
			return (1); // set error id for 'fork' error
		if (p_id[i] == 0)
			handle_proces(data, i);
		i++;
	}
	i = 0;
	while((++i) < 2)
	{
		pip_stat = 0; //pid_wait(p_id[i]);
		i++;
	}
	return(pip_stat);
}
