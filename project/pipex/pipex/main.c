/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:53:46 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/19 22:02:39 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	data_init(t_pipex *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->envp_paths = NULL;
	data->splitted_cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_status;

	pipe_status = 0;
	if (argc != 5)
	{
		ft_putstr_fd("Correct command format: infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	data_init(&data, argc, argv, envp);
	pipe_status = pipex(&data);
    // free?? fd close??
	return (pipe_status);
}