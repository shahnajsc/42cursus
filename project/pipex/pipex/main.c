/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:19:25 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/03 17:32:36 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void data_init(t_pipex *data, int argc, char **argv, char **envp)
{
    data->argc = argc;
    data->argv = argv;
    data->envp = envp;
}

int main(int argc, char **argv, char **envp)
{
	int pip_status;
    t_pipex data;
	
	pip_status = 0;
    if (argc != 5)
	{
		printf("Invalid command format\nCorrect format: \"infile cmd1 cmd2 outfile\"\n"); // use ft_printf ***
		return (1);
	}
    data_init(&data, argc, argv, envp);
	pip_status = pipex(&data);
    //fd or pipe close?? ***
    return(pip_status);
}