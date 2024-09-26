/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:54:55 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/26 08:55:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//required library
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

// Variable declaration

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		fd[2];
	char	**sp_cmd;
	char	**envp_paths;
	char	*cmd_path;
}	t_pipex;

// utils functions
void	free_grid(char **ptr);
char	*skip_empty_str(char *cmd);
char	*quoted_word(char *cmd);
char	*normal_word(char *cmd);
int		check_white_spaces(char *str);

// command function
void	execve_init(t_pipex *data, char *cmd);
char	*get_command_path(t_pipex *data);
void	split_command(t_pipex *data, char *cmd);

// process functions
void	pipe_init(t_pipex *data, int *fd);
int		get_file_fd(t_pipex *data, int i, char *filen);
void	redirect_fd(t_pipex *data, int infd, int outfd);
int		pipex(t_pipex *data);
int		wait_process(pid_t pid);

// error handle function
void	free_grid(char **ptr);
void	close_fds(int *fd);
void	error_return(t_pipex *data, char *err_in, char *msg_err, int ret_value);

#endif
