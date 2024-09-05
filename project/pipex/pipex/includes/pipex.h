/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:54:55 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/05 10:57:27 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//required library
# include <fcntl.h>
# include <sys/wait.h>

// Variable declaration

typedef struct s_pipex
{
    int argc;
    char **argv;
    char **envp;
    int fd[2];
}   t_pipex;


// utils functions
char    **ft_split(char const *s, char c);
void    free_grid(char **ptr);

// command function
void execve_init(t_pipex *data, char *cmd);

// process functions
void    pipe_init(int *fd);
int     get_file_fd(int i, char *filen);
int     redirect_fd(int infd, int outfd);
int     pipex(t_pipex *data);

// error handle function

#endif