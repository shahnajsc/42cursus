/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:40:55 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/26 16:43:22 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pipe_init(t_pipex *data)
{
	int	i;

	i = 0;
	while (data->fd && i < (data->argc - 3 - data->here_doc))
	{
		if (pipe(data->fd[i]) == -1)
		{
			close_fds(data);
			error_return(data, "pipe()", "", 1);
		}
		i++;
	}
}

int	get_file_fd(t_pipex *data, int i, char *filename)
{
	int	file_fd;

	file_fd = 0;
	if (i == 0)
	{
		filename = data->argv[1];
		if (access(filename, F_OK) == 0 && access(filename, R_OK) == -1)
			error_return(data, filename, "", 1);
		file_fd = open(filename, O_RDONLY, 0444);
	}
	else
	{
		filename = data->argv[data->argc - 1];
		if (access(filename, F_OK) == 0 && access(filename, W_OK) == -1)
			error_return(data, filename, "", 1);
		if (data->here_doc)
			file_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (file_fd == -1)
		error_return(data, filename, "", 1);
	return (file_fd);
}

void	read_here_doc(t_pipex *data)
{
	char	*line_text;
	int		hd_fd;

	hd_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (hd_fd == 1)
		error_return(data, "open()", "", 1);
	while (1)
	{
		line_text = get_next_line(0);
		if (!line_text)
			break ;
		if (ft_strncmp(line_text, data->argv[2], ft_strlen(data->argv[2])) == 0)
			break ;
		write(hd_fd, line_text, ft_strlen(line_text));
		free(line_text);
	}
	close(hd_fd);
	if (!line_text)
		error_return(data, "get_next_line()", "", 1);
	free(line_text);
}

void	redirect_fd(t_pipex *data, int infd, int outfd)
{
	if (dup2(infd, STDIN_FILENO) == -1)
		error_return(data, "dup2()", "", 1);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		error_return(data, "dup2", "", 1);
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
