/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:54:04 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/26 16:45:47 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex_bonus.h"

static void	data_init(t_pipex *data, int argc, char **argv, char **envp, int i)
{
	int	**fds;

	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	if (argc > 5 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		data->here_doc = 1;
	else
		data->here_doc = 0;
	fds = (int **)malloc((data->argc - 3 - data->here_doc + 1) * sizeof(int *));
	if (!fds)
		error_return(data, "", "malloc()", 1);
	while (fds && ++i < (data->argc - 3 - data->here_doc))
	{
		fds[i] = (int *)malloc(2 * sizeof(int));
		if (!fds[i])
		{
			free_grid((void **)fds);
			error_return(data, "pipe()", "", 1);
		}
	}
	fds[i] = NULL;
	data->fd = fds;
	data->envp_paths = NULL;
	data->sp_cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		pipe_status;

	pipe_status = 0;
	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6))
	{
		ft_putstr_fd("Correct command format: infile cmd1..cmd(n) outfile\n", 2);
		exit(1);
	}
	data_init(&data, argc, argv, envp, -1);
	pipe_status = pipex(&data);
	clean_at_exit(&data);
	exit(pipe_status);
}
