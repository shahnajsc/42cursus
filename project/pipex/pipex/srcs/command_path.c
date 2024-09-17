/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:31:59 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/17 11:28:36 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static char	**get_envp_paths(t_pipex *data)
{
	char	**envp_path;
	int		i;

	if (!data->envp)
		return (NULL);
	i = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
		{
			envp_path = ft_split(data->envp[i] + 5, ':'); // need to update main ft_split it is not skipping :
			if (!envp_path)
				error_return("ft_split()", 1);
			return (envp_path);
		}
		i++;
	}
	return (NULL);
}

static char	*combine_path_cmd(char *envp_path, char *cmd)
{
	char	*combined_path;
	int		len_envp;
	int		len_cmd;

	len_envp = ft_strlen(envp_path);
	len_cmd = ft_strlen(cmd);
	combined_path = (char *)malloc(sizeof(char) * (len_envp + len_cmd + 2));
	if (!combined_path)
		return (NULL);
	ft_strlcpy(combined_path, envp_path, len_envp + 1);
	ft_strlcpy(combined_path + len_envp, "/", 2);
	ft_strlcpy(combined_path + len_envp + 1, cmd, len_cmd + 1);
	return (combined_path);
}

static char	*get_path_cmd(char **envp_paths, char *cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (envp_paths[i] != NULL)
	{
		final_path = combine_path_cmd(envp_paths[i], cmd);
		if (!final_path || access(final_path, F_OK) == 0) // !final_path
			return (final_path);
		free(final_path);
		i++;
	}
	return (NULL);
}

char	*get_command_path(t_pipex *data)
{
	char	*final_command;

	if (ft_strchr(data->splitted_cmd[0], '/'))
	{
		if (access(data->splitted_cmd[0], F_OK) == 0)
			return (data->splitted_cmd[0]);
		else
			error_return(data->splitted_cmd[0], 126); // error return 1 end error msg
	}
	data->envp_paths = get_envp_paths(data);
	final_command = get_path_cmd(data->envp_paths, data->splitted_cmd[0]);
	free_grid(data->envp_paths);
	free_grid(data->splitted_cmd);
	return (final_command);
}
