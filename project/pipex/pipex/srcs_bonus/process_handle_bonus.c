/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:59:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/22 20:36:32 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pipe_init(int *fd)
{
	if (pipe(fd) == -1)
	{
		error_return("pipe()", "", 1);
	}
}

int	get_file_fd(int i, char *filename)
{
	int	file_fd;

	file_fd = 0;
	if (i == 0)
	{
		if (access(filename, F_OK) == 0 && access(filename, R_OK) == -1)
			error_return(filename, "", 1);
		file_fd = open(filename, O_RDONLY, 0444);
	}
	else
	{
		if (access(filename, F_OK) == 0 && access(filename, W_OK) == -1)
			error_return(filename, "", 1);
		file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (file_fd == -1)
		error_return(filename, "", 1);
	return (file_fd);
}

void	redirect_fd(int infd, int outfd)
{
	if (dup2(infd, STDIN_FILENO) == -1)
		error_return("dup2()", "", 1);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		error_return("dup2", "", 1);
	close(infd);
	close(outfd);
}

int	wait_process(pid_t pid)
{
	int	wstatus;

	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (1);
}
