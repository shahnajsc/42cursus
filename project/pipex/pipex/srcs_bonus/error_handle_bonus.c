/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:59:09 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/22 20:36:15 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_grid(char **ptr)
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

void	close_fds(int *fd)
{
	if (fd)
	{
		close(fd[0]);
		close(fd[1]);
	}
}

void	error_return(char *err_in, char *msg_err, int ret_value)
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
	exit(ret_value);
}
