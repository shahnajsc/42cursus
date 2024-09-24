/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:05:36 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/24 15:12:49 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//required library
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

// Variable declaration

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		**fd;
	int		here_doc;
	char	**splitted_cmd;
	char	**envp_paths;
}	t_pipex;

// utils functions
char	**ft_split(char const *s, char c);
char	*skip_empty_str(char *cmd);
char	*quoted_word(char *cmd);
char	*normal_word(char *cmd);
int		check_white_spaces(char *str);

// command function
void	execve_init(t_pipex *data, char *cmd);
char	*get_command_path(t_pipex *data);
void	split_command(t_pipex *data, char *cmd);

// process functions
void	pipe_init(t_pipex *data);
int		get_file_fd(int i, t_pipex *data);
void	read_here_doc(t_pipex *data, int i);
void	redirect_fd(int infd, int outfd);
int		pipex(t_pipex *data);
int		wait_process(pid_t pid);

// error handle function
void	free_grid(void **ptr);
void	close_fds(t_pipex *data);
void	error_return(char *err_in, char *msg_err, int ret_value);

#endif
