/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:53:50 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/03 21:00:44 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <pipex.h>
#include <unistd.h> //remove when libft added
#include <stdlib.h> //remove when libft added
#include <stdio.h> //remove when libft added

void pipe_init(int *fd)
{
    if (pipe(fd) == -1)
    {
        perror("pipe(): initiation failed\n");
        exit (1);
    }
}
int get_file_fd(int i, char *filen)
{
	int fd;

	fd = 0;

	if (i == 0)
	{
		if (access(filen, F_OK) == 0 && access(filen, R_OK) == -1)
			return (1);
		fd = open(filen, O_RDONLY, 0444 );
	}
	else 
	{
		if (access(filen, F_OK) == 0 && access(filen, W_OK) == -1)
			return (1);
		fd = open(filen, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (fd == -1)
		return (1);
	return (fd);
}

int redirect_fd(int infd, int outfd)
{
	if (dup2(infd, STDIN_FILENO) == -1)
		return (1);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		return (1);
	return(0);
}