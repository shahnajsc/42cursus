/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:27:44 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/17 15:06:10 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s++, 1);
	}
}

void	free_grid(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	display_err_msg(char *msg_err)
{
	// ft_putstr_fd("pipex: ", 2);
	if (msg_err)
		ft_putstr_fd(msg_err, 2);
	perror("");
	// if (type_err == "pipe")
	//     ft_putstr_fd(" pipe()", 2);
	// if (type_err == "fork")
	//     ft_putstr_fd(" fork()", 2);
	// if (type_err == "dup2")
	//     ft_putstr_fd(" dup2()", 2);
	// if (type_err == "cmd")
	//     ft_putstr_fd(" command not found", 2);
	// if (type_err == "malloc")
	//     ft_putstr_fd(" malloc() failed", 2);
	// if (type_err == "open")
	//     ft_putstr_fd(" open() failed", 2);
	// if (type_err == "read")
	//     ft_putstr_fd(" read() failed", 2);
	// if (type_err == "access")
	//     ft_putstr_fd(" access denied", 2);
	// if (type_err == "execev")
	//     ft_putstr_fd(" No such file or directory", 2);
}

void	error_return(char *err_in, char *msg_err, int ret_value)
{
	// display err msg
	ft_putstr_fd("pipex:", 2);
	if (err_in)
		ft_putstr_fd(err_in, 2);
	if (*msg_err == '\0' || !msg_err)
		perror(" ");
	else
		ft_putstr_fd(msg_err, 2);
	exit(ret_value);
	//handle fd, array
	//exit
}
